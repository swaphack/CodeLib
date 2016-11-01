#pragma once

#include "system.h"

#include <map>

namespace web
{
	// Web�ͻ���,���ڴ�������������������
	class WebClient
	{
	public:
		WebClient();
		virtual ~WebClient();
	public:
		// ����һ���ͻ���
		sys::Client* createClient(const char* ip, int port);
		// ��ȡ�ͻ���
		sys::Client* getClient(int id);
		// �ر�һ���ͻ���
		void closeClient(int id);
		// �ر����пͻ���
		void removeAllClients();
		// ���ý��յ�����ʱ�Ĵ���
		void setRecvHandler(sys::Object* target, sys::CLIENT_RECV_HANDLER handler);
		// ���ÿͻ��˶Ͽ�ʱ�Ĵ���
		void setCloseHandler(sys::Object* target, sys::CLIENT_CLOSE_HANDLER handler);
		// ����
		void update();
	private:
		// �����Ŀͻ��˼�
		std::map<int, sys::Client*> _clients;
		// ��������ʱ�Ĵ���
		sys::ClientRecvHandler _recvHandler;
		// �ͻ��˶Ͽ�ʱ�Ĵ���
		sys::ClientCloseHandler _closeHandler;
	};
}