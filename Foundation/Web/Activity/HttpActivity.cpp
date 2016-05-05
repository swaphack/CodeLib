#include "HttpActivity.h"
#include "../WebApplication.h"

using namespace web;


HttpActivity::HttpActivity()
:_srcID(0)
{
	WebApplication::getInstance()->addRecvHandler(this, static_cast<WEB_RECV_HANDLER>(&HttpActivity::onReceiveRequest));
}

HttpActivity::~HttpActivity()
{
	WebApplication::getInstance()->removeRecvHandler(this, static_cast<WEB_RECV_HANDLER>(&HttpActivity::onReceiveRequest));
}

void HttpActivity::onReceiveRequest(int id, HttpRequest* request)
{
	_srcID = id;

	if (request == nullptr)
	{
		return;
	}

	this->doGet(request);
}


void HttpActivity::doGet( HttpRequest* request )
{

}

void HttpActivity::doPost( HttpResponse* response )
{
	if (response == nullptr)
	{
		return;
	}
	this->sendResponse(_srcID, response);
}

void HttpActivity::sendResponse(int id, HttpResponse* response)
{
	WebApplication::getInstance()->postResponse(id, response);
}
