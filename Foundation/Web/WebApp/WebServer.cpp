#include "WebServer.h"

using namespace web;

WebServer::WebServer(sys::Server* server)
{
	ASSERT(_server != nullptr);

	_server = server;
	_session = new Sessions();

	_httpListener = new HttpActivityListener();
	_packetListener = new PacketActivityListener();
}

WebServer::~WebServer()
{
	SAFE_DELETE(_session);
	SAFE_DELETE(_server);
	SAFE_DELETE(_httpListener);
	SAFE_DELETE(_packetListener);
}

void WebServer::postResponse(const char* sessionID, sys::NetData* data)
{
	if (sessionID == nullptr || data == nullptr)
	{
		return;
	}

	ClientSession* client = getSession()->getHttpClient(sessionID);
	if (client == nullptr)
	{
		return;
	}

	_server->sendMessage(client->clientID, data);
}

void WebServer::postBroadcast(sys::NetData* data)
{
	if (data == nullptr)
	{
		return;
	}

	_server->sendBroadcast(data);
}

void WebServer::update()
{
	_server->update();
}

void WebServer::onParseData(int id, sys::DataQueue& dataQueue)
{	
	std::string sessionID;
	sys::BitConvert::getNumberString(id, sessionID);

	ClientSession client;
	client.sessionID = sessionID;
	client.clientID = id;

	this->getSession()->addHttpClient(client.sessionID.c_str(), client);

	bool bRet = false;
	int size = 0;
	if (!bRet && this->getHttpListener())
	{
		bRet = this->getHttpListener()->onDispatch(sessionID.c_str(), dataQueue, size);
	}

	if (!bRet && this->getPacketListener())
	{
		bRet = this->getPacketListener()->onDispatch(sessionID.c_str(), dataQueue, size);
	}

	if (bRet)
	{
		sys::NetData* netData = dataQueue.top();

		int cursor = netData->pos + size;
		if (cursor == netData->size)
		{// 刚好解析完毕
			dataQueue.pop();
			delete netData;
		}
		else
		{
			if (dataQueue.count() > 1)
			{// 保留到下一条数据
				dataQueue.pop();
				sys::NetData* nextData = dataQueue.top();
				nextData->insert(netData->getCursorPtr() + size, netData->size - cursor);
				delete netData;
			}
			else
			{
				netData->pos += size;
			}
		}
	}
}

Sessions* WebServer::getSession()
{
	return _session;
}

HttpActivityListener* WebServer::getHttpListener()
{
	return _httpListener;
}

PacketActivityListener* WebServer::getPacketListener()
{
	return _packetListener;
}
