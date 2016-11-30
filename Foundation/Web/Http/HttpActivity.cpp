#include "HttpActivity.h"
#include "HttpRecvHandler.h"
#include "../WebApp/WebApplication.h"

using namespace web;

#define G_HTTPAPPLICATION WebApplication::getInstance()

HttpActivity::HttpActivity()
{
	G_HTTPAPPLICATION->getHttpListener()->addRecvHandler(this, static_cast<HTTP_RECV_REQUEST_HANDLER>(&HttpActivity::onReceiveRequest));
	G_HTTPAPPLICATION->getHttpListener()->addRecvHandler(this, static_cast<HTTP_RECV_RESPONE_HANDLER>(&HttpActivity::onReceiveResponse));
}

HttpActivity::~HttpActivity()
{
	G_HTTPAPPLICATION->getHttpListener()->removeRecvHandler(this, static_cast<HTTP_RECV_REQUEST_HANDLER>(&HttpActivity::onReceiveRequest));
	G_HTTPAPPLICATION->getHttpListener()->removeRecvHandler(this, static_cast<HTTP_RECV_RESPONE_HANDLER>(&HttpActivity::onReceiveResponse));
}

void HttpActivity::onReceiveRequest(const char* sessionID, sys::HttpRequest* request)
{
	if (sessionID == nullptr || request == nullptr)
	{
		return;
	}
	_sessionID = sessionID;

	this->doGetRequest(request);
}

void HttpActivity::onReceiveResponse(const char* sessionID, sys::HttpResponse* response)
{
	if (sessionID == nullptr || response == nullptr)
	{
		return;
	}
	_sessionID = sessionID;

	this->doGetResponse(response);
}


void HttpActivity::doGetRequest(sys::HttpRequest* request)
{

}

void HttpActivity::doGetResponse(sys::HttpResponse* response)
{

}

void HttpActivity::doPostResponse(sys::HttpResponse* response)
{
	if (response == nullptr)
	{
		return;
	}

	response->makeMessage();
	//response->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postResponse(_sessionID.c_str(), new sys::NetData(response->getMessage(), response->getMessageSize()));
}

void HttpActivity::doPostResponse(sys::HttpRequest* request)
{
	if (request == nullptr)
	{
		return;
	}

	request->makeMessage();
	//request->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postResponse(_sessionID.c_str(), new sys::NetData(request->getMessage(), request->getMessageSize()));
}

void HttpActivity::doPostResponse(int destID, sys::HttpResponse* response)
{
	if (response == nullptr)
	{
		return;
	}

	response->makeMessage();
	//response->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postResponse(destID, new sys::NetData(response->getMessage(), response->getMessageSize()));
}

void HttpActivity::doPostRequest(int destID, sys::HttpRequest* request)
{
	if (request == nullptr)
	{
		return;
	}

	request->makeMessage();
	//request->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postResponse(destID, new sys::NetData(request->getMessage(), request->getMessageSize()));
}

void HttpActivity::doPostResponse(const char* sessionID, sys::HttpResponse* response)
{
	if (sessionID == nullptr || response == nullptr)
	{
		return;
	}

	response->makeMessage();
	//response->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postResponse(sessionID, new sys::NetData(response->getMessage(), response->getMessageSize()));
}

void HttpActivity::doPostRequest(const char* sessionID, sys::HttpRequest* request)
{
	if (sessionID == nullptr || request == nullptr)
	{
		return;
	}

	request->makeMessage();
	//request->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postResponse(sessionID, new sys::NetData(request->getMessage(), request->getMessageSize()));
}

void HttpActivity::doBroadCast(sys::HttpResponse* response)
{
	if (response == nullptr)
	{
		return;
	}

	response->makeMessage();
	//response->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postBroadcast(new sys::NetData(response->getMessage(), response->getMessageSize()));
}

void HttpActivity::doBroadCast(sys::HttpRequest* request)
{
	if (request == nullptr)
	{
		return;
	}

	request->makeMessage();
	//request->setSessionID(_sessionID.c_str());

	G_HTTPAPPLICATION->postBroadcast(new sys::NetData(request->getMessage(), request->getMessageSize()));
}


