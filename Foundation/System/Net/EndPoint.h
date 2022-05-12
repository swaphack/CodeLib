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
		int32_t port = 0;
		// �Ƿ�ipv6
		bool ipv6 = false;
	public:
		EndPoint();
		EndPoint(const std::string& addr, int32_t port, bool ipv6);
	public:
		// ��ȡsocket��ַ��Ϣ
		void getAddr(struct sockaddr_in* addr_in) const;
	public:
		// ��socket �л�ȡ������Ϣ
		static EndPoint loadLocalSocket(int32_t socketID);
		// ��socket �л�ȡԶ����Ϣ
		static EndPoint loadPeerSocket(int32_t socketID);
	};
}