#include "SocketModule.h"
#include <stdint.h>
#if (defined(_WIN32) || defined(WIN32))
#include <WinSock2.h>
#endif

#if (defined(_WIN32) || defined(WIN32))
const int sys::SocketModule::INVALID_SOCKET_VALUE = INVALID_SOCKET;
#else
const int sys::SocketModule::INVALID_SOCKET_VALUE = -1;
#endif

#ifdef _WIN32
static int32_t s_InitSocketModuleCount = 0;
#endif // #ifdef _WIN32

void sys::SocketModule::InitSockModule()
{
#ifdef _WIN32
#pragma comment(lib, "WS2_32.lib")
	if (s_InitSocketModuleCount != 0)
	{
		s_InitSocketModuleCount++;
		return;
	}

	WORD wVersionRequested;
	WSADATA wsaData;
	int32_t err;

	wVersionRequested = MAKEWORD(1, 1);

	err = ::WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
		::WSACleanup();
		return;
	}
#endif
}

void sys::SocketModule::ReleaseSockModule()
{
#ifdef _WIN32
	if (s_InitSocketModuleCount == 0)
	{
		return;
	}
	s_InitSocketModuleCount--;
	if (s_InitSocketModuleCount == 0)
	{
		::WSACleanup();
	}
#endif
}
