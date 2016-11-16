#include "WebApplication.h"

using namespace web;

static WebApplication* s_pWebApplication = nullptr;
//////////////////////////////////////////////////////////////////////////
WebApplication::WebApplication( const char* ip, int port, int maxWaitCount )
:_ip(ip)
,_port(port)
,_maxWaitCount(maxWaitCount)
,_server(nullptr)
{
	ASSERT(s_pWebApplication == nullptr);

	s_pWebApplication = this;

	sys::Socket::InitSockModule();

	this->init();
}

WebApplication::~WebApplication()
{
	this->disponse();

	sys::Socket::ReleaseSockModule();

	s_pWebApplication = nullptr;
}

WebApplication* WebApplication::getInstance()
{
	return s_pWebApplication;
}

WebServer* WebApplication::getServer()
{
	return _server;
}

WebClient* WebApplication::getClient()
{
	return _client;
}

sys::ResourceMgr* WebApplication::getResourceMgr()
{
	return _resource;
}

HttpActivityListener* WebApplication::getHttpListener()
{
	return static_cast<HttpActivityListener*>(_listenerPool->getListener(_httpListenerID));
}

PacketActivityListener* WebApplication::getPacketListener()
{
	return static_cast<PacketActivityListener*>(_listenerPool->getListener(_packetListenerID));
}

void WebApplication::postResponse(const char* sessionID, sys::NetData* data)
{
	if (sessionID == nullptr || data == nullptr)
	{
		return;
	}

	ClientSession* session = _session->getSession(sessionID);
	if (session == nullptr)
	{
		return;
	}

	if (session->tag == EST_SERVER)
	{
		_server->postResponse(session->clientID, data);
	}
	else if (session->tag == EST_CLIENT)
	{
		sys::Client* client = _client->getClient(session->clientID);
		if (client)
		{
			client->sendMessage(data);
		}
	}
}

void WebApplication::postResponse(int clientID, sys::NetData* data)
{
	if (data == nullptr)
	{
		return;
	}

	ClientSession* session = _session->getSession(clientID);
	if (session)
	{
		if (session->tag == EST_SERVER)
		{
			_server->postResponse(session->clientID, data);
			return;
		}
	}	
	sys::Client* client = _client->getClient(clientID);
	if (client)
	{
		client->sendMessage(data);
	}
}

void WebApplication::postBroadcast(sys::NetData* data)
{
	if (data == nullptr)
	{
		return;
	}

	_server->postBroadcast(data);
}

int WebApplication::getSocketID(const char* sessionID)
{
	if (sessionID == nullptr)
	{
		return -1;
	}

	ClientSession* client = _session->getSession(sessionID);
	if (client == nullptr)
	{
		return -1;
	}

	return client->clientID;
}

void WebApplication::init()
{
	_resource = new sys::ResourceMgr();

	_listenerPool = new ListenerPool();
	_httpListenerID = _listenerPool->addListener(new HttpActivityListener());
	_packetListenerID = _listenerPool->addListener(new PacketActivityListener());
	
	
	_server = new WebServer();
	_server->setRecvHandler(this, static_cast<sys::SERVER_RECV_HANDLER>(&WebApplication::parseReceiveServerData));
	_server->setCloseHandler(this, static_cast<sys::CLIENT_CLOSE_HANDLER>(&WebApplication::closeClient));

	_server->createServer(_ip.c_str(), _port, _maxWaitCount);

	_client = new WebClient();
	_client->setRecvHandler(this, static_cast<sys::CLIENT_RECV_HANDLER>(&WebApplication::parseReceiveClientData));
	_client->setCloseHandler(this, static_cast<sys::CLIENT_CLOSE_HANDLER>(&WebApplication::closeClient));

	_session = new Sessions();
}

void WebApplication::update()
{
	if (_server)
	{
		_server->update();
	}

	if (_client)
	{
		_client->update();
	}

	checkAutoRealsePool();
}

void WebApplication::dispose()
{
	SAFE_DELETE(_server);
	SAFE_DELETE(_resource);
	SAFE_DELETE(_client);
	SAFE_DELETE(_listenerPool);
	SAFE_DELETE(_session);
}

void WebApplication::parseReceiveServerData(int id, sys::DataQueue& dataQueue)
{
	parseReceiveData(id, dataQueue, EST_SERVER);
}

void WebApplication::parseReceiveClientData(int id, sys::DataQueue& dataQueue)
{
	parseReceiveData(id, dataQueue, EST_CLIENT);
}

void WebApplication::parseReceiveData(int id, sys::DataQueue& dataQueue, int tag)
{
	std::string sessionID;
	sys::BitConvert::getNumberString(id, sessionID);
	
	// 服务端session
	if (!_session->getSession(sessionID.c_str()))
	{
		ClientSession client;
		client.sessionID = sessionID;
		client.clientID = id;
		client.tag = tag;

		_session->addSession(client.sessionID.c_str(), client);
	}
	
	if (_listenerPool->onDispatch(sessionID.c_str(), dataQueue))
	{
	}
	else
	{ // 错误数据
	}
}

void WebApplication::closeClient(int id)
{
	// 服务端session
	_session->removeClient(id);
}