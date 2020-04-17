#pragma once

#include "Session.h"
#include "system.h"

#include "Http/import.h"
#include "Packet/import.h"
#include "Listener/import.h"

namespace web
{
	// Web�����
	class WebServer
	{
	public:
		WebServer();
		virtual ~WebServer();
	public:
		// ����һ��������
		sys::Server* createServer(const std::string& ip, int port, int maxWaitCount);
		// �������ͻ���
		void postResponse(int id, sys::NetData* data);
		// �㲥
		void postBroadcast(sys::NetData* data);
		// ���ý��յ�����ʱ�Ĵ���
		void setRecvHandler(sys::Object* target, sys::CLIENT_RECV_HANDLER handler);
		// ���ÿͻ��˶Ͽ�ʱ�Ĵ���
		void setCloseHandler(sys::Object* target, sys::CLIENT_CLOSE_HANDLER handler);
		// ����
		void update();
	private:
		// ������
		sys::Server* _server;
		// ��������ʱ�Ĵ���
		sys::ClientRecvHandler _recvHandler;
		// �ͻ��˶Ͽ�ʱ�Ĵ���
		sys::ClientCloseHandler _closeHandler;
	};
}