#include "DNS.h"
#include "Socket.h"
#include "../Base/import.h"

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

void DNS::getIPAddress(const char* url, std::string& ip)
{
	sys::Socket::InitSockModule();

	ip.clear();
	if (url == nullptr)
	{
		return;
	}

	struct addrinfo *result = NULL;
	struct addrinfo *ptr = NULL;
	struct addrinfo hints;
	int dwRetval;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	dwRetval = getaddrinfo(url, 0, &hints, &result);
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

	sys::Socket::ReleaseSockModule();
}

void DNS::getIPAddress(const char* url, std::vector<std::string>& ips)
{
	sys::Socket::InitSockModule();

	ips.clear();
	if (url == nullptr)
	{
		return;
	}

	struct addrinfo *result = NULL;
	struct addrinfo *ptr = NULL;
	struct addrinfo hints;
	int dwRetval;
	std::string ip;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	dwRetval = getaddrinfo(url, 0, &hints, &result);
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
						ips.push_back(ip);
						break;
		}
		case AF_INET6:
		{
						 memset(s_common, 0, DNS_IP_MAX);
						 struct sockaddr_in6 *sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
						 ip = inet_ntop(ptr->ai_family, &sockaddr_ipv6->sin6_addr, s_common, DNS_IP_MAX);
						 ips.push_back(ip);
						 break;
		}
		default:
			break;
		}
	}

	sys::Socket::ReleaseSockModule();
}



