#pragma once

#include "Framework/Object.h"
#include "DataQueue.h"
#include <functional>

namespace sys
{
	// 服务端处理接收数据的函数指针
	typedef void (Object::*SERVER_RECV_HANDLER)(int32_t id, DataQueue& data);
	// 服务端接收数据的处理者
	typedef std::pair<Object*, SERVER_RECV_HANDLER> ServerRecvHandler;

	typedef std::function<void(int32_t id, DataQueue& data)> ServerRecvFunc;

	// 客户端处理接收数据的函数指针
	typedef void (Object::*CLIENT_RECV_HANDLER)(int32_t id, DataQueue& data);
	// 客户端接收数据的处理者
	typedef std::pair<Object*, CLIENT_RECV_HANDLER> ClientRecvHandler;

	typedef std::function<void(int32_t id, DataQueue& data)> ClientRecvFunc;

	// 客户端断开连接的函数指针
	typedef void (Object::*CLIENT_CLOSE_HANDLER)(int32_t id);
	// 客户端断开连接的处理者
	typedef std::pair<Object*, CLIENT_CLOSE_HANDLER> ClientCloseHandler;

	typedef std::function<void(int32_t id)> ClientCloseFunc;
}