#pragma once

#include "macros.h"
#include <map>
#include <string>

namespace sys
{
	class Socket
	{
	public:
		Socket();
		Socket(int sock);
		~Socket();
	public:
		// ����socketģ������
		static void InitSockModule();
		// ����socketģ������
		static void ReleaseSockModule();

		// ��ip�Ͷ˿�
		void Bind(const char* addr, int port, bool ipv6 = false);
		// �������ȴ���
		void Listen(int maxCount);
		// ���յ��µ�����
		Socket* Accept();
		// ���ӵ�Զ�̷����
		bool Connect(const char* addr, int port, bool ipv6 = false);
		// ������Ϣ
		int Send(const char* data, int size);
		/** 
		*	������Ϣ
		*	-1 �ȴ����ж��Ƿ������д�
		*	0 �Ͽ�����
		*	����0�� ���յ�����
		*/
		char* Recv(int& size);
		// �ر�ָ��Socket IO
		void ShutDown(int type);
		// �Ƿ���������
		bool HasError();
		// �ر�socket
		void Close();
		// ��ȡsocketID
		int getID();

		// ��ȡ����ip
		const char* getLocalIP();
		// ��ȡ���ض˿�
		int getLocalPort();
		// ��ȡԶ��ip
		const char* getRemoteIP();
		// ��ȡԶ�̶˿�
		int getRemotePort();
	protected:
		// ��ʼ��Ĭ��socket����
		// �Ƕ���
		void initDefaultOPT();
		// ��ʼ�����غ�Զ����Ϣ
		void initLocalAndRemote();
	private:
		// socket id
		int _sock;
		// ���ص�ַ�Ͷ˿���Ϣ
		std::pair<std::string, int> _localEP;
		// Զ�̵�ַ�Ͷ˿���Ϣ
		std::pair<std::string, int> _remoteEP;
	};


}