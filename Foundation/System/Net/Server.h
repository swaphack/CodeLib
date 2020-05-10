#pragma once

#include "DataQueue.h"
#include "SocketRecvHandler.h"
#include <map>
#include <string>

namespace sys
{
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 9547

	class Socket;
	struct NetData;
	class Object;

	class Server
	{
	public:
		Server();
		Server(const std::string& ip, int32_t port, int32_t backlog);
		~Server();
	public:
		/*
		 * ����
		 * ���տͻ�������
		 * ���տͻ�������
		 * �������ݸ��ͻ���
		 */
		void update();
		// ���ý�������ʱ�Ĵ���
		void setRecvHandler(Object* target, SERVER_RECV_HANDLER handler);
		void setRecvFunc(ServerRecvFunc func);
		// ���ÿͻ��˶Ͽ�ʱ�Ĵ���
		void setCloseHandler(Object* target, CLIENT_CLOSE_HANDLER handler);
		void setCloseFunc(ClientCloseFunc func);
		// ������Ϣ, ʹ��new��������Ϻ���Զ��ͷ�
		void sendMessage(int32_t id, NetData* data);
		// �㲥
		void sendBroadcast(NetData* data);
	protected:
		// ��ӿͻ���
		void addClient(Socket* sock);
		// �Ƴ��ͻ���
		void removeClient(int32_t sockId);
		// �Ƴ����пͻ���
		void removeAllClients();
		// ��ӽ��յ�������
		void addRecvBuffer(int32_t id, NetData* data);
		// ��Ӵ����͵�����
		void addSendBuffer(int32_t id, NetData* data);
		// ��������ʱ����
		void onRecvHandler(int32_t id, NetData* data);
	private:
		// �������ݣ����Ҵ洢�Ͽ���socket����
		void _recvData(std::vector<int32_t>& removedSocks);
		// �Ƴ�socekt
		void _removeSockets(std::vector<int32_t>& removedSocks);
		// ������ݼ��
		void _flushData();
		// ������Ϣ
		void _flushSendData();
		// ������Ϣ
		void _flushRecvData();

		// �����������
		void processRecvData(int32_t id);
	protected:
		Socket* _socket;
		// �ͻ���
		std::map<int32_t, Socket*> _clients;
		// ���յ�������
		std::map<int32_t, DataQueue*> _recvDatas;
		// �����͵�����
		std::map<int32_t, DataQueue*> _sendDatas;
		// ��������ʱ�Ĵ���
		ServerRecvHandler _recvHandler;
		// ��������ʱ�Ĵ���
		ServerRecvFunc _recvFunc;
		// �ͻ��˶Ͽ�ʱ�Ĵ���
		ClientCloseHandler _closeHandler;
		ClientCloseFunc _closeFunc = nullptr;
	};
}