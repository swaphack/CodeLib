#include "Client.h"
#include "Socket.h"
#include "Framework/Object.h"
#include "NetData.h"
#include "Base/macros.h"

using namespace sys;


Client::Client( const std::string& ip, int32_t port )
:_bConnected(false)
{
	_socket = new Socket();
	_ID = _socket->getID();
	this->setRemote(ip, port);
}

Client::~Client()
{
	SAFE_DELETE(_socket);
}

int32_t Client::getID()
{
	return _ID;
}

void Client::setRemote(const std::string& ip, int32_t port)
{
	_remote.first = ip;
	_remote.second = port;
}
bool Client::connect()
{
	bool result = _socket->connect(_remote.first, _remote.second);
	_bConnected = result;
	return _bConnected;
}

bool Client::disconnect()
{
	if (this->_closeHandler.first && this->_closeHandler.second)
	{
		(this->_closeHandler.first->*this->_closeHandler.second)(getID());
	}
	if (this->_closeFunc)
	{
		this->_closeFunc(getID());
	}
	_socket->close();
	_bConnected = false;
	return true;
}

bool Client::isConnected()
{
	return _bConnected;
}

void Client::update()
{
	this->_recvData();

	this->_flushData();
}

void Client::setRecvHandler( Object* target, CLIENT_RECV_HANDLER handler )
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_recvHandler.first = target;
	_recvHandler.second = handler;
}

void Client::setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler)
{
	if (target == nullptr || handler == nullptr)
	{
		return;
	}

	_closeHandler.first = target;
	_closeHandler.second = handler;
}

void Client::sendMessage(NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	this->addSendBuffer(data);
}

void Client::sendString(const std::string& data)
{
	if (data.empty())
	{
		return;
	}

	this->sendMessage(new NetData(data));
}

void Client::addRecvBuffer( NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	_recvDatas.pushData(data);
}

void Client::addSendBuffer( NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	_sendDatas.pushData(data);
}

void Client::onRecvHandler( NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	this->addRecvBuffer(data);
}

void Client::_recvData()
{
	int32_t size;
	char* buff = _socket->read(size);
	if (size == -1)
	{// 等待
		if (_socket->hasError() == true)
		{
			this->disconnect();
		}
	}
	else if (size == 0)
	{// 断开连接
		this->disconnect();
	}
	else
	{// 接收到数据
		this->onRecvHandler(new NetData(buff, size));
	}
}

void Client::_flushData()
{
	// 发送数据
	int32_t size;
	NetData* data = _sendDatas.topData();
	if (data)
	{
		size = _socket->write(data->getCursorPtr(), data->getRemainSize());
		if (size > 0)
		{
			data->pos = data->pos + size;
			if (data->pos >= data->getSize())
			{
				SAFE_DELETE(data);
				_sendDatas.popData();
			}
		}
	}

	processRecvData();
	
}

void Client::setRecvFunc(ClientRecvFunc func)
{
	_recvFunc = func;
}

void Client::setCloseFunc(ClientCloseFunc func)
{
	_closeFunc = func;
}

void Client::processRecvData()
{
	if (this->_recvDatas.empty())
	{
		return;
	}

	if (this->_recvHandler.first && this->_recvHandler.second)
	{
		(this->_recvHandler.first->*this->_recvHandler.second)(_socket->getID(), this->_recvDatas);
	}

	if (this->_recvFunc)
	{
		this->_recvFunc(_socket->getID(), this->_recvDatas);
	}
}
