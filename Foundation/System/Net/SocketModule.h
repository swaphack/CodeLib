#pragma once

namespace sys
{

	class SocketModule
	{
	public:
		// ������socketֵ
		const static int INVALID_SOCKET_VALUE;
	public:
		// ����socketģ������
		static void InitSockModule();
		// ����socketģ������
		static void ReleaseSockModule();
	};
}