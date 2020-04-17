#pragma once

#include "Session.h"
#include "system.h"

#include "Http/import.h"
#include "Packet/import.h"
#include "Listener/import.h"

namespace web
{
	// Web服务端
	class WebServer
	{
	public:
		WebServer();
		virtual ~WebServer();
	public:
		// 创建一个服务器
		sys::Server* createServer(const std::string& ip, int port, int maxWaitCount);
		// 反馈给客户端
		void postResponse(int id, sys::NetData* data);
		// 广播
		void postBroadcast(sys::NetData* data);
		// 设置接收导数据时的处理
		void setRecvHandler(sys::Object* target, sys::CLIENT_RECV_HANDLER handler);
		// 设置客户端断开时的处理
		void setCloseHandler(sys::Object* target, sys::CLIENT_CLOSE_HANDLER handler);
		// 更新
		void update();
	private:
		// 服务器
		sys::Server* _server;
		// 接收数据时的处理
		sys::ClientRecvHandler _recvHandler;
		// 客户端断开时的处理
		sys::ClientCloseHandler _closeHandler;
	};
}