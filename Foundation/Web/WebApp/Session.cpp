#include "Session.h"

using namespace web;

Session::Session()
{

}

Session::~Session()
{
	this->removeAllHtppClients();
}

void Session::addHttpClient(const char* sessionID, const HttpClient& client)
{
	if (sessionID == nullptr)
	{
		return;
	}

	_httpClients[sessionID] = client;
}

HttpClient* Session::getHttpClient(const char* sessionID)
{
	if (sessionID == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, HttpClient>::iterator it = _httpClients.find(sessionID);
	if (it == _httpClients.end())
	{
		return nullptr;
	}

	return &it->second;
}

void Session::removeHttpClient(const char* sessionID)
{
	if (sessionID == nullptr)
	{
		return;
	}

	_httpClients.erase(sessionID);
}

void Session::removeAllHtppClients()
{
	_httpClients.clear();
}