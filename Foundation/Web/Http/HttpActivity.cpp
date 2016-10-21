#include "HttpActivity.h"
#include "HttpRecvHandler.h"
#include "../WebApp/WebApplication.h"

using namespace web;

#define G_HTTPAPPLICATION WebApplication::getInstance()->getServer()


HttpActivity::HttpActivity()
{
	G_HTTPAPPLICATION->getHttpListener()->addRecvHandler(this, static_cast<HTTP_RECV_HANDLER>(&HttpActivity::onReceiveRequest));
}

HttpActivity::~HttpActivity()
{
	G_HTTPAPPLICATION->getHttpListener()->removeRecvHandler(this, static_cast<HTTP_RECV_HANDLER>(&HttpActivity::onReceiveRequest));
}

void HttpActivity::onReceiveRequest(const char* sessionID, sys::HttpRequest* request)
{
	if (sessionID == nullptr || request == nullptr)
	{
		return;
	}
	_sessionID = sessionID;

	this->doGet(request);
}


void HttpActivity::doGet(sys::HttpRequest* request)
{

}

void HttpActivity::doPost(sys::HttpResponse* response)
{
	if (response == nullptr)
	{
		return;
	}

	response->makeMessage();

	this->sendResponse(_sessionID.c_str(), response);
}

void HttpActivity::doBroadCast(sys::HttpResponse* response)
{
	if (response == nullptr)
	{
		return;
	}

	response->makeMessage();

	this->sendBroadcast(_sessionID.c_str(), response);
}

void HttpActivity::sendResponse(const char* sessionID, sys::HttpResponse* response)
{
	response->setSessionID(sessionID);
	G_HTTPAPPLICATION->postResponse(sessionID, new sys::NetData(response->getMessage(), response->getMessageSize()));
}

void HttpActivity::sendBroadcast(const char* sessionID, sys::HttpResponse* response)
{
	response->setSessionID(sessionID);
	G_HTTPAPPLICATION->postBroadcast(new sys::NetData(response->getMessage(), response->getMessageSize()));
}