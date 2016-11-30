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
		// 创建一个连接到游戏服务器的客户端
		bool createGameServerListener(const char* ip, int port);
		// 创建一个连接到 网站服务器的客户端
		bool createHttpServerListener(const char* ip, int port);
		// 获取连接游戏服务器的客户端id
		int getGameServerListenerID();
		// 获取连接 网站服务器的客户端id
		int getHttpServerListenerID();
	private:
		// 游戏服务器socket监听id
		int _gameServerListenerID;
		// 网站服务器socket监听id;
		int _httpServerListenerID;

	};

#define sGateWay static_cast<GateWay*>(web::WebApplication::getInstance())
}