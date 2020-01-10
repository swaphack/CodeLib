#pragma once

#include "Framework/Object.h"
#include "DataQueue.h"

namespace sys
{
	// ����˴���������ݵĺ���ָ��
	typedef void (Object::*SERVER_RECV_HANDLER)(int32_t id, DataQueue& data);
	// ����˽������ݵĴ�����
	typedef std::pair<Object*, SERVER_RECV_HANDLER> ServerRecvHandler;

	// �ͻ��˴���������ݵĺ���ָ��
	typedef void (Object::*CLIENT_RECV_HANDLER)(int32_t id, DataQueue& data);
	// �ͻ��˽������ݵĴ�����
	typedef std::pair<Object*, CLIENT_RECV_HANDLER> ClientRecvHandler;

	// �ͻ��˶Ͽ����ӵĺ���ָ��
	typedef void (Object::*CLIENT_CLOSE_HANDLER)(int32_t id);
	// �ͻ��˶Ͽ����ӵĴ�����
	typedef std::pair<Object*, CLIENT_CLOSE_HANDLER> ClientCloseHandler;
}