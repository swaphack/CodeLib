#pragma once

#include <string>
#include <cstdint>
#include <map>

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
		static void getAllIPAddress(const char* url, std::map<std::string, int32_t>& ipAddresses);
		// ��ȡip��ַ�Ͷ˿�
		static void getIPAddress(struct addrinfo* addr_info, std::string& ip, int32_t& port);
		// ��ȡip��ַ�Ͷ˿�
		static void getIPAddress(struct sockaddr_in* addr_in, std::string& ip, int32_t& port);
	private:
	};
}