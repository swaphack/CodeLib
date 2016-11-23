#include "HttpServer.h"

using namespace web;
using namespace hs;

HttpServer::HttpServer(const char* ip, int port, int maxWaitCount)
:WebApplication(ip, port, maxWaitCount)
{
	this->initSelf();
}

HttpServer::~HttpServer()
{

}

void HttpServer::initSelf()
{
}