#pragma once

#include "macros.h"

namespace sys
{
	// �������ݴ�С
	#define	SOCKET_DATA_SIZE 32 * 1024
	// IO �����С
	#define SOCKET_BUFFER_SIZE 1024 * 1024
	// ��ʱʱ�䣨��λ�����룩
	#define SOCKET_TIME_OUT 100

	class Socket
	{
	public:
		Socket();
		Socket(int sock);
		~Socket();
	public:
		// ����socketģ������������
		static void InitSockModule();
		static void ReleaseSockModule();

		// ��ip�Ͷ˿�
		void Bind(const char* addr, int port);
		// �������ȴ���
		void Listen(int maxCount);
		// ���յ��µ�����
		Socket* Accept();
		// ���ӵ�Զ�̷����
		bool Connect(const char* addr, int port);
		// ������Ϣ
		int Send(const char* data, int size);
		// ������Ϣ
		char* Recv(int& size);
		// �ر�ָ��Socket IO
		void ShutDown(int type);
		// �Ƿ���������
		bool HasError();
		// �ر�socket
		void Close();
		// ��ȡsocketID
		int getID();
	protected:
		// ��ʼ��Ĭ��socket����
		// �Ƕ���
		void initDefaultOPT();
	private:
		int _sock;
	};


}