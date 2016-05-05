#pragma once

#include "../Framework/Object.h"
#include "Socket.h"
#include "NetData.h"
#include "DataQueue.h"
#include "SocketRecvHandler.h"
#include <map>

namespace sys
{
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 9547

	class Server
	{
	public:
		Server();
		Server(const char* ip, int port, int backlog);
		~Server();
	public:
		/*
		 * ����
		 * ���տͻ���
		 * ���տͻ�������
		 * �������ݸ��ͻ���
		 */
		void update();
		// ���ý��յ�����ʱ�Ĵ���
		void setRecvHandler(Object* target, SERVER_RECV_HANDLER handler);
		// ������Ϣ, ʹ��new��������Ϻ���Զ��ͷ�
		void sendMessage(int id, NetData* data);
	protected:
		// ��ӿͻ���
		void addClient(Socket* sock);
		// �Ƴ��ͻ���
		void removeClient(int sockId);
		// �Ƴ����пͻ���
		void removeAllClients();
		// ��ӽ��յ�������
		void addRecvBuffer(int id, NetData* data);
		// ��Ӵ����͵�����
		void addSendBuffer(int id, NetData* data);
		// ��������ʱ����
		void onRecvHandler(int id, NetData* data);
	private:
		// �������ݣ����Ҵ洢�Ͽ���socket����
		void _recvData(std::vector<int>& removedSocks);
		// �Ƴ�socekt
		void _removeSockets(std::vector<int>& removedSocks);
		// ������Ϣ
		void _flushData();
	protected:
		Socket* _socket;
		// �ͻ���
		std::map<int, Socket*> _clients;
		// ���յ�������
		std::map<int, DataQueue> _recvDatas;
		// �����͵�����
		std::map<int, DataQueue> _sendDatas;
		// ��������ʱ�Ĵ���
		ServerRecvHandler _recvHandler;
	};
}