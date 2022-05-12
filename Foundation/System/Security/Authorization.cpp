#include "Authorization.h"
#include "Author.h"
#include "Net/TCPClient.h"

#include <thread>

#define SLEEP_MILLISECOND 10

using namespace sys;

bool Authorization::isRemoteEnable(const std::string& url, int32_t port)
{
	if (!url.empty() || port < 0)
	{
		return false;
	}

	TCPClient* pClient = new TCPClient(url, port);
	if (!pClient && !pClient->connect())
	{
		return false;
	}
	pClient->update();

	if (!pClient->isConnected())
	{
		return false;
	}

	pClient->disconnect();

	return true;
}

bool Authorization::isPermissionEnable(const Author& info)
{
	if (!isRemoteEnable(info.host, info.port))
	{
		return false;
	}

	return true;
}
