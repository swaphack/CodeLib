#pragma once

#include "macros.h"
#include "Base/Types.h"
#include "EndPoint.h"

namespace sys
{
	class Socket
	{
	public:
		Socket();
		Socket(int32 sock);
		~Socket();
	public:
		// 用于socket模块启动
		static void InitSockModule();
		// 用于socket模块销毁
		static void ReleaseSockModule();

		// 绑定ip和端口
		void bind(const char* addr, int32 port, bool ipv6 = false);
		// 设置最大等待数
		void listen(int32 maxCount);
		// 接收到新的连接
		Socket* accept();
		// 连接到远程服务端
		bool connect(const char* addr, int32 port, bool ipv6 = false);
		// 发送消息
		int32 write(const char* data, int32 size);
		/** 
		*	接收消息
		*	-1 等待，判断是否连接有错
		*	0 断开连接
		*	大于0， 接收到数据
		*/
		char* read(int32& size);
		// 关闭指定Socket IO
		void shutDown(int32 type);
		// 是否连接有误
		bool hasError();
		// 关闭socket
		void close();
		// 获取socketID
		int32 getID();

		// 获取本地ip
		const char* getLocalIP();
		// 获取本地端口
		int32 getLocalPort();
		// 获取远程ip
		const char* getRemoteIP();
		// 获取远程端口
		int32 getRemotePort();
	protected:
		// 初始化默认socket环境
		// 非堵塞
		void initDefaultOPT();
		// 初始化本地和远程信息
		void initLocalAndRemote();
	private:
		// socket id
		int32 _sock;
		// 本地地址和端口信息
		EndPoint _localEP;
		// 远程地址和端口信息
		EndPoint _remoteEP;
	};
}