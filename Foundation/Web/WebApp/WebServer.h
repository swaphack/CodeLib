#pragma once

#include "macros.h"
#include "Session.h"
#include "system.h"

#include "../Http/import.h"
#include "../Packet/import.h"

namespace web
{
	// Web应用服务器
	class WebServer
	{
	public:
		WebServer(sys::Server* server);
		virtual ~WebServer();
	public:
		// 反馈给客户端
		void postResponse(const char* sessionID, sys::NetData* data);
		// 广播
		void postBroadcast(sys::NetData* data);
		// 更新
		void update();
		// 解析数据
		void onParseData(int id, sys::DataQueue& dataQueue);
		// http 监听
		HttpActivityListener* getHttpListener();
		// 报文监听
		PacketActivityListener* getPacketListener();
	protected:
		// 客户端信息
		Sessions* getSession();
	private:
		// 服务器
		sys::Server* _server;
		// 客户端信息
		Sessions* _session;
		// Http监听
		HttpActivityListener* _httpListener;
		// 报文监听
		PacketActivityListener* _packetListener;
	};
}