#include "WebApplication.h"

using namespace web;

WebApplication::WebApplication( const char* ip, int port, int maxWaitCount )
:_ip(ip)
,_port(port)
,_maxWaitCount(maxWaitCount)
,_server(nullptr)
{
	sys::Socket::InitSockModule();
}

WebApplication::~WebApplication()
{

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

	checkAutoRealsePool();
}

void WebApplication::dispose()
{
	this->disposeNet();
}

void WebApplication::initNet()
{
	_server = new sys::Server(_ip.c_str(), _port, _maxWaitCount);
	_server->setRecvHandler(this, static_cast<sys::SERVER_RECV_HANDLER>(&WebApplication::parseData));
}

void WebApplication::disposeNet()
{
	SAFE_DELETE(_server);
}

void WebApplication::parseData( int id, sys::DataQueue& dataQueue )
{
	this->onParseData(id, dataQueue);
}

void web::WebApplication::onParseData(int id, sys::DataQueue& dataQueue)
{

}
