#include "EndPoint.h"
#include "macros.h"

#if (defined(_WIN32) || defined(WIN32))
#include <WinSock2.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#endif

using namespace sys;

EndPoint::EndPoint()
:addr("")
, port(0)
, ipv6(false)
{

}

EndPoint::EndPoint(const char* addr, int32_t port, bool ipv6)
:addr(addr)
, port(port)
, ipv6(ipv6)
{

}

void EndPoint::getAddr(struct sockaddr_in* addr_in)
{
	if (ipv6)
	{
		addr_in->sin_addr.S_un.S_addr = inet_addr(addr.c_str());
		addr_in->sin_family = AF_INET6;
	}
	else
	{
		addr_in->sin_addr.S_un.S_addr = inet_addr(addr.c_str());
		addr_in->sin_family = AF_INET;
	}

	addr_in->sin_port = htons(port);
}
