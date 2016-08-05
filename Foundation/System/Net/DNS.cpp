#include "DNS.h"

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

using namespace sys;

char sys::DNS::s_common[DNS_IP_MAX] = { 0 };

const char* DNS::getIPAddress(const char* url)
{
	struct hostent* pHostent = gethostbyname(url);
	if (pHostent == nullptr)
	{
		return nullptr;
	}

	short i;

	for (i = 0; i < pHostent->h_length; i++)
	{
		if (pHostent->h_addr_list[i] != nullptr)
		{
			return inet_ntop(pHostent->h_addrtype, pHostent->h_addr_list[i], s_common, sizeof(s_common));
		}
	}

	return nullptr;
}



