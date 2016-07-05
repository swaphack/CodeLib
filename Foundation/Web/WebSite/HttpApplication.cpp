#include "HttpApplication.h"

using namespace web;

static HttpApplication* s_pHttpApplication = nullptr;

//////////////////////////////////////////////////////////////////////////
HttpApplication::HttpApplication(const char* ip, int port, int maxWaitCount /*= WAIT_LISTEN_COUNT*/)
:WebApplication(ip, port, maxWaitCount)
{
	_session = new Session();

	s_pHttpApplication = this;
}

HttpApplication::~HttpApplication()
{
	SAFE_DELETE(_session);
}

HttpApplication* HttpApplication::getInstance()
{
	return s_pHttpApplication;
}

void HttpApplication::addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
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

void HttpApplication::removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler)
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

void HttpApplication::postResponse(HttpResponse* response)
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

void HttpApplication::postBroadcast(HttpResponse* response)
{
	sys::NetData* data = this->createResponseData(response);
	if (data == nullptr)
	{
		return;
	}

	_server->sendBroadcast(data);
}

Session* HttpApplication::getSession()
{
	return _session;
}

void HttpApplication::onRecvHander(HttpRequest* data)
{
	std::vector<HttpRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		it->hand(data->getSessionID(), data);
		it++;
	}
}

HttpRequest* HttpApplication::createHttpRequest(int id, sys::DataQueue& dataQueue)
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

	sys::String cookie = request->getHeadParam(HttpRequestField::COOKIE);

	dataQueue.pop();
	delete data;

	return request;
}

sys::NetData* HttpApplication::createResponseData(HttpResponse* response)
{
	if (response == nullptr)
	{
		return nullptr;
	}

	return new sys::NetData(response->getMessage(), response->size());
}

void HttpApplication::onParseData(int id, sys::DataQueue& dataQueue)
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
