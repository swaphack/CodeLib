#pragma once

#include "../Framework/Object.h"
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
		Client(const char* ip, int port);
		~Client();
	public:
		/*
		 * ����
		 * ��������
		 * ��������
		 */
		void update();
		// ���ý��յ�����ʱ�Ĵ���
		void setRecvHandler(Object* target, CLIENT_RECV_HANDLER handler);
		// ������Ϣ, ʹ��new��������Ϻ���Զ��ͷ�
		void sendMessage(NetData* data);
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
		Socket* _socket;
		DataQueue _recvDatas;
		DataQueue _sendDatas;
		// ��������ʱ�Ĵ���
		ClientRecvHandler _recvHandler;
	};
}