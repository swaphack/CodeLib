#include "Socket.h"
#include <cstdio>

#if (defined(_WIN32) || defined(WIN32))
#include <WinSock2.h>
#pragma comment(lib, "WS2_32.lib")
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

static char s_recvData[SOCKET_DATA_SIZE];

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
}

void Socket::InitSockModule()
{
#ifdef _WIN32
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
	::WSACleanup();
#endif
}

Socket::~Socket()
{
	Close();
}

void Socket::Bind( const char* addr, int port )
{
	SOCKADDR_IN addrSrv;  
	addrSrv.sin_addr.S_un.S_addr = inet_addr(addr);
	addrSrv.sin_family = AF_INET;  
	addrSrv.sin_port = htons(port); 

	::bind(_sock, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
}

void Socket::Listen(int maxCount)
{
	::listen(_sock, maxCount);
}

Socket* Socket::Accept()
{
	SOCKADDR_IN  addrClient;  
	int len = sizeof(SOCKADDR);  
	SOCKET sock = ::accept(_sock, (SOCKADDR*)&addrClient, &len);
	if (sock == INVALID_SOCKET_VALUE)
	{
		return nullptr;
	}
	
	return new Socket(sock);
}

bool Socket::Connect( const char* addr, int port )
{
	SOCKADDR_IN addrSrv;  
	addrSrv.sin_addr.S_un.S_addr = inet_addr(addr);
	addrSrv.sin_family = AF_INET;  
	addrSrv.sin_port = htons(port); 

	return ::connect(_sock, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == 0;
}

int Socket::Send( const char* data, int size )
{
	return ::send(_sock, data, size, 0);
}

char* Socket::Recv( int& size )
{
	memset(s_recvData, 0, SOCKET_DATA_SIZE);
	size = ::recv(_sock, s_recvData, SOCKET_DATA_SIZE, 0);
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
	PRINT("error id %d\n", error);
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
	::closesocket(_sock);
	_sock = INVALID_SOCKET_VALUE;
}

int Socket::getID()
{
	return _sock;
}

void Socket::initDefaultOPT()
{
	//non-blocking mode is enabled.
#ifdef _WIN32
	u_long iMode = 1;
	::ioctlsocket(_sock, FIONBIO, &iMode);
#else
	int flags = fcntl(_sock, F_GETFL, 0); 
	fcntl(socket, F_SETFL, flags | O_NONBLOCK);
#endif 	

	bool bDtLger = false;
	::setsockopt(_sock, SOL_SOCKET, SO_DONTLINGER, (const char*)&bDtLger, sizeof(bool));

	int nNetTimeout = SOCKET_TIME_OUT;
	::setsockopt(_sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&nNetTimeout, sizeof(int));
	::setsockopt(_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&nNetTimeout, sizeof(int));

	int nBufSize = SOCKET_BUFFER_SIZE;
	::setsockopt(_sock, SOL_SOCKET, SO_SNDBUF, (const char*)&nBufSize, sizeof(int));
	::setsockopt(_sock, SOL_SOCKET, SO_RCVBUF, (const char*)&nBufSize, sizeof(int));
}

