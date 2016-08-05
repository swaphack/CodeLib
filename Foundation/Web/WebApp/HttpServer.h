#pragma once

#include "macros.h"
#include "Session.h"

namespace web
{
	// httpӦ�÷�����
	class HttpServer
	{
	public:
		HttpServer(sys::Server* server);
		virtual ~HttpServer();
	public:
		// ��ӽ������ݴ���
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// �Ƴ��������ݴ���
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// �������ͻ���
		void postResponse(HttpResponse* response);
		// �㲥
		void postBroadcast(HttpResponse* response);
		// ����
		void update();
		// ��������
		void onParseData(int id, sys::DataQueue& dataQueue);
	protected:
		// �ͻ�����Ϣ
		Session* getSession();
		// ����������
		void onRecvHander(HttpRequest* data);
	private:
		// �ӽ��յ������д���http���󣬲���ɾ������ɵ�����
		HttpRequest* createHttpRequest(int id, sys::DataQueue& dataQueue);
		// ��http����ת����������
		sys::NetData* createResponseData(HttpResponse* response);
	private:
		// ������
		sys::Server* _server;
		// �ͻ�����Ϣ
		Session* _session;
		// http���ܴ���
		std::vector<HttpRecvHandler> _recvHandlers;
	};
}