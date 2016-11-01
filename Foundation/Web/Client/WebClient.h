#pragma once

#include "system.h"

#include <map>

namespace web
{
	// Web客户端,用于处理与其他服务器连接
	class WebClient
	{
	public:
		WebClient();
		virtual ~WebClient();
	public:
		// 创建一个客户端
		sys::Client* createClient(const char* ip, int port);
		// 获取客户端
		sys::Client* getClient(int id);
		// 关闭一个客户端
		void closeClient(int id);
		// 关闭所有客户端
		void removeAllClients();
		// 设置接收导数据时的处理
		void setRecvHandler(sys::Object* target, sys::CLIENT_RECV_HANDLER handler);
		// 设置客户端断开时的处理
		void setCloseHandler(sys::Object* target, sys::CLIENT_CLOSE_HANDLER handler);
		// 更新
		void update();
	private:
		// 创建的客户端集
		std::map<int, sys::Client*> _clients;
		// 接收数据时的处理
		sys::ClientRecvHandler _recvHandler;
		// 客户端断开时的处理
		sys::ClientCloseHandler _closeHandler;
	};
}