#pragma once

#include "EndPoint.h"
#include "SocketModule.h"
#include <string>
#include <cstdint>

namespace sys
{
	/**
	*	tcp
	*/
	class TCPSocket
	{
	public:
		TCPSocket();
		TCPSocket(int32_t sock);
		~TCPSocket();
	public:
		// ��ȡsocketID
		int32_t getID() const;
	public:
		// ��ip�Ͷ˿�
		void bind(const std::string& addr, int32_t port, bool ipv6 = false);
		// �������ȴ���
		void listen(int32_t maxCount);
		// ���յ��µ�����
		TCPSocket* accept();
	public:
		// ���ӵ�Զ�̷����
		bool connect(const std::string& addr, int32_t port, bool ipv6 = false);
		// �ر�socket
		void close();
	public:
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
	public:
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
		int32_t _sock = sys::SocketModule::INVALID_SOCKET_VALUE;
		// ���ص�ַ�Ͷ˿���Ϣ
		EndPoint _localEP;
		// Զ�̵�ַ�Ͷ˿���Ϣ
		EndPoint _remoteEP;
	};
}