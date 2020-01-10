#pragma once

#include "Base/Types.h"

struct sockaddr_in;

namespace sys
{
	struct EndPoint 
	{
		// ip��ַ
		std::string addr;
		// ip�˿�
		int32_t port;
		// �Ƿ�ipv6
		bool ipv6;

		EndPoint();
		EndPoint(const char* addr, int32_t port, bool ipv6);
		// ��ȡsocket��ַ��Ϣ
		void getAddr(struct sockaddr_in* addr_in);
	};
}