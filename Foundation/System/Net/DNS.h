#pragma once

#include <string>
#include <vector>

struct addrinfo;
struct sockaddr_in;

namespace sys
{
	class DNS
	{
	public:
		// ��ȡ�׸�ip��ַ
		static void getFirstIPAddress(const char* url, std::string& ip);
		// ��ȡ����ip��ַ
		static void getAllIPAddress(const char* url, std::vector<std::string>& ips);
		// ��ȡip��ַ�Ͷ˿�
		static void getIPAddress(struct addrinfo* addr_info, std::string& ip, int& port);
		// ��ȡip��ַ�Ͷ˿�
		static void getIPAddress(struct sockaddr_in* addr_in, std::string& ip, int& port);
	private:
	};
}