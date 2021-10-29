#pragma once

#include "EndPoint.h"

#include <string>
#include <cstdint>

namespace sys
{
	class Socket
	{
	public:
		Socket();
		Socket(int32_t sock);
		~Socket();
	public:
		// ����socketģ������
		static void InitSockModule();
		// ����socketģ������
		static void ReleaseSockModule();

		// ��ip�Ͷ˿�
		void bind(const std::string& addr, int32_t port, bool ipv6 = false);
		// �������ȴ���
		void listen(int32_t maxCount);
		// ���յ��µ�����
		Socket* accept();
		// ���ӵ�Զ�̷����
		bool connect(const std::string& addr, int32_t port, bool ipv6 = false);
		// ������Ϣ
		int32_t write(const char* data, int32_t size);
		/** 
		*	������Ϣ
		*	-1 �ȴ����ж��Ƿ������д�
		*	0 �Ͽ�����
		*	����0�� ���յ�����
		*/
		char* read(int32_t& size);
		// �ر�ָ��Socket IO
		void shutDown(int32_t type);
		// �Ƿ���������
		bool hasError() const;
		// �ر�socket
		void close();
		// ��ȡsocketID
		int32_t getID() const;

		// ��ȡ����ip
		const std::string& getLocalIP() const;
		// ��ȡ���ض˿�
		int32_t getLocalPort() const;
		// ��ȡԶ��ip
		const std::string& getRemoteIP() const;
		// ��ȡԶ�̶˿�
		int32_t getRemotePort() const;
	protected:
		// ��ʼ��Ĭ��socket����
		// �Ƕ���
		void initDefaultOPT();
		// ��ʼ�����غ�Զ����Ϣ
		void initLocalAndRemote();
	private:
		// socket id
		int32_t _sock;
		// ���ص�ַ�Ͷ˿���Ϣ
		EndPoint _localEP;
		// Զ�̵�ַ�Ͷ˿���Ϣ
		EndPoint _remoteEP;
	};
}