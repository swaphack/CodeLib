#pragma once

#include <string>
#include <vector>

namespace sys
{
	class DNS
	{
	public:
		// 获取首个ip地址
		static void getIPAddress(const char* url, std::string& ip);
		// 获取所有ip地址
		static void getIPAddress(const char* url, std::vector<std::string>& ips);
	private:
	};
}