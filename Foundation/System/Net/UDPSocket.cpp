#include "UDPSocket.h"
#include "Base/macros.h"
#include "EndPoint.h"
#include "DNS.h"

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
#define	SOCKET_DATA_SIZE 1024
// IO 缓存大小
#define SOCKET_BUFFER_SIZE 1024
// 超时时间（单位：毫秒）
#define SOCKET_TIME_OUT 5000

sys::UDPSocket::UDPSocket()
{
	_sock = ::socket(AF_INET, SOCK_DGRAM, 0);
	if (_sock == sys::SocketModule::INVALID_SOCKET_VALUE) return;

	this->initDefaultOPT();
}

sys::UDPSocket::~UDPSocket()
{
	close();
}

void sys::UDPSocket::bind(const std::string& addr, int32_t port, bool ipv6)
{
	_localEP = EndPoint(addr, port, ipv6);
	struct sockaddr_in server;
	EndPoint point32(addr, port, ipv6);
	point32.getAddr(&server);
	int svrSize = sizeof(server);
	int32_t result = ::bind(_sock, (struct sockaddr*)&server, svrSize);

#if _DEBUG
	PRINT("TCPSocket Bind Result, code:%d\n", result);
#endif
}

void sys::UDPSocket::setRemote(const std::string& addr, int32_t port, bool ipv6)
{
	_remoteEP = EndPoint(addr, port, ipv6);
}

void sys::UDPSocket::close()
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

int32_t sys::UDPSocket::write(const char* data, int32_t size)
{
	struct sockaddr_in server;
	_remoteEP.getAddr(&server);
	int svrSize = sizeof(server);
	return ::sendto(_sock, data, size, 0, (struct sockaddr*)&server, svrSize);
}

char* sys::UDPSocket::read(int32_t& size)
{
	static char s_recvData[SOCKET_DATA_SIZE] = { 0 };
	memset(s_recvData, 0, SOCKET_DATA_SIZE);

	struct sockaddr_in client;
	int clientSize = sizeof(client);
	size = ::recvfrom(_sock, s_recvData, SOCKET_DATA_SIZE - 1, 0, (struct sockaddr*)&client, &clientSize);
#if _DEBUG
	if (size > 0)
	{
		PRINT("%s", s_recvData);
	}
#endif
	return s_recvData;
}

bool sys::UDPSocket::hasError() const
{
#ifdef _WIN32
	int32_t error = ::WSAGetLastError();
	if (error != WSAEWOULDBLOCK)
	{
		return true;
	}
#else
	int32_t err = errno;
	if (err != EINPROGRESS && err != EAGAIN)
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

const std::string& sys::UDPSocket::getLocalIP() const
{
	return _localEP.addr;
}

int32_t sys::UDPSocket::getLocalPort() const
{
	return _localEP.port;
}

const std::string& sys::UDPSocket::getRemoteIP() const
{
	return _remoteEP.addr;
}

int32_t sys::UDPSocket::getRemotePort() const
{
	return _remoteEP.port;
}

void sys::UDPSocket::initDefaultOPT()
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