#pragma once

#include "web.h"
#include "../Module/import.h"
#include <map>

namespace gs
{
	/**
	*	ÓÎÏ··þÎñÆ÷
	*/
	class GameServer : public web::WebApplication
	{
	public:
		GameServer(const char* ip, int port, int maxWaitCount);
		virtual ~GameServer();
	public:
		virtual void initSelf();
	};

#define sGameServer static_cast<GameServer*>(web::WebApplication::getInstance())
}