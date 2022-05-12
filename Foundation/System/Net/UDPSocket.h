#pragma once

#include "EndPoint.h"
#include "SocketModule.h"
#include <string>
#include <cstdint>

namespace sys
{
	/**
	*	udp
	*/
	class UDPSocket
	{
	public:
		UDPSocket();
		~UDPSocket();
	public:
		// ��ip�Ͷ˿�
		void bind(const std::string& addr, int32_t port, bool ipv6 = false);
		// ����Զ����Ϣ
		void setRemote(const std::string& addr, int32_t port, bool ipv6 = false);
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
	private:
		// socket id
		int32_t _sock = sys::SocketModule::INVALID_SOCKET_VALUE;
		// ���ص�ַ�Ͷ˿���Ϣ
		EndPoint _localEP;
		// Զ�̵�ַ�Ͷ˿���Ϣ
		EndPoint _remoteEP;
	};
}