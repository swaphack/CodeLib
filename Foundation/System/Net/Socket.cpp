#include "Socket.h"
#include "EndPoint.h"
#include "DNS.h"
#include <cstdio>

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


#if (defined(_WIN32) || defined(WIN32))
#define INVALID_SOCKET_VALUE INVALID_SOCKET
#else
#define INVALID_SOCKET_VALUE -1
#endif

#ifdef _WIN32
static int s_InitSocketModuleCount = 0;
#endif // #ifdef _WIN32

// 接收数据大小
#define	SOCKET_DATA_SIZE 32 * 1024
// IO 缓存大小
#define SOCKET_BUFFER_SIZE 1024 * 1024
// 超时时间（单位：毫秒）
#define SOCKET_TIME_OUT 5000


using namespace sys;

Socket::Socket()
{
	_sock = ::socket(AF_INET, SOCK_STREAM, 0);

	this->initDefaultOPT();
}

Socket::Socket(int sock)
{
	_sock = sock;

	this->initDefaultOPT();

	initLocalAndRemote();
}

void Socket::InitSockModule()
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
	int err;  

	wVersionRequested = MAKEWORD( 1, 1 );

	err = ::WSAStartup(wVersionRequested, &wsaData);
	if ( err != 0 ) {  
		return;
	}  

	if ( LOBYTE( wsaData.wVersion ) != 1 || HIBYTE( wsaData.wVersion ) != 1 ) {  
		::WSACleanup();
		return;   
	}  
#endif
}

void Socket::ReleaseSockModule()
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

Socket::~Socket()
{
	Close();
}

void Socket::Bind(const char* addr, int port, bool ipv6)
{
	struct sockaddr_in addrSrv;  
	EndPoint point(addr, port, ipv6);
	point.getAddr(&addrSrv);

	int result = ::bind(_sock, (struct sockaddr*)&addrSrv, sizeof(struct sockaddr));
#if _DEBUG
	PRINT("Socket Bind Result, code:%d\n", result);
#endif
}

void Socket::Listen(int maxCount)
{
	int result = ::listen(_sock, maxCount);
#if _DEBUG
	PRINT("Socket Listen Result, code:%d\n", result);
#endif
}

Socket* Socket::Accept()
{
	struct sockaddr_in addrClient;  
	int len = sizeof(struct sockaddr);  
	SOCKET sock = ::accept(_sock, (struct sockaddr*)&addrClient, &len);
	if (sock == INVALID_SOCKET_VALUE)
	{
		return nullptr;
	}
	
	return new Socket(sock);
}

bool Socket::Connect(const char* addr, int port, bool ipv6)
{
	struct sockaddr_in addrSrv;
	EndPoint point(addr, port, ipv6);
	point.getAddr(&addrSrv);

	bool result = ::connect(_sock, (struct sockaddr*)&addrSrv, sizeof(struct sockaddr)) == 0;
	if (result)
	{
		initLocalAndRemote();
	}

	return result;
}

int Socket::Send( const char* data, int size )
{
	return ::send(_sock, data, size, 0);
}

char* Socket::Recv( int& size )
{
	static char s_recvData[SOCKET_DATA_SIZE] = { 0 };
	memset(s_recvData, 0, SOCKET_DATA_SIZE);
	size = ::recv(_sock, s_recvData, SOCKET_DATA_SIZE - 1, 0);
#if _DEBUG
	if (size > 0)
	{
		PRINT("%s", s_recvData);
	}
#endif
	return s_recvData;
}

void Socket::ShutDown( int type )
{
	::shutdown(_sock, type);
}

bool Socket::HasError()
{
#ifdef _WIN32
	int error = ::WSAGetLastError();
	if (error != WSAEWOULDBLOCK) 
	{
		return true;
	}
#else
	int err = errno;
	if(err != EINPROGRESS && err != EAGAIN) 
	{
		return true;
	}
#endif
	return false;
}

void Socket::Close()
{
	if (_sock != INVALID_SOCKET_VALUE)
	{
		::closesocket(_sock);
	}
#if _DEBUG
	if (_sock != INVALID_SOCKET_VALUE)
	{
		PRINT("Socket close %d\n", _sock);
	}
#endif
	_sock = INVALID_SOCKET_VALUE;
}

int Socket::getID()
{
	return _sock;
}

const char* Socket::getLocalIP()
{
	return _localEP.addr.c_str();
}

int Socket::getLocalPort()
{
	return _localEP.port;
}

const char* Socket::getRemoteIP()
{
	return _remoteEP.addr.c_str();
}

int Socket::getRemotePort()
{
	return _remoteEP.port;
}

void Socket::initDefaultOPT()
{
	//non-blocking mode is enabled.
#ifdef _WIN32
	u_long iMode = 1;
	::ioctlsocket(_sock, FIONBIO, &iMode);
#else
	int flags = fcntl(_sock, F_GETFL, 0); 
	fcntl(_sock, F_SETFL, flags | O_NONBLOCK);
#endif 	

	bool bDtLger = false;
	::setsockopt(_sock, SOL_SOCKET, SO_DONTLINGER, (const char*)&bDtLger, sizeof(bool));

	int nNetTimeout = SOCKET_TIME_OUT;
	::setsockopt(_sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&nNetTimeout, sizeof(int));
	::setsockopt(_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&nNetTimeout, sizeof(int));

	int nBufSize = SOCKET_BUFFER_SIZE;
	::setsockopt(_sock, SOL_SOCKET, SO_SNDBUF, (const char*)&nBufSize, sizeof(int));
	::setsockopt(_sock, SOL_SOCKET, SO_RCVBUF, (const char*)&nBufSize, sizeof(int));

	_localEP.addr = "";
	_localEP.port = 0;

	_remoteEP.addr = "";
	_remoteEP.port = 0;
}

void Socket::initLocalAndRemote()
{
	if (_sock == INVALID_SOCKET_VALUE)
	{
		return;
	}

	struct sockaddr_in addr_in;
	int len;
	std::string ip;
	int port;

	len = sizeof(struct sockaddr_in);
	::getsockname(_sock, (struct sockaddr*)&addr_in, &len);
	DNS::getIPAddress(&addr_in, ip, port);
	_localEP.addr = ip;
	_localEP.port = port;
	_localEP.ipv6 = addr_in.sin_family == AF_INET6;

	::getpeername(_sock, (struct sockaddr*)&addr_in, &len);
	DNS::getIPAddress(&addr_in, ip, port);
	_remoteEP.addr = ip;
	_remoteEP.port = port;
	_remoteEP.ipv6 = addr_in.sin_family == AF_INET6;
}
