#include "WebServer.h"

using namespace web;

WebServer::WebServer()
:_server(nullptr)
{
}

WebServer::~WebServer()
{
	SAFE_DELETE(_server);
}

sys::Server* WebServer::createServer(const std::string& ip, int port, int maxWaitCount)
{
	if (ip.empty())
	{
		return nullptr;
	}

	SAFE_DELETE(_server);

	_server = new sys::Server(ip, port, maxWaitCount);
	_server->setRecvHandler(_recvHandler.first, _recvHandler.second);
	_server->setCloseHandler(_closeHandler.first, _closeHandler.second);

	return _server;
}

void WebServer::postResponse(int id, sys::NetData* data)
{
	if (data == nullptr || _server == nullptr)
	{
		return;
	}

	_server->sendMessage(id, data);
}

void WebServer::postBroadcast(sys::NetData* data)
{
	if (data == nullptr || _server == nullptr)
	{
		return;
	}

	_server->sendBroadcast(data);
}

void WebServer::setRecvHandler(sys::Object* target, sys::CLIENT_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_recvHandler.first = target;
	_recvHandler.second = handler;
}

void WebServer::setCloseHandler(sys::Object* target, sys::CLIENT_CLOSE_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_closeHandler.first = target;
	_closeHandler.second = handler;
}

void WebServer::update()
{
	if (_server)
	{
		_server->update();
	}
}