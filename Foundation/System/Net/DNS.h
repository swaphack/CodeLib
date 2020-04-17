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
		// ��ȡ�׸�ip��ַ
		static void getFirstIPAddress(const std::string& url, std::string& ip, int32_t& port);
		// ��ȡ����ip��ַ
		static void getAllIPAddress(const std::string& url, std::vector<std::pair<std::string, int32_t>>& ipAddresses);
		// ��ȡip��ַ�Ͷ˿�
		static void getIPAddress(struct addrinfo* addr_info, std::string& ip, int32_t& port);
		// ��ȡip��ַ�Ͷ˿�
		static void getIPAddress(struct sockaddr_in* addr_in, std::string& ip, int32_t& port);
	private:
	};
}