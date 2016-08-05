#pragma once

namespace sys
{
	#define DNS_IP_MAX 256

	class DNS
	{
	public:
		// µØÖ·×ªip
		static const char* getIPAddress(const char* url);

	private: 
		static char s_common[DNS_IP_MAX];
	};
}