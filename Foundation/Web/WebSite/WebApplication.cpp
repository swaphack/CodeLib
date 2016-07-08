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
	s_pWebApplication = this;

	sys::Socket::InitSockModule();

	this->init();
}

WebApplication::~WebApplication()
{
	this->disponse();

	sys::Socket::ReleaseSockModule();
}

WebApplication* WebApplication::getInstance()
{
	return s_pWebApplication;
}

HttpServer* WebApplication::getServer()
{
	return _server;
}

Resource* WebApplication::getResource()
{
	return _resource;
}

void WebApplication::init()
{
	sys::Server* server = new sys::Server(_ip.c_str(), _port, _maxWaitCount);
	server->setRecvHandler(this, static_cast<sys::SERVER_RECV_HANDLER>(&WebApplication::parseData));

	_server = new HttpServer(server);

	_resource = new Resource();
}

void WebApplication::update()
{
	if (_server)
	{
		_server->update();
	}

	checkAutoRealsePool();
}

void WebApplication::dispose()
{
	SAFE_DELETE(_server);
	SAFE_DELETE(_resource);
}

void WebApplication::parseData( int id, sys::DataQueue& dataQueue )
{
	_server->onParseData(id, dataQueue);
}