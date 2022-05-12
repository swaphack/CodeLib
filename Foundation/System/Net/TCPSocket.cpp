#include "TCPSocket.h"
#include "EndPoint.h"
#include "DNS.h"
#include "Base/macros.h"
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


// 接收数据大小
#define	SOCKET_DATA_SIZE 32 * 1024
// IO 缓存大小
#define SOCKET_BUFFER_SIZE 1024 * 1024
// 超时时间（单位：毫秒）
#define SOCKET_TIME_OUT 5000


using namespace sys;

TCPSocket::TCPSocket()
{
	_sock = ::socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == sys::SocketModule::INVALID_SOCKET_VALUE) return;
	this->initDefaultOPT();
}

TCPSocket::TCPSocket(int32_t sock)
{
	_sock = sock;

	this->initDefaultOPT();

	initLocalAndRemote();
}

TCPSocket::~TCPSocket()
{
	close();
}



int32_t TCPSocket::getID() const
{
	return _sock;
}

void TCPSocket::bind(const std::string& addr, int32_t port, bool ipv6)
{
	struct sockaddr_in addrSrv;  
	EndPoint point32(addr, port, ipv6);
	point32.getAddr(&addrSrv);
	int svrSize = sizeof(addrSrv);
	int32_t result = ::bind(_sock, (struct sockaddr*)&addrSrv, svrSize);
	if (result >= 0)
	{
		_localEP = EndPoint::loadLocalSocket(_sock);
	}

#if _DEBUG
	PRINT("TCPSocket Bind Result, code:%d\n", result);
#endif
}

void TCPSocket::listen(int32_t maxCount)
{
	int32_t result = ::listen(_sock, maxCount);
#if _DEBUG
	PRINT("TCPSocket Listen Result, code:%d\n", result);
#endif
}

TCPSocket* TCPSocket::accept()
{
	struct sockaddr_in addrClient;  
	int32_t len = sizeof(addrClient);
	SOCKET sock = ::accept(_sock, (struct sockaddr*)&addrClient, &len);
	if (sock == sys::SocketModule::INVALID_SOCKET_VALUE)
	{
		return nullptr;
	}
	
	return new TCPSocket(sock);
}

bool TCPSocket::connect(const std::string& addr, int32_t port, bool ipv6)
{
	struct sockaddr_in addrSrv;
	EndPoint point32(addr, port, ipv6);
	point32.getAddr(&addrSrv);
	int svrSize = sizeof(addrSrv);
	bool result = ::connect(_sock, (struct sockaddr*)&addrSrv, svrSize) == 0;
	if (result >= 0)
	{
		_remoteEP = EndPoint::loadPeerSocket(_sock);
	}

	return result;
}

void TCPSocket::close()
{
	if (_sock != sys::SocketModule::INVALID_SOCKET_VALUE)
	{
		::closesocket(_sock);
#if _DEBUG
		PRINT("TCPSocket close %d\n", _sock);
#endif
	}

	_sock = sys::SocketModule::INVALID_SOCKET_VALUE;
}

int32_t TCPSocket::write(const char* data, int32_t size)
{
	return ::send(_sock, data, size, 0);
}

char* TCPSocket::read( int32_t& size )
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

void TCPSocket::shutDown( int32_t type )
{
	::shutdown(_sock, type);
}

bool TCPSocket::hasError() const
{
#ifdef _WIN32
	int32_t error = ::WSAGetLastError();
	if (error != WSAEWOULDBLOCK) 
	{
		return true;
	}
#else
	int32_t err = errno;
	if(err != EINPROGRESS && err != EAGAIN) 
	{
		return true;
	}
#endif
	if (_sock == sys::SocketModule::INVALID_SOCKET_VALUE)
	{
		return true;
	}
	return false;
}

const std::string& TCPSocket::getLocalIP() const
{
	return _localEP.addr;
}

int32_t TCPSocket::getLocalPort() const
{
	return _localEP.port;
}

const std::string& TCPSocket::getRemoteIP() const
{
	return _remoteEP.addr;
}

int32_t TCPSocket::getRemotePort() const
{
	return _remoteEP.port;
}

void TCPSocket::initDefaultOPT()
{
	//non-blocking mode is enabled.
#ifdef _WIN32
	u_long iMode = 1;
	::ioctlsocket(_sock, FIONBIO, &iMode);
#else
	int32_t flags = fcntl(_sock, F_GETFL, 0); 
	fcntl(_sock, F_SETFL, flags | O_NONBLOCK);
#endif 	

	bool bDtLger = false;
	::setsockopt(_sock, SOL_SOCKET, SO_DONTLINGER, (const char*)&bDtLger, sizeof(bool));

	int32_t nNetTimeout = SOCKET_TIME_OUT;
	::setsockopt(_sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&nNetTimeout, sizeof(int32_t));
	::setsockopt(_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&nNetTimeout, sizeof(int32_t));

	int32_t nBufSize = SOCKET_BUFFER_SIZE;
	::setsockopt(_sock, SOL_SOCKET, SO_SNDBUF, (const char*)&nBufSize, sizeof(int32_t));
	::setsockopt(_sock, SOL_SOCKET, SO_RCVBUF, (const char*)&nBufSize, sizeof(int32_t));

	_localEP.addr = "";
	_localEP.port = 0;

	_remoteEP.addr = "";
	_remoteEP.port = 0;
}

void TCPSocket::initLocalAndRemote()
{
	if (_sock == sys::SocketModule::INVALID_SOCKET_VALUE)
	{
		return;
	}

	_localEP = EndPoint::loadLocalSocket(_sock);
	_remoteEP = EndPoint::loadPeerSocket(_sock);
}
