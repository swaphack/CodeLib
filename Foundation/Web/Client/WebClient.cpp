#include "WebClient.h"

using namespace web;

WebClient::WebClient()
{

}

WebClient::~WebClient()
{
	this->removeAllClients();
}

sys::Client* WebClient::createClient(const char* ip, int port)
{
	if (ip == nullptr || port < 0)
	{
		return nullptr;
	}
	sys::Client* pClient = new sys::Client(ip, port);
	if (pClient == nullptr)
	{
		return nullptr;
	}
	pClient->connect();
	pClient->setRecvHandler(_recvHandler.first, _recvHandler.second);
	pClient->setCloseHandler(_closeHandler.first, _closeHandler.second);

	_clients[pClient->getID()] = pClient;

	return pClient;
}

sys::Client* WebClient::getClient(int id)
{
	std::map<int, sys::Client*>::iterator iter = _clients.find(id);
	if (iter != _clients.end())
	{
		return iter->second;
	}
	return nullptr;
}

void WebClient::closeClient(int id)
{
	std::map<int, sys::Client*>::iterator iter = _clients.find(id);
	if (iter != _clients.end())
	{
		iter->second->disconnect();
		delete iter->second;
		_clients.erase(iter);
	}
}

void WebClient::removeAllClients()
{
	std::map<int, sys::Client*>::iterator iter = _clients.begin();
	while (iter != _clients.end())
	{
		iter->second->disconnect();
		delete iter->second;
		iter++;
	}

	_clients.clear();
}

void WebClient::setRecvHandler(sys::Object* target, sys::CLIENT_RECV_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_recvHandler.first = target;
	_recvHandler.second = handler;
}

void WebClient::setCloseHandler(sys::Object* target, sys::CLIENT_CLOSE_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_closeHandler.first = target;
	_closeHandler.second = handler;
}

void WebClient::update()
{
	std::vector<int> clientIDs;

	std::map<int, sys::Client*>::iterator iter = _clients.begin();
	while (iter != _clients.end())
	{
		iter->second->update();
		if (!iter->second->isConnected())
		{
			clientIDs.push_back(iter->first);
		}
		iter++;
	}

	for (int i = 0; i < clientIDs.size(); i++)
	{
		this->closeClient(clientIDs[i]);
	}
}
