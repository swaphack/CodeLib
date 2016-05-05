#pragma once

#include "../Framework/Object.h"
#include "Socket.h"
#include "NetData.h"
#include "DataQueue.h"
#include "SocketRecvHandler.h"
#include <map>

namespace sys
{
	class Client
	{
	public:
		Client(const char* ip, int port);
		~Client();
	public:
		/*
		 * 更新
		 * 接收数据
		 * 发送数据
		 */
		void update();
		// 设置接收导数据时的处理
		void setRecvHandler(Object* target, CLIENT_RECV_HANDLER handler);
		// 发送消息, 使用new，发送完毕后会自动释放
		void sendMessage(NetData* data);
	protected:
		// 添加接收到的数据
		void addRecvBuffer(NetData* data);
		// 添加带发送的数据
		void addSendBuffer(NetData* data);
		// 接收数据时处理
		void onRecvHandler(NetData* data);
	private:
		// 接收数据，并且存储断开的socket连接
		void _recvData();
		// 发送消息
		void _flushData();
	protected:
		Socket* _socket;
		DataQueue _recvDatas;
		DataQueue _sendDatas;
		// 接收数据时的处理
		ClientRecvHandler _recvHandler;
	};
}