#include "Authorization.h"
#include "Author.h"
#include "../Net/Client.h"

#include <thread>

#define SLEEP_MILLISECOND 10

using namespace sys;

bool Authorization::isRemoteEnable(const std::string& url, int port)
{
	if (!url.empty() || port < 0)
	{
		return false;
	}

	Client* pClient = new Client(url.c_str(), port);
	if (!pClient->connect())
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
	if (!isRemoteEnable(info.url, info.port))
	{
		return false;
	}

	return true;
}
