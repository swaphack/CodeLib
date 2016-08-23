#pragma once

#include <string>

struct sockaddr_in;

namespace sys
{
	struct EndPoint 
	{
		// ip地址
		std::string addr;
		// ip端口
		int port;
		// 是否ipv6
		bool ipv6;

		EndPoint();
		EndPoint(const char* addr, int port, bool ipv6);
		// 获取socket地址信息
		void getAddr(struct sockaddr_in* addr_in);
	};
}