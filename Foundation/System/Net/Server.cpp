#include "Server.h"

using namespace sys;


Server::Server()
{
	_socket = new Socket();
	_socket-> bind(DEFAULT_IP, DEFAULT_PORT);
	_socket->listen(1);
}

Server::Server( const char* ip, int32 port, int32 backlog )
{
	_socket = new Socket();
	_socket-> bind(ip, port);
	_socket->listen(backlog);
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
	Socket* socket = _socket->accept();
	if (socket)
	{
		this->addClient(socket);
		PRINT("client %s:%d connect\n", socket->getRemoteIP(), socket->getRemotePort());
	}

	// disabled socket
	std::vector<int32> removedSocks;

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

void Server::setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_closeHandler.first = target;
	_closeHandler.second = handler;
}

void Server::sendMessage( int32 id, NetData* data )
{
	this->addSendBuffer(id, data);
}

void Server::sendBroadcast(NetData* data)
{
	if (data == nullptr)
	{
		return;
	}
	std::map<int32, DataQueue*>::iterator it = _sendDatas.begin();
	while (it != _sendDatas.end())
	{
		NetData* temp = new NetData(data->data, data->size);
		it->second->pushData(temp);
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

	int32 sockId = sock->getID();

	_clients[sockId] = sock;

	if (_recvDatas.find(sockId) == _recvDatas.end())
	{
		_recvDatas[sockId] = new DataQueue();
	}
	
	if (_sendDatas.find(sockId) == _sendDatas.end())
	{
		DataQueue data2;
		_sendDatas[sockId] = new DataQueue();
	}
}

void Server::removeClient( int32 sockId )
{
	_clients.erase(sockId);
	if (_recvDatas.find(sockId) != _recvDatas.end())
	{
		delete _recvDatas[sockId];
		_recvDatas.erase(sockId);
	}
	
	if (_sendDatas.find(sockId) != _sendDatas.end())
	{
		delete _sendDatas[sockId];
		_sendDatas.erase(sockId);
	}

	if (this->_closeHandler.first && this->_closeHandler.second)
	{
		(this->_closeHandler.first->*this->_closeHandler.second)(sockId);
	}
}

void Server::removeAllClients()
{
	std::map<int32, Socket*>::iterator it = _clients.begin();

	while (it != _clients.end())
	{
		SAFE_DELETE(it->second);
		it++;
	}

	_clients.clear();
	_recvDatas.clear();
	_sendDatas.clear();
}

void Server::addRecvBuffer( int32 id, NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	if (_recvDatas.find(id) != _recvDatas.end())
	{
		_recvDatas[id]->pushData(data);
	}
	else
	{
		delete data;
	}
}

void Server::addSendBuffer( int32 id, NetData* data )
{
	if (data == nullptr)
	{
		return;
	}

	if (_sendDatas.find(id) != _sendDatas.end())
	{
		_sendDatas[id]->pushData(data);
	}
	else
	{
		delete data;
	}
}

void Server::onRecvHandler( int32 id, NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	this->addRecvBuffer(id, data);
}

void Server::_recvData( std::vector<int32>& removedSocks )
{
	int32 size;

	for (std::map<int32, Socket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		size = 0;
		Socket* socket = it->second;
		char* buff = socket->read(size);
		if (size == -1)
		{// 等待
			if (socket->hasError() == true)
			{
				int32 sockId = socket->getID();
				removedSocks.push_back(sockId);
			}
		}
		else if (size == 0)
		{// 断开连接
			int32 sockId = socket->getID();
			removedSocks.push_back(sockId);
		}
		else if (size > 0)
		{// 接收到数据
			this->onRecvHandler(socket->getID(), new NetData(buff, size));
		}
	}
}

void Server::_removeSockets( std::vector<int32>& removedSocks )
{
	for (std::vector<int32>::iterator it = removedSocks.begin();
		it != removedSocks.end();
		it++)
	{
		int32 sockId = (*it);
		Socket* socket = _clients[sockId];
		this->removeClient(sockId);
		if (socket)
		{
			PRINT("client %s:%d disconnect\n", socket->getRemoteIP(), socket->getRemotePort());
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
	int32 size;

	for (std::map<int32, Socket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		size = 0;

		int32 sockId = it->first;

		NetData* data = _sendDatas[sockId]->topData();
		if (data)
		{
			Socket* socket = _clients[sockId];
			size = socket->write(data->data + data->pos, data->size - data->pos);
			if (size > 0)
			{
				data->pos = data->pos + size;
				if (data->pos >= data->size)
				{
					SAFE_DELETE(data);
					_sendDatas[sockId]->popData();
				}
			}
		}
	}
}

void Server::_flushRecvData()
{
	int32 id;

	for (std::map<int32, Socket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		id = it->first;
		if (this->_recvHandler.first && this->_recvHandler.second)
		{
			if (this->_recvDatas.find(id) != this->_recvDatas.end() && !this->_recvDatas[id]->empty())
			{
				(this->_recvHandler.first->*this->_recvHandler.second)(id, *this->_recvDatas[id]);
			}
		}
	}
}
