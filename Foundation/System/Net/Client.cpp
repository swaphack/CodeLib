#include "Client.h"

using namespace sys;


Client::Client( const char* ip, int port )
{
	_socket = new Socket();
	_socket->Connect(ip, port);
}

Client::~Client()
{
	SAFE_DELETE(_socket);
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

	_recvHandler.target = target;
	_recvHandler.hander = handler;
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
	_recvDatas.push(data);
}

void Client::addSendBuffer( NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	_sendDatas.push(data);
}

void Client::onRecvHandler( NetData* data )
{
	if (data == nullptr)
	{
		return;
	}
	this->addRecvBuffer(data);

	if (! this->_recvHandler.empty())
	{
		this->_recvHandler.hand(this->_recvDatas);	
	}
}

void Client::_recvData()
{
	int size;
	char* buff = _socket->Recv(size);
	if (size == -1)
	{
		if (_socket->HasError() == true)
		{
			_socket->Close();
			return;
		}
	}
	else
	{
		this->onRecvHandler(new NetData(buff, size));
	}
}

void Client::_flushData()
{
	int size;
	NetData* data = _sendDatas.top();
	if (data)
	{
		size = _socket->Send(data->data + data->pos, data->size - data->pos);
		if (size > 0)
		{
			data->pos = data->pos + size;
			if (data->pos >= data->size)
			{
				_sendDatas.pop();
				SAFE_DELETE(data);
			}
		}
	}
}