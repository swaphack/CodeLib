#pragma once

#include "web.h"

namespace gs
{
	class GameServer : public web::WebApplication
	{
	public:
		GameServer(const char* ip, int port);
		virtual ~GameServer();
	public:
		virtual void init();
	protected:
	private:
	};
}