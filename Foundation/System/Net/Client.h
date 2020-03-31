#pragma once

#include "DataQueue.h"
#include "SocketRecvHandler.h"
#include <cstdint>
#include <string>
#include <map>

namespace sys
{
	class Object;
	class Socket;

	class Client
	{
	public:
		Client(const std::string& ip, int32_t port);
		~Client();
	public:
		int32_t getID();
		// 设置远程信息
		void setRemote(const std::string& ip, int32_t port);
		// 连接服务器
		bool connect();
		// 断开连接
		bool disconnect();
		// 是否连接成功
		bool isConnected();
		/*
		 * 更新
		 * 接收数据
		 * 发送数据
		 */
		void update();
		// 设置接收导数据时的处理
		void setRecvHandler(Object* target, CLIENT_RECV_HANDLER handler);
		// 设置客户端断开时的处理
		void setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler);
		// 发送消息, 使用new，发送完毕后会自动释放
		void sendMessage(NetData* data);
		// 发送消息
		void sendString(const std::string& data);
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
		int32_t _ID;
		// 远程信息{地址，端口}
		std::pair<std::string, int32_t> _remote;
		// 是否连接服务器
		bool _bConnected;
		// socket
		Socket* _socket;
		// 接收到的数据
		DataQueue _recvDatas;
		// 待发送的数据
		DataQueue _sendDatas;
		// 接收数据时的处理
		ClientRecvHandler _recvHandler;
		// 客户端断开时的处理
		ClientCloseHandler _closeHandler;
	};
}