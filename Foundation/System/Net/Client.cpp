#include "Client.h"

using namespace sys;


Client::Client( const char* ip, int32 port )
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

int32 Client::getID()
{
	return _ID;
}

void Client::setRemote(const char* ip, int32 port)
{
	_remote.first = ip;
	_remote.second = port;
}
bool Client::connect()
{
	bool result = _socket->connect(_remote.first, _remote.second);
	_bConnected = true;
	return _bConnected;
}

bool Client::disconnect()
{
	if (this->_closeHandler.first && this->_closeHandler.second)
	{
		(this->_closeHandler.first->*this->_closeHandler.second)(getID());
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

void Client::sendString(const char* data)
{
	if (data == nullptr)
	{
		return;
	}

	this->sendMessage(new NetData(data, strlen(data)));
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
	int32 size;
	char* buff = _socket->read(size);
	if (size == -1)
	{// �ȴ�
		if (_socket->hasError() == true)
		{
			this->disconnect();
		}
	}
	else if (size == 0)
	{// �Ͽ�����
		this->disconnect();
	}
	else
	{// ���յ�����
		this->onRecvHandler(new NetData(buff, size));
	}
}

void Client::_flushData()
{
	// ��������
	int32 size;
	NetData* data = _sendDatas.topData();
	if (data)
	{
		size = _socket->write(data->data + data->pos, data->size - data->pos);
		if (size > 0)
		{
			data->pos = data->pos + size;
			if (data->pos >= data->size)
			{
				SAFE_DELETE(data);
				_sendDatas.popData();
			}
		}
	}

	// ������յ�����
	if (!this->_recvDatas.empty())
	{
		if (this->_recvHandler.first && this->_recvHandler.second)
		{
			(this->_recvHandler.first->*this->_recvHandler.second)(_socket->getID(), this->_recvDatas);
		}
	}
}