#pragma once

#include "macros.h"
#include "Session.h"
#include "system.h"

namespace web
{
	// WebӦ�÷�����
	class WebServer
	{
	public:
		WebServer(sys::Server* server);
		virtual ~WebServer();
	public:
		// ��ӽ������ݴ���
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// �Ƴ��������ݴ���
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// �������ͻ���
		void postResponse(sys::HttpResponse* response);
		// �㲥
		void postBroadcast(sys::HttpResponse* response);
		// ����
		void update();
		// ��������
		void onParseData(int id, sys::DataQueue& dataQueue);
	protected:
		// �ͻ�����Ϣ
		Session* getSession();
		// ����������
		void onRecvHander(sys::HttpRequest* data);
	private:
		// �ӽ��յ������д���http���󣬲���ɾ������ɵ�����
		sys::HttpRequest* createHttpRequest(int id, sys::DataQueue& dataQueue);
		// ��http����ת����������
		sys::NetData* createResponseData(sys::HttpResponse* response);
	private:
		// ������
		sys::Server* _server;
		// �ͻ�����Ϣ
		Session* _session;
		// http���ܴ���
		std::vector<HttpRecvHandler> _recvHandlers;
	};
}