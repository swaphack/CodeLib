#pragma once

#include "Base/Types.h"

struct addrinfo;
struct sockaddr_in;

namespace sys
{
	class DNS
	{
	public:
		// 获取首个ip地址
		static void getFirstIPAddress(const char* url, std::string& ip);
		// 获取所有ip地址
		static void getAllIPAddress(const char* url, std::map<std::string, int32>& ipAddresses);
		// 获取ip地址和端口
		static void getIPAddress(struct addrinfo* addr_info, std::string& ip, int32& port);
		// 获取ip地址和端口
		static void getIPAddress(struct sockaddr_in* addr_in, std::string& ip, int32& port);
	private:
	};
}