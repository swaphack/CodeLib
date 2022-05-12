#pragma once

#include "EndPoint.h"
#include "SocketModule.h"
#include <string>
#include <cstdint>

namespace sys
{
	/**
	*	udp
	*/
	class UDPSocket
	{
	public:
		UDPSocket();
		~UDPSocket();
	public:
		// 绑定ip和端口
		void bind(const std::string& addr, int32_t port, bool ipv6 = false);
		// 设置远程信息
		void setRemote(const std::string& addr, int32_t port, bool ipv6 = false);
		// 关闭socket
		void close();
	public:
		// 发送消息
		int32_t write(const char* data, int32_t size);
		/**
		*	接收消息
		*	-1 等待，判断是否连接有错
		*	0 断开连接
		*	大于0， 接收到数据
		*/
		char* read(int32_t& size);
		// 是否连接有误
		bool hasError() const;
	public:
		// 获取本地ip
		const std::string& getLocalIP() const;
		// 获取本地端口
		int32_t getLocalPort() const;
		// 获取远程ip
		const std::string& getRemoteIP() const;
		// 获取远程端口
		int32_t getRemotePort() const;
	protected:
		// 初始化默认socket环境
		// 非堵塞
		void initDefaultOPT();
	private:
		// socket id
		int32_t _sock = sys::SocketModule::INVALID_SOCKET_VALUE;
		// 本地地址和端口信息
		EndPoint _localEP;
		// 远程地址和端口信息
		EndPoint _remoteEP;
	};
}