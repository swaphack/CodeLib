#pragma once

#include "macros.h"

namespace sys
{
	// 接收数据大小
	#define	SOCKET_DATA_SIZE 32 * 1024
	// IO 缓存大小
	#define SOCKET_BUFFER_SIZE 1024 * 1024
	// 超时时间（单位：毫秒）
	#define SOCKET_TIME_OUT 100

	class Socket
	{
	public:
		Socket();
		Socket(int sock);
		~Socket();
	public:
		// 用于socket模块启动和销毁
		static void InitSockModule();
		static void ReleaseSockModule();

		// 绑定ip和端口
		void Bind(const char* addr, int port);
		// 设置最大等待数
		void Listen(int maxCount);
		// 接收到新的连接
		Socket* Accept();
		// 连接到远程服务端
		bool Connect(const char* addr, int port);
		// 发送消息
		int Send(const char* data, int size);
		// 接收消息
		char* Recv(int& size);
		// 关闭指定Socket IO
		void ShutDown(int type);
		// 是否连接有误
		bool HasError();
		// 关闭socket
		void Close();
		// 获取socketID
		int getID();
	protected:
		// 初始化默认socket环境
		// 非堵塞
		void initDefaultOPT();
	private:
		int _sock;
	};


}