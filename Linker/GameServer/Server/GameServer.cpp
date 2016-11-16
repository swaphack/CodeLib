#include "GameServer.h"

using namespace web;
using namespace gs;

GameServer::GameServer(const char* ip, int port, int maxWaitCount)
:WebApplication(ip, port, maxWaitCount)
{
	this->initSelf();
}

GameServer::~GameServer()
{
	
}

void GameServer::initSelf()
{
}