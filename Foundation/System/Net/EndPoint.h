#pragma once

#include <string>
#include <cstdint>

struct sockaddr_in;

namespace sys
{
	struct EndPoint 
	{
	public:
		// ip地址
		std::string addr;
		// ip端口
		int32_t port = 0;
		// 是否ipv6
		bool ipv6 = false;
	public:
		EndPoint();
		EndPoint(const std::string& addr, int32_t port, bool ipv6);
	public:
		// 获取socket地址信息
		void getAddr(struct sockaddr_in* addr_in) const;
	public:
		// 从socket 中获取本地信息
		static EndPoint loadLocalSocket(int32_t socketID);
		// 从socket 中获取远程信息
		static EndPoint loadPeerSocket(int32_t socketID);
	};
}