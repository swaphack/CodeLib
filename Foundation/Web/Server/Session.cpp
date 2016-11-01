#include "Session.h"

using namespace web;

Sessions::Sessions()
{

}

Sessions::~Sessions()
{
	this->removeAllSessions();
}

void Sessions::addSession(const char* sessionID, const ClientSession& client)
{
	if (sessionID == nullptr)
	{
		return;
	}

	_clientSessions[sessionID] = client;
}

ClientSession* Sessions::getSession(const char* sessionID)
{
	if (sessionID == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, ClientSession>::iterator iter = _clientSessions.find(sessionID);
	if (iter == _clientSessions.end())
	{
		return nullptr;
	}

	return &iter->second;
}

ClientSession* Sessions::getSession(int clientID)
{
	std::map<std::string, ClientSession>::iterator iter = _clientSessions.begin();
	while (iter == _clientSessions.end())
	{
		if (iter->second.clientID == clientID)
		{
			return &iter->second;
		}
		iter++;
	}

	return nullptr;
}

void Sessions::removeSession(const char* sessionID)
{
	if (sessionID == nullptr)
	{
		return;
	}

	_clientSessions.erase(sessionID);
}

void Sessions::removeClient(int clientID)
{
	std::map<std::string, ClientSession>::iterator iter = _clientSessions.begin();
	while (iter == _clientSessions.end())
	{
		if (iter->second.clientID == clientID)
		{
			_clientSessions.erase(iter);
			break;
		}
		iter++;
	}
}

void Sessions::removeAllSessions()
{
	_clientSessions.clear();
}