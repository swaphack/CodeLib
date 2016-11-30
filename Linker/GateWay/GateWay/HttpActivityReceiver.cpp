#include "HttpActivityReceiver.h"
#include "GateWay.h"
using namespace gw;

#define G_RESOURCE WebApplication::getInstance()->getResourceMgr()->getResource(ERT_LOCAL)

bool HttpActivityReceiver::isHttpServer()
{
	int socketID = sGateWay->getSocketID(_sessionID.c_str());
	return socketID == sGateWay->getHttpServerListenerID();
}

void HttpActivityReceiver::doGetRequest(sys::HttpRequest* request)
{
	if (isHttpServer())
	{
		return;
	}

	// 来自客户端，转给服务器

	sys::HttpReqDocument* pReqDocument = request->getDocument();
	pReqDocument->setHeader("ClientID", _sessionID.c_str());

	this->doPostRequest(sGateWay->getHttpServerListenerID(), request);
}

void HttpActivityReceiver::doGetResponse(sys::HttpResponse* response)
{
	if (!isHttpServer())
	{
		return;
	}

	// 来自服务器，转给客户端

	sys::HttpRespDocument* pReqDocument = response->getDocument();
	std::string clientID = pReqDocument->getHeader("ClientID");

	pReqDocument->removeHeader("ClientID");	

	this->doPostResponse(clientID.c_str(), response);
}

