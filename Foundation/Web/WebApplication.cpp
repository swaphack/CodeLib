#include "WebApplication.h"

using namespace web;

WebApplication* WebApplication::s_pWebApplication = nullptr;

WebApplication::WebApplication( const char* ip, int port, int maxWaitCount )
:_ip(ip)
,_port(port)
,_maxWaitCount(maxWaitCount)
,_server(nullptr)
{
	s_pWebApplication = this;

	sys::Socket::InitSockModule();
}

WebApplication::~WebApplication()
{
	s_pWebApplication = nullptr;

	sys::Socket::ReleaseSockModule();
}

void WebApplication::init()
{
	this->initNet();
}

void WebApplication::update()
{
	if (_server)
	{
		_server->update();
	}
}

void WebApplication::dispose()
{
	this->disposeNet();
}

void WebApplication::initNet()
{
	_server = new sys::Server(_ip.c_str(), _port, _maxWaitCount);
	_server->setRecvHandler(this, static_cast<sys::SERVER_RECV_HANDLER>(&WebApplication::parserData));
}

void WebApplication::disposeNet()
{
	SAFE_DELETE(_server);
}

void WebApplication::addRecvHandler( sys::Object* target, WEB_RECV_HANDLER handler )
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	WebRecvHandler singleHandler;
	singleHandler.target = target;
	singleHandler.hander = handler;

	_recvHandlers.push_back(singleHandler);
}

void WebApplication::removeRecvHandler(sys::Object* target, WEB_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	std::vector<WebRecvHandler>::iterator it = _recvHandlers.begin();
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

void WebApplication::postResponse( int id, HttpResponse* response )
{
	sys::NetData* data = this->createResponseData(response);
	if (data == nullptr)
	{
		return;
	}

	_server->sendMessage(id, data);
}

void WebApplication::parserData( int id, sys::DataQueue& dataQueue )
{
	HttpRequest* request = this->createHttpRequest(dataQueue);
	if (request == nullptr || request->empty())
	{
		return;
	}

	request->setSrcID(id);
	this->onRecvHander(id, request);

	delete request;
}

void WebApplication::onRecvHander( int id, HttpRequest* data )
{
	std::vector<WebRecvHandler>::iterator it = _recvHandlers.begin();
	while (it != _recvHandlers.end())
	{
		it->hand(id, data);
		it++;
	}
}

HttpRequest* WebApplication::createHttpRequest( sys::DataQueue& dataQueue )
{
	sys::NetData* data = dataQueue.top();
	if (data == nullptr)
	{
		return nullptr;
	}

	HttpRequest* request = new HttpRequest();
	request->setMessage(data->data, data->size);

	dataQueue.pop();
	delete data;

	return request;
}

sys::NetData* WebApplication::createResponseData( HttpResponse* response )
{
	if (response == nullptr)
	{
		return nullptr;
	}

	return new sys::NetData(response->getMessage(), response->size());
}

WebApplication* WebApplication::getInstance()
{
	ASSERT(s_pWebApplication != nullptr);

	return s_pWebApplication;
}
