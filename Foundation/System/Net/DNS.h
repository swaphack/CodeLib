#pragma once

#include <string>
#include <vector>

namespace sys
{
	class DNS
	{
	public:
		// ��ȡ�׸�ip��ַ
		static void getIPAddress(const char* url, std::string& ip);
		// ��ȡ����ip��ַ
		static void getIPAddress(const char* url, std::vector<std::string>& ips);
	private:
	};
}