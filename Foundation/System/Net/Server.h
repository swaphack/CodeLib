#pragma once

#include "Framework/Object.h"
#include "Socket.h"
#include "NetData.h"
#include "DataQueue.h"
#include "SocketRecvHandler.h"
#include <map>

namespace sys
{
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 9547

	class Server
	{
	public:
		Server();
		Server(const std::string& ip, int32_t port, int32_t backlog);
		~Server();
	public:
		/*
		 * 更新
		 * 接收客户端连接
		 * 接收客户端数据
		 * 发送数据给客户端
		 */
		void update();
		// 设置接收数据时的处理
		void setRecvHandler(Object* target, SERVER_RECV_HANDLER handler);
		// 设置客户端断开时的处理
		void setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler);
		// 发送消息, 使用new，发送完毕后会自动释放
		void sendMessage(int32_t id, NetData* data);
		// 广播
		void sendBroadcast(NetData* data);
	protected:
		// 添加客户端
		void addClient(Socket* sock);
		// 移除客户端
		void removeClient(int32_t sockId);
		// 移除所有客户端
		void removeAllClients();
		// 添加接收到的数据
		void addRecvBuffer(int32_t id, NetData* data);
		// 添加带发送的数据
		void addSendBuffer(int32_t id, NetData* data);
		// 接收数据时处理
		void onRecvHandler(int32_t id, NetData* data);
	private:
		// 接收数据，并且存储断开的socket连接
		void _recvData(std::vector<int32_t>& removedSocks);
		// 移除socekt
		void _removeSockets(std::vector<int32_t>& removedSocks);
		// 清除数据检查
		void _flushData();
		// 发送消息
		void _flushSendData();
		// 接受消息
		void _flushRecvData();
	protected:
		Socket* _socket;
		// 客户端
		std::map<int32_t, Socket*> _clients;
		// 接收到的数据
		std::map<int32_t, DataQueue*> _recvDatas;
		// 待发送的数据
		std::map<int32_t, DataQueue*> _sendDatas;
		// 接收数据时的处理
		ServerRecvHandler _recvHandler;
		// 客户端断开时的处理
		ClientCloseHandler _closeHandler;
	};
}