#pragma once

#include "macros.h"
#include <map>
#include <string>

namespace sys
{
	class Socket
	{
	public:
		Socket();
		Socket(int sock);
		~Socket();
	public:
		// 用于socket模块启动
		static void InitSockModule();
		// 用于socket模块销毁
		static void ReleaseSockModule();

		// 绑定ip和端口
		void Bind(const char* addr, int port, bool ipv6 = false);
		// 设置最大等待数
		void Listen(int maxCount);
		// 接收到新的连接
		Socket* Accept();
		// 连接到远程服务端
		bool Connect(const char* addr, int port, bool ipv6 = false);
		// 发送消息
		int Send(const char* data, int size);
		/** 
		*	接收消息
		*	-1 等待，判断是否连接有错
		*	0 断开连接
		*	大于0， 接收到数据
		*/
		char* Recv(int& size);
		// 关闭指定Socket IO
		void ShutDown(int type);
		// 是否连接有误
		bool HasError();
		// 关闭socket
		void Close();
		// 获取socketID
		int getID();

		// 获取本地ip
		const char* getLocalIP();
		// 获取本地端口
		int getLocalPort();
		// 获取远程ip
		const char* getRemoteIP();
		// 获取远程端口
		int getRemotePort();
	protected:
		// 初始化默认socket环境
		// 非堵塞
		void initDefaultOPT();
		// 初始化本地和远程信息
		void initLocalAndRemote();
	private:
		// socket id
		int _sock;
		// 本地地址和端口信息
		std::pair<std::string, int> _localEP;
		// 远程地址和端口信息
		std::pair<std::string, int> _remoteEP;
	};


}