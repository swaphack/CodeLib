#include "DNS.h"
#include "Socket.h"
#include "Base/import.h"

#if PLATFORM_TARGET == EPT_WINDOWS
#include <WS2tcpip.h>
#elif PLATFORM_TARGET == EPT_LINUX
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>  
#elif PLATFORM_TARGET == EPT_MAC
#include <netdb.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#endif

#define DNS_IP_MAX 256

static char s_common[DNS_IP_MAX] = {0};

using namespace sys;

void DNS::getFirstIPAddress(const char* url, std::string& ip)
{
	Socket::InitSockModule();

	ip.clear();

	if (url == nullptr)
	{
		return;
	}

	struct addrinfo *result = NULL;
	struct addrinfo *ptr = NULL;
	struct addrinfo hint32s;
	int32 dwRetval;

	ZeroMemory(&hint32s, sizeof(hint32s));
	hint32s.ai_family = AF_UNSPEC;
	hint32s.ai_socktype = SOCK_STREAM;
	hint32s.ai_protocol = IPPROTO_TCP;

	dwRetval = getaddrinfo(url, 0, &hint32s, &result);
	if (dwRetval != 0) 
	{
		return;
	}
	ptr = result;
	switch (ptr->ai_family)
	{
	case AF_INET:
	{
					memset(s_common, 0, DNS_IP_MAX);
					struct sockaddr_in *sockaddr_ipv4 = (struct sockaddr_in *) ptr->ai_addr;
					ip = inet_ntop(ptr->ai_family, &sockaddr_ipv4->sin_addr, s_common, DNS_IP_MAX);
					break;
	}
	case AF_INET6:
	{
					 memset(s_common, 0, DNS_IP_MAX);
					 struct sockaddr_in6 *sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
					 ip = inet_ntop(ptr->ai_family, &sockaddr_ipv6->sin6_addr, s_common, DNS_IP_MAX);
					 break;
	}
	default:
		break;
	}

	Socket::ReleaseSockModule();
}

void DNS::getAllIPAddress(const char* url, std::map<std::string, int32>& ipAddresses)
{
	Socket::InitSockModule();

	ipAddresses.clear();
	if (url == nullptr)
	{
		return;
	}

	struct addrinfo *result = NULL;
	struct addrinfo *ptr = NULL;
	struct addrinfo hint32s;
	int32 dwRetval;
	std::string ip;
	int32 port;

	ZeroMemory(&hint32s, sizeof(hint32s));
	hint32s.ai_family = AF_UNSPEC;
	hint32s.ai_socktype = SOCK_STREAM;
	hint32s.ai_protocol = IPPROTO_TCP;

	dwRetval = getaddrinfo(url, 0, &hint32s, &result);
	if (dwRetval != 0)
	{
		return;
	}
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{
		switch (ptr->ai_family)
		{
		case AF_INET:
		{
						memset(s_common, 0, DNS_IP_MAX);
						struct sockaddr_in *sockaddr_ipv4 = (struct sockaddr_in *) ptr->ai_addr;
						ip = inet_ntop(ptr->ai_family, &sockaddr_ipv4->sin_addr, s_common, DNS_IP_MAX);
						port = ntohs(sockaddr_ipv4->sin_port);
						ipAddresses[ip] = port;
						break;
		}
		case AF_INET6:
		{
						 memset(s_common, 0, DNS_IP_MAX);
						 struct sockaddr_in6 *sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
						 ip = inet_ntop(ptr->ai_family, &sockaddr_ipv6->sin6_addr, s_common, DNS_IP_MAX);
						 port = ntohs(sockaddr_ipv6->sin6_port);
						 ipAddresses[ip] = port;
						 break;
		}
		default:
			break;
		}
	}

	Socket::ReleaseSockModule();
}

void DNS::getIPAddress(struct addrinfo* addr_info, std::string& ip, int32& port)
{
	ip.clear();
	port = 0;

	if (addr_info == nullptr)
	{
		return;
	}

	switch (addr_info->ai_family)
	{
	case AF_INET:
	{
					memset(s_common, 0, DNS_IP_MAX);
					struct sockaddr_in *sockaddr_ipv4 = (struct sockaddr_in *) addr_info->ai_addr;
					ip = inet_ntop(sockaddr_ipv4->sin_family, &sockaddr_ipv4->sin_addr, s_common, DNS_IP_MAX);
					port = ntohs(sockaddr_ipv4->sin_port);
					break;
	}
	case AF_INET6:
	{
					 memset(s_common, 0, DNS_IP_MAX);
					 struct sockaddr_in6 *sockaddr_ipv6 = (struct sockaddr_in6 *) addr_info->ai_addr;
					 ip = inet_ntop(sockaddr_ipv6->sin6_family, &sockaddr_ipv6->sin6_addr, s_common, DNS_IP_MAX);
					 port = ntohs(sockaddr_ipv6->sin6_port);
					 break;
	}
	default:
		break;
	}
}

void DNS::getIPAddress(struct sockaddr_in* addr_in, std::string& ip, int32& port)
{
	ip.clear();
	port = 0;

	if (addr_in == nullptr)
	{
		return;
	}

	switch (addr_in->sin_family)
	{
	case AF_INET:
	{		
					memset(s_common, 0, DNS_IP_MAX);
					ip = inet_ntop(addr_in->sin_family, &addr_in->sin_addr, s_common, DNS_IP_MAX);
					port = ntohs(addr_in->sin_port);
					break;
	}
	case AF_INET6:
	{
					 memset(s_common, 0, DNS_IP_MAX);
					 struct sockaddr_in6 *sockaddr_ipv6 = (struct sockaddr_in6 *) addr_in;
					 ip = inet_ntop(sockaddr_ipv6->sin6_family, &sockaddr_ipv6->sin6_addr, s_common, DNS_IP_MAX);
					 port = ntohs(sockaddr_ipv6->sin6_port);
					 break;
	}
	default:
		break;
	}
}



