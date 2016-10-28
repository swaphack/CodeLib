#include "GameServer.h"

using namespace web;
using namespace gs;

GameServer::GameServer(const char* ip, int port)
:WebApplication(ip, port)
{
	this->init();
}

GameServer::~GameServer()
{

}

void GameServer::init()
{
	WebApplication::init();
}
