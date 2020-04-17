#pragma once

#include "Framework/Object.h"
#include "DataQueue.h"
#include <functional>

namespace sys
{
	// ����˴���������ݵĺ���ָ��
	typedef void (Object::*SERVER_RECV_HANDLER)(int32_t id, DataQueue& data);
	// ����˽������ݵĴ�����
	typedef std::pair<Object*, SERVER_RECV_HANDLER> ServerRecvHandler;

	typedef std::function<void(int32_t id, DataQueue& data)> ServerRecvFunc;

	// �ͻ��˴���������ݵĺ���ָ��
	typedef void (Object::*CLIENT_RECV_HANDLER)(int32_t id, DataQueue& data);
	// �ͻ��˽������ݵĴ�����
	typedef std::pair<Object*, CLIENT_RECV_HANDLER> ClientRecvHandler;

	typedef std::function<void(int32_t id, DataQueue& data)> ClientRecvFunc;

	// �ͻ��˶Ͽ����ӵĺ���ָ��
	typedef void (Object::*CLIENT_CLOSE_HANDLER)(int32_t id);
	// �ͻ��˶Ͽ����ӵĴ�����
	typedef std::pair<Object*, CLIENT_CLOSE_HANDLER> ClientCloseHandler;

	typedef std::function<void(int32_t id)> ClientCloseFunc;
}