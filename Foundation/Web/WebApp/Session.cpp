#include "Session.h"

using namespace web;

Sessions::Sessions()
{

}

Sessions::~Sessions()
{
	this->removeAllHtppClients();
}

void Sessions::addHttpClient(const char* sessionID, const ClientSession& client)
{
	if (sessionID == nullptr)
	{
		return;
	}

	_httpClients[sessionID] = client;
}

ClientSession* Sessions::getHttpClient(const char* sessionID)
{
	if (sessionID == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, ClientSession>::iterator it = _httpClients.find(sessionID);
	if (it == _httpClients.end())
	{
		return nullptr;
	}

	return &it->second;
}

void Sessions::removeHttpClient(const char* sessionID)
{
	if (sessionID == nullptr)
	{
		return;
	}

	_httpClients.erase(sessionID);
}

void Sessions::removeAllHtppClients()
{
	_httpClients.clear();
}