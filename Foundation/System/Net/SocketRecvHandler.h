#pragma once

#include "../Framework/Object.h"
#include "DataQueue.h"

namespace sys
{
	// ����˴���������ݵĺ���ָ��
	typedef void (Object::*SERVER_RECV_HANDLER)(int id, DataQueue& data);
	// ����˽������ݵĴ�����
	struct ServerRecvHandler
	{
		Object* target;
		SERVER_RECV_HANDLER hander;

		ServerRecvHandler():target(nullptr), hander(nullptr){}

		void hand(int id, DataQueue& data)
		{
			if (!empty())
				(target->*hander)(id, data);
		}

		bool empty() 
		{
			return target == nullptr || hander == nullptr;
		}

		void clean() 
		{ 
			target = nullptr; 
			hander = nullptr; 
		}
	};



	// �ͻ��˴���������ݵĺ���ָ��
	typedef void (Object::*CLIENT_RECV_HANDLER)(int id, DataQueue& data);
	// �ͻ��˽������ݵĴ�����
	struct ClientRecvHandler
	{
		Object* target;
		CLIENT_RECV_HANDLER hander;

		ClientRecvHandler():target(nullptr), hander(nullptr){}

		void hand(int id, DataQueue& data)
		{
			if (!empty())
				(target->*hander)(id, data);
		}

		bool empty() 
		{
			return target == nullptr || hander == nullptr;
		}

		void clean() 
		{ 
			target = nullptr; 
			hander = nullptr; 
		}
	};
}