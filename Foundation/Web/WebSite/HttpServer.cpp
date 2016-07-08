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
	singleHandler.target = target;
	singleHandler.hander = handler;

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
		if (it->equals(target, handler))
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
		it->hand(data->getSessionID(), data);
		it++;
	}
}

HttpRequest* HttpServer::createHttpRequest(int id, sys::DataQueue& dataQueue)
{
	sys::NetData* data = dataQueue.top();
	if (data == nullptr)
	{
		return nullptr;
	}

	sys::String session;
	session.make("%d", id);

	HttpRequest* request = new HttpRequest();
	request->setMessage(data->data, data->size);
	request->setSessionID(session.getString());

	sys::String cookie = request->getHeader(HttpRequestField::COOKIE);

	dataQueue.pop();
	delete data;

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