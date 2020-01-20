#pragma once

#include "Framework/Object.h"
#include "Socket.h"
#include "NetData.h"
#include "DataQueue.h"
#include "SocketRecvHandler.h"
#include <map>

namespace sys
{
	class Client
	{
	public:
		Client(const std::string& ip, int32_t port);
		~Client();
	public:
		int32_t getID();
		// ����Զ����Ϣ
		void setRemote(const std::string& ip, int32_t port);
		// ���ӷ�����
		bool connect();
		// �Ͽ�����
		bool disconnect();
		// �Ƿ����ӳɹ�
		bool isConnected();
		/*
		 * ����
		 * ��������
		 * ��������
		 */
		void update();
		// ���ý��յ�����ʱ�Ĵ���
		void setRecvHandler(Object* target, CLIENT_RECV_HANDLER handler);
		// ���ÿͻ��˶Ͽ�ʱ�Ĵ���
		void setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler);
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
	protected:
		int32_t _ID;
		// Զ����Ϣ{��ַ���˿�}
		std::pair<std::string, int32_t> _remote;
		// �Ƿ����ӷ�����
		bool _bConnected;
		// socket
		Socket* _socket;
		// ���յ�������
		DataQueue _recvDatas;
		// �����͵�����
		DataQueue _sendDatas;
		// ��������ʱ�Ĵ���
		ClientRecvHandler _recvHandler;
		// �ͻ��˶Ͽ�ʱ�Ĵ���
		ClientCloseHandler _closeHandler;
	};
}