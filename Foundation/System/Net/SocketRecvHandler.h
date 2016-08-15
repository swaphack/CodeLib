#pragma once

#include "../Framework/Object.h"
#include "DataQueue.h"

namespace sys
{
	// ����˴���������ݵĺ���ָ��
	typedef void (Object::*SERVER_RECV_HANDLER)(int id, DataQueue& data);
	// ����˽������ݵĴ�����
	typedef std::pair<Object*, SERVER_RECV_HANDLER> ServerRecvHandler;

	// �ͻ��˴���������ݵĺ���ָ��
	typedef void (Object::*CLIENT_RECV_HANDLER)(int id, DataQueue& data);
	// �ͻ��˽������ݵĴ�����
	typedef std::pair<Object*, CLIENT_RECV_HANDLER> ClientRecvHandler;
}