#pragma once

#include <string>
#include <cstdint>
#include <vector>

struct addrinfo;
struct sockaddr_in;

namespace sys
{
	class DNS
	{
	public:
		// 获取首个ip地址
		static void getFirstIPAddress(const std::string& url, std::string& ip, int32_t& port);
		// 获取所有ip地址
		static void getAllIPAddress(const std::string& url, std::vector<std::pair<std::string, int32_t>>& ipAddresses);
		// 获取ip地址和端口
		static void getIPAddress(struct addrinfo* addr_info, std::string& ip, int32_t& port);
		// 获取ip地址和端口
		static void getIPAddress(struct sockaddr_in* addr_in, std::string& ip, int32_t& port);
	private:
	};
}