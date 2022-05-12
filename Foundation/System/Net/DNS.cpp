#include "DNS.h"
#include "SocketModule.h"
#include "Base/import.h"
#include "Type/String.h"
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

void DNS::getFirstIPAddress(const std::string& url, std::string& ip, int32_t& port)
{
	SocketModule::InitSockModule();

	ip.clear();

	if (url.empty())
	{
		return;
	}

	struct addrinfo *result = NULL;
	struct addrinfo *ptr = NULL;
	struct addrinfo hint32s;
	int32_t dwRetval;

	ZeroMemory(&hint32s, sizeof(hint32s));
	hint32s.ai_family = AF_UNSPEC;
	hint32s.ai_socktype = SOCK_STREAM;
	hint32s.ai_protocol = IPPROTO_TCP;

	dwRetval = getaddrinfo(url.c_str(), 0, &hint32s, &result);
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
					port = ntohs(sockaddr_ipv4->sin_port);
					break;
	}
	case AF_INET6:
	{
					 memset(s_common, 0, DNS_IP_MAX);
					 struct sockaddr_in6 *sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
					 ip = inet_ntop(ptr->ai_family, &sockaddr_ipv6->sin6_addr, s_common, DNS_IP_MAX);
					 port = ntohs(sockaddr_ipv6->sin6_port);
					 break;
	}
	default:
		break;
	}

	SocketModule::ReleaseSockModule();
}

void DNS::getAllIPAddress(const std::string& url, std::vector<std::pair<std::string, int32_t>>& ipAddresses)
{
	SocketModule::InitSockModule();

	ipAddresses.clear();
	if (url.empty())
	{
		return;
	}

	struct addrinfo *result = NULL;
	struct addrinfo *ptr = NULL;
	struct addrinfo hint32s;
	int32_t dwRetval;
	std::string ip;
	int32_t port;

	ZeroMemory(&hint32s, sizeof(hint32s));
	hint32s.ai_family = AF_UNSPEC;
	hint32s.ai_socktype = SOCK_STREAM;
	hint32s.ai_protocol = IPPROTO_TCP;

	dwRetval = getaddrinfo(url.c_str(), 0, &hint32s, &result);
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
						ipAddresses.push_back(std::make_pair(ip, port));
						break;
		}
		case AF_INET6:
		{
						 memset(s_common, 0, DNS_IP_MAX);
						 struct sockaddr_in6 *sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
						 ip = inet_ntop(ptr->ai_family, &sockaddr_ipv6->sin6_addr, s_common, DNS_IP_MAX);
						 port = ntohs(sockaddr_ipv6->sin6_port);
						 ipAddresses.push_back(std::make_pair(ip, port));
						 break;
		}
		default:
			break;
		}
	}

	SocketModule::ReleaseSockModule();
}

void DNS::getIPAddress(struct addrinfo* addr_info, std::string& ip, int32_t& port)
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

void DNS::getIPAddress(struct sockaddr_in* addr_in, std::string& ip, int32_t& port)
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


