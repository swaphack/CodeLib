#include "WebServer.h"

using namespace web;


//////////////////////////////////////////////////////////////////////////
WebServer::WebServer(sys::Server* server)
{
	ASSERT(_server != nullptr);

	_server = server;
	_session = new Session();
}

WebServer::~WebServer()
{
	SAFE_DELETE(_session);
	SAFE_DELETE(_server);
}

void WebServer::addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	HttpRecvHandler singleHandler;
	singleHandler.first = target;
	singleHandler.second = handler;

	_recvHandlers.push_back(singleHandler);
}

void WebServer::removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	std::vector<HttpRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		if (it->first == target && it->second ==  handler)
		{
			_recvHandlers.erase(it);
			break;
		}
		it++;
	}
}

void WebServer::postResponse(sys::HttpResponse* response)
{
	sys::NetData* data = this->createResponseData(response);
	if (data == nullptr)
	{
		return;
	}

	HttpClient* client = getSession()->getHttpClient(response->getSessionID());
	if (client == nullptr)
	{
		return;
	}

	_server->sendMessage(client->clientID, data);
}

void WebServer::postBroadcast(sys::HttpResponse* response)
{
	sys::NetData* data = this->createResponseData(response);
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
	sys::HttpRequest* request = this->createHttpRequest(id, dataQueue);
	if (request == nullptr)
	{
		return;
	}
	if (request->getDocument()->getStreamSize() == 0)
	{
		return;
	}

	HttpClient client;
	client.sessionID = request->getSessionID();
	client.clientID = id;

	this->getSession()->addHttpClient(client.sessionID.c_str(), client);

	this->onRecvHander(request);

	delete request;
}

Session* WebServer::getSession()
{
	return _session;
}

void WebServer::onRecvHander(sys::HttpRequest* data)
{
	std::vector<HttpRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		(it->first->*it->second)(data->getSessionID(), data);
		it++;
	}
}

sys::HttpRequest* WebServer::createHttpRequest(int id, sys::DataQueue& dataQueue)
{
	sys::NetData* netData = dataQueue.top();
	if (netData == nullptr)
	{
		return nullptr;
	}

	sys::HttpReqDocument* pDoc = new sys::HttpReqDocument();
	if (!pDoc->parseRequest(netData->getCursorPtr(), netData->getRemainSize()))
	{
		delete pDoc;
		return nullptr;
	}

	int parseLen = pDoc->getStreamSize();

	if (parseLen + netData->pos > netData->size)
	{
		delete pDoc;
		return nullptr;
	}

	std::string sessionID;
	sys::BitConvert::getNumberString(id, sessionID);

	sys::HttpRequest* pReq = new sys::HttpRequest();
	pReq->setDocument(pDoc);
	pReq->setSessionID(sessionID.c_str());

	if (parseLen + netData->pos == netData->size)
	{
		dataQueue.pop();
		delete netData;
	}
	else
	{
		if (dataQueue.count() > 1)
		{// 保留到下一条数据
			dataQueue.pop();
			sys::NetData* nextData = dataQueue.top();
			nextData->insert(netData->getCursorPtr() + parseLen, netData->size - parseLen);
			delete netData;
		}
	}

	return pReq;

	/*

	int offset = 0;
	sys::HttpRequest* request = new sys::HttpRequest();
	offset = request->tryParseMessage(netData->data + netData->pos, netData->size);
	// 需判断接收数据是个完整的http包
	if (request->isFullCommand())
	{
		request->setSessionID(getCString("%d", id));
		request->setMessage(netData->data + netData->pos, offset);
	}
	else
	{
		delete request;
		request = nullptr;
	}

	if (offset > 0)
	{
		if (offset == netData->size)
		{// 数据解析完毕
			if (request->isFullCommand())
			{// 完整的包
				dataQueue.pop();
				delete netData;
			}
			else
			{
				if (dataQueue.count() > 1)
				{// 保留到下一条数据
					dataQueue.pop();
					sys::NetData* nextData = dataQueue.top();
					nextData->insert(netData->getCursorPtr(), netData->size - offset);
					delete netData;
				}
				// 保留当前
			}
		}
		else
		{
			netData->pos = offset;
		}
	}
	else
	{
		if (dataQueue.count() > 1)
		{// 保留到下一条数据
			dataQueue.pop();
			sys::NetData* nextData = dataQueue.top();
			nextData->insert(netData->getCursorPtr(), netData->size - offset);
			delete netData;
		}
		// 保留当前
	}
	*/
}

sys::NetData* WebServer::createResponseData(sys::HttpResponse* response)
{
	if (response == nullptr)
	{
		return nullptr;
	}

	return new sys::NetData(response->getMessage(), response->getMessageSize());
}