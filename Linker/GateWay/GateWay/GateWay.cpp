#include "GateWay.h"

#include "TextActivityListener.h"

using namespace web;
using namespace gw;

GateWay::GateWay(const char* ip, int port, int maxWaitCount)
:WebApplication(ip, port, maxWaitCount)
{
	_gameServerListenerID = 0;
	_httpServerListenerID = 0;

	this->initSelf();
}

GateWay::~GateWay()
{

}

void GateWay::initSelf()
{
	//_listenerPool->addListener(new TextActivityListener());
}

bool GateWay::createGameServerListener(const char* ip, int port)
{
	sys::Client* pClient = getClient()->createClient(ip, port);
	if (pClient == nullptr)
	{
		return false;
	}

	_gameServerListenerID = pClient->getID();

	return true;
}

bool GateWay::createHttpServerListener(const char* ip, int port)
{
	sys::Client* pClient = getClient()->createClient(ip, port);
	if (pClient == nullptr)
	{
		return false;
	}

	_httpServerListenerID = pClient->getID();

	return true;
}

int GateWay::getGameServerListenerID()
{
	return _gameServerListenerID;
}

int GateWay::getHttpServerListenerID()
{
	return _httpServerListenerID;
}