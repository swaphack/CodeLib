#pragma once

namespace sys
{

	class SocketModule
	{
	public:
		// 不可用socket值
		const static int INVALID_SOCKET_VALUE;
	public:
		// 用于socket模块启动
		static void InitSockModule();
		// 用于socket模块销毁
		static void ReleaseSockModule();
	};
}