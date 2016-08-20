#include "Server.h"

using namespace sys;


Server::Server()
{
	_socket = new Socket();
	_socket->Bind(DEFAULT_IP, DEFAULT_PORT);
	_socket->Listen(1);
}

Server::Server( const char* ip, int port, int backlog )
{
	_socket = new Socket();
	_socket->Bind(ip, port);
	_socket->Listen(backlog);
}

Server::~Server()
{
	this->removeAllClients();
	SAFE_DELETE(_socket);
}

void Server::update()
{
	if (_socket == nullptr)
	{
		return;
	}
	Socket* socket = _socket->Accept();
	if (socket)
	{
		this->addClient(socket);
		PRINT("connect socket %d\n", socket->getID());
	}

	// disabled socket
	std::vector<int> removedSocks;

	// recv data
	this->_recvData(removedSocks);

	// remove disabled socket
	this->_removeSockets(removedSocks);

	// send data
	this->_flushData();
}

void Server::setRecvHandler( Object* target, SERVER_RECV_HANDLER handler )
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_recvHandler.first = target;
	_recvHandler.second = handler;
}

void Server::sendMessage( int id, NetData* data )
{
	this->addSendBuffer(id, data);
}

void Server::sendBroadcast(NetData* data)
{
	if (data == nullptr)
	{
		return;
	}
	std::map<int, DataQueue>::iterator it = _sendDatas.begin();
	while (it != _sendDatas.end())
	{
		NetData* temp = new NetData(data->data, data->size);
		it->second.push(temp);
		it++;
	}

	delete data;
}

void Server::addClient( Socket* sock )
{
	if (sock == nullptr)
	{
		return;
	}

	int sockId = sock->getID();

	_clients[sockId] = sock;

	DataQueue data1;
	_recvDatas[sockId] = data1;

	DataQueue data2;
	_sendDatas[sockId] = data2;
}

void Server::removeClient( int sockId )
{
	_clients.erase(sockId);
	_recvDatas.erase(sockId);
	_sendDatas.erase(sockId);
}

void Server::removeAllClients()
{
	std::map<int, Socket*>::iterator it = _clients.begin();

	while (it != _clients.end())
	{
		SAFE_DELETE(it->second);
		it++;
	}

	_clients.clear();
	_recvDatas.clear();
	_sendDatas.clear();
}

void Server::addRecvBuffer( int id, NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	if (_recvDatas.find(id) != _recvDatas.end())
	{
		_recvDatas[id].push(data);
	}
	else
	{
		delete data;
	}
}

void Server::addSendBuffer( int id, NetData* data )
{
	if (data == nullptr)
	{
		return;
	}

	if (_sendDatas.find(id) != _sendDatas.end())
	{
		_sendDatas[id].push(data);
	}
	else
	{
		delete data;
	}
}

void Server::onRecvHandler( int id, NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	this->addRecvBuffer(id, data);
}

void Server::_recvData( std::vector<int>& removedSocks )
{
	int size;

	for (std::map<int, Socket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		size = 0;

		char* buff = it->second->Recv(size);
		if (size == -1)
		{// 等待
			Socket* socket = it->second;
			if (socket->HasError() == true)
			{
				int sockId = socket->getID();
				removedSocks.push_back(sockId);
			}
		}
		else if (size == 0)
		{// 断开连接
			Socket* socket = it->second;
			int sockId = socket->getID();
			removedSocks.push_back(sockId);
		}
		else if (size > 0)
		{// 接收到数据
			this->onRecvHandler(it->second->getID(), new NetData(buff, size));
		}
	}
}

void Server::_removeSockets( std::vector<int>& removedSocks )
{
	for (std::vector<int>::iterator it = removedSocks.begin();
		it != removedSocks.end();
		it++)
	{
		int sockId = (*it);
		Socket* socket = _clients[sockId];
		this->removeClient(sockId);
		if (socket)
		{
			PRINT("disconnect socket %d\n", socket->getID());
			delete socket;
		}
	}
}

void Server::_flushData()
{
	this->_flushSendData();
	this->_flushRecvData();
}

void Server::_flushSendData()
{
	int size;

	for (std::map<int, Socket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		size = 0;

		int sockId = it->first;

		NetData* data = _sendDatas[sockId].top();
		if (data)
		{
			Socket* socket = _clients[sockId];
			size = socket->Send(data->data + data->pos, data->size - data->pos);
			if (size > 0)
			{
				data->pos = data->pos + size;
				if (data->pos >= data->size)
				{
					_sendDatas[sockId].pop();
					SAFE_DELETE(data);
				}
			}
		}
	}
}

void Server::_flushRecvData()
{
	int id;

	for (std::map<int, Socket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		id = it->first;
		if (this->_recvHandler.first && this->_recvHandler.second)
		{
			if (this->_recvDatas.find(id) != this->_recvDatas.end() && !this->_recvDatas[id].empty())
			{
				(this->_recvHandler.first->*this->_recvHandler.second)(id, this->_recvDatas[id]);
			}
		}
	}
}
