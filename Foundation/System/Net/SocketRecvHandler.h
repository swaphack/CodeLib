#pragma once

#include "../Framework/Object.h"
#include "DataQueue.h"

namespace sys
{
	// 服务端处理接收数据的函数指针
	typedef void (Object::*SERVER_RECV_HANDLER)(int id, DataQueue& data);
	// 服务端接收数据的处理者
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



	// 客户端处理接收数据的函数指针
	typedef void (Object::*CLIENT_RECV_HANDLER)(int id, DataQueue& data);
	// 客户端接收数据的处理者
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