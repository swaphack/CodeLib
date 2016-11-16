#pragma once

#include "web.h" 
#include "system.h"

namespace gw
{

	class GateWay : public web::WebApplication
	{
	public:
		GateWay(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~GateWay();
	public:
		void initSelf();
		// 创建一个连接到远端的客户端
		bool createGameServerListener(const char* ip, int port);
		// 获取连接远程的客户端id
		int getGameServerListenerID();
	private:
		int _gameServerListenerID;
	};

#define sGateWay static_cast<GateWay*>(web::WebApplication::getInstance())
}