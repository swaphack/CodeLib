#pragma once

#include "macros.h"
#include "Base/Types.h"
#include "EndPoint.h"

namespace sys
{
	class Socket
	{
	public:
		Socket();
		Socket(int32 sock);
		~Socket();
	public:
		// ����socketģ������
		static void InitSockModule();
		// ����socketģ������
		static void ReleaseSockModule();

		// ��ip�Ͷ˿�
		void bind(const char* addr, int32 port, bool ipv6 = false);
		// �������ȴ���
		void listen(int32 maxCount);
		// ���յ��µ�����
		Socket* accept();
		// ���ӵ�Զ�̷����
		bool connect(const char* addr, int32 port, bool ipv6 = false);
		// ������Ϣ
		int32 write(const char* data, int32 size);
		/** 
		*	������Ϣ
		*	-1 �ȴ����ж��Ƿ������д�
		*	0 �Ͽ�����
		*	����0�� ���յ�����
		*/
		char* read(int32& size);
		// �ر�ָ��Socket IO
		void shutDown(int32 type);
		// �Ƿ���������
		bool hasError();
		// �ر�socket
		void close();
		// ��ȡsocketID
		int32 getID();

		// ��ȡ����ip
		const char* getLocalIP();
		// ��ȡ���ض˿�
		int32 getLocalPort();
		// ��ȡԶ��ip
		const char* getRemoteIP();
		// ��ȡԶ�̶˿�
		int32 getRemotePort();
	protected:
		// ��ʼ��Ĭ��socket����
		// �Ƕ���
		void initDefaultOPT();
		// ��ʼ�����غ�Զ����Ϣ
		void initLocalAndRemote();
	private:
		// socket id
		int32 _sock;
		// ���ص�ַ�Ͷ˿���Ϣ
		EndPoint _localEP;
		// Զ�̵�ַ�Ͷ˿���Ϣ
		EndPoint _remoteEP;
	};
}