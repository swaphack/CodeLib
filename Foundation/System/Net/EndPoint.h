#pragma once

#include <string>
#include <cstdint>

struct sockaddr_in;

namespace sys
{
	struct EndPoint 
	{
	public:
		// ip��ַ
		std::string addr;
		// ip�˿�
		int32_t port;
		// �Ƿ�ipv6
		bool ipv6;
	public:
		EndPoint();
		EndPoint(const std::string& addr, int32_t port, bool ipv6);
	public:
		// ��ȡsocket��ַ��Ϣ
		void getAddr(struct sockaddr_in* addr_in);
	};
}