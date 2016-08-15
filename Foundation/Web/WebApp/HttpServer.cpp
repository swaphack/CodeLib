#include "HttpServer.h"

using namespace web;


//////////////////////////////////////////////////////////////////////////
HttpServer::HttpServer(sys::Server* server)
{
	ASSERT(_server != nullptr);

	_server = server;
	_session = new Session();
}

HttpServer::~HttpServer()
{
	SAFE_DELETE(_session);
	SAFE_DELETE(_server);
}

void HttpServer::addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
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

void HttpServer::removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
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

void HttpServer::postResponse(HttpResponse* response)
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

void HttpServer::postBroadcast(HttpResponse* response)
{
	sys::NetData* data = this->createResponseData(response);
	if (data == nullptr)
	{
		return;
	}

	_server->sendBroadcast(data);
}

void HttpServer::update()
{
	_server->update();
}

void HttpServer::onParseData(int id, sys::DataQueue& dataQueue)
{
	HttpRequest* request = this->createHttpRequest(id, dataQueue);
	if (request == nullptr || request->empty())
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

Session* HttpServer::getSession()
{
	return _session;
}

void HttpServer::onRecvHander(HttpRequest* data)
{
	std::vector<HttpRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		(it->first->*it->second)(data->getSessionID(), data);
		it++;
	}
}

HttpRequest* HttpServer::createHttpRequest(int id, sys::DataQueue& dataQueue)
{
	sys::NetData* netData = dataQueue.top();
	if (netData == nullptr)
	{
		return nullptr;
	}
	
	int offset = 0;
	HttpRequest* request = new HttpRequest();
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

	return request;
}

sys::NetData* HttpServer::createResponseData(HttpResponse* response)
{
	if (response == nullptr)
	{
		return nullptr;
	}

	return new sys::NetData(response->getMessage(), response->size());
}