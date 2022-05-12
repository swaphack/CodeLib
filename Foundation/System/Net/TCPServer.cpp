#include "TCPServer.h"
#include "Framework/Object.h"
#include "TCPSocket.h"
#include "NetData.h"
#include "Base/macros.h"

using namespace sys;


TCPServer::TCPServer()
{
	_socket = new TCPSocket();
	_socket-> bind(DEFAULT_IP, DEFAULT_PORT);
	_socket->listen(1);
}

TCPServer::TCPServer( const std::string& ip, int32_t port, int32_t backlog )
{
	_socket = new TCPSocket();
	_socket-> bind(ip, port);
	_socket->listen(backlog);
}

TCPServer::~TCPServer()
{
	this->removeAllClients();
	SAFE_DELETE(_socket);
}

void TCPServer::update()
{
	if (_socket == nullptr)
	{
		return;
	}
	TCPSocket* socket = _socket->accept();
	if (socket)
	{
		this->addClient(socket);
		PRINT("client %s:%d connect\n", socket->getRemoteIP().c_str(), socket->getRemotePort());
	}

	// disabled socket
	std::vector<int32_t> removedSocks;

	// recv data
	this->_recvData(removedSocks);

	// remove disabled socket
	this->_removeSockets(removedSocks);

	// send data
	this->_flushData();
}

void TCPServer::setRecvHandler( Object* target, SERVER_RECV_HANDLER handler )
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_recvHandler.first = target;
	_recvHandler.second = handler;
}

void TCPServer::setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_closeHandler.first = target;
	_closeHandler.second = handler;
}

void TCPServer::sendMessage( int32_t id, NetData* data )
{
	this->addSendBuffer(id, data);
}

void TCPServer::sendBroadcast(NetData* data)
{
	if (data == nullptr)
	{
		return;
	}
	std::map<int32_t, DataQueue*>::iterator it = _sendDatas.begin();
	while (it != _sendDatas.end())
	{
		NetData* temp = new NetData(*data);
		it->second->pushData(temp);
		it++;
	}

	delete data;
}

void TCPServer::addClient( TCPSocket* sock )
{
	if (sock == nullptr)
	{
		return;
	}

	int32_t sockId = sock->getID();

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

void TCPServer::removeClient( int32_t sockId )
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

	if (this->_closeFunc)
	{
		this->_closeFunc(sockId);
	}
}

void TCPServer::removeAllClients()
{
	std::map<int32_t, TCPSocket*>::iterator it = _clients.begin();

	while (it != _clients.end())
	{
		SAFE_DELETE(it->second);
		it++;
	}

	_clients.clear();
	_recvDatas.clear();
	_sendDatas.clear();
}

void TCPServer::addRecvBuffer( int32_t id, NetData* data )
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

void TCPServer::addSendBuffer( int32_t id, NetData* data )
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

void TCPServer::onRecvHandler( int32_t id, NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	this->addRecvBuffer(id, data);
}

void TCPServer::_recvData( std::vector<int32_t>& removedSocks )
{
	int32_t size;

	for (std::map<int32_t, TCPSocket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		size = 0;
		TCPSocket* socket = it->second;
		char* buff = socket->read(size);
		if (size == -1)
		{// 等待
			if (socket->hasError() == true)
			{
				int32_t sockId = socket->getID();
				removedSocks.push_back(sockId);
			}
		}
		else if (size == 0)
		{// 断开连接
			int32_t sockId = socket->getID();
			removedSocks.push_back(sockId);
		}
		else if (size > 0)
		{// 接收到数据
			this->onRecvHandler(socket->getID(), new NetData(buff, size));
		}
	}
}

void TCPServer::_removeSockets( std::vector<int32_t>& removedSocks )
{
	for (std::vector<int32_t>::iterator it = removedSocks.begin();
		it != removedSocks.end();
		it++)
	{
		int32_t sockId = (*it);
		TCPSocket* socket = _clients[sockId];
		this->removeClient(sockId);
		if (socket)
		{
			PRINT("client %s:%d disconnect\n", socket->getRemoteIP().c_str(), socket->getRemotePort());
			delete socket;
		}
	}
}

void TCPServer::_flushData()
{
	this->_flushSendData();
	this->_flushRecvData();
}

void TCPServer::_flushSendData()
{
	int32_t size;

	for (std::map<int32_t, TCPSocket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		size = 0;

		int32_t sockId = it->first;

		NetData* data = _sendDatas[sockId]->topData();
		if (data)
		{
			TCPSocket* socket = _clients[sockId];
			size = socket->write(data->getCursorPtr(), data->getRemainSize());
			if (size > 0)
			{
				data->pos = data->pos + size;
				if (data->pos >= data->getSize())
				{
					SAFE_DELETE(data);
					_sendDatas[sockId]->popData();
				}
			}
		}
	}
}

void TCPServer::_flushRecvData()
{
	int32_t id;

	for (std::map<int32_t, TCPSocket*>::iterator it = _clients.begin();
		it != _clients.end();
		it++)
	{
		id = it->first;
		if (this->_recvDatas.find(id) != this->_recvDatas.end() && !this->_recvDatas[id]->empty())
		{
			this->processRecvData(id);
		}
	}
}

void TCPServer::setRecvFunc(ServerRecvFunc func)
{
	_recvFunc = func;
}

void TCPServer::setCloseFunc(ClientCloseFunc func)
{
	_closeFunc = func;
}

void TCPServer::processRecvData(int32_t id)
{
	if (this->_recvHandler.first && this->_recvHandler.second)
	{
		(this->_recvHandler.first->*this->_recvHandler.second)(id, *this->_recvDatas[id]);
	}

	if (this->_recvFunc)
	{
		this->_recvFunc(id, *this->_recvDatas[id]);
	}
}
