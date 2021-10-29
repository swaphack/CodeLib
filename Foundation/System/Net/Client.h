#pragma once

#include "DataQueue.h"
#include "SocketRecvHandler.h"
#include <cstdint>
#include <string>
#include <map>

namespace sys
{
	class Object;
	class Socket;

	class Client
	{
	public:
		Client(const std::string& ip, int32_t port);
		virtual ~Client();
	public:
		int32_t getID() const;
		// ����Զ����Ϣ
		void setRemote(const std::string& ip, int32_t port);
		// ���ӷ�����
		bool connect();
		// �Ͽ�����
		bool disconnect();
		// �Ƿ����ӳɹ�
		bool isConnected() const;
		/*
		 * ����
		 * ��������
		 * ��������
		 */
		void update();
		// ���ý��յ�����ʱ�Ĵ���
		void setRecvHandler(Object* target, CLIENT_RECV_HANDLER handler);
		void setRecvFunc(ClientRecvFunc func);
		// ���ÿͻ��˶Ͽ�ʱ�Ĵ���
		void setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler);
		void setCloseFunc(ClientCloseFunc func);
		// ������Ϣ, ʹ��new��������Ϻ���Զ��ͷ�
		void sendMessage(NetData* data);
		// ������Ϣ
		void sendString(const std::string& data);
	protected:
		// ��ӽ��յ�������
		void addRecvBuffer(NetData* data);
		// ��Ӵ����͵�����
		void addSendBuffer(NetData* data);
		// ��������ʱ����
		void onRecvHandler(NetData* data);
	private:
		// �������ݣ����Ҵ洢�Ͽ���socket����
		void _recvData();
		// ������Ϣ
		void _flushData();
		// �����������
		void processRecvData();
	protected:
		int32_t _ID;
		// Զ����Ϣ{��ַ���˿�}
		std::pair<std::string, int32_t> _remote;
		// �Ƿ����ӷ�����
		bool _bConnected = false;
		// socket
		Socket* _socket = nullptr;
		// ���յ�������
		DataQueue _recvDatas;
		// �����͵�����
		DataQueue _sendDatas;
		// ��������ʱ�Ĵ���
		ClientRecvHandler _recvHandler;
		ClientRecvFunc _recvFunc = nullptr;
		// �ͻ��˶Ͽ�ʱ�Ĵ���
		ClientCloseHandler _closeHandler;
		ClientCloseFunc _closeFunc = nullptr;
	};
}