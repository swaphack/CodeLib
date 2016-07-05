#pragma once

#include "macros.h"
#include "Session.h"
#include "WebApplication.h"

namespace web
{
	// httpӦ�÷�����
	class HttpApplication : public WebApplication
	{
	public:
		HttpApplication(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~HttpApplication();
	public:
		// ��ȡhttpʵ��
		static HttpApplication* getInstance();
		// ��ӽ������ݴ���
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// �Ƴ��������ݴ���
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// �������ͻ���
		void postResponse(HttpResponse* response);
		// �㲥
		void postBroadcast(HttpResponse* response);
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
		// ��������
		virtual void onParseData(int id, sys::DataQueue& dataQueue);
	private:
		// �ͻ�����Ϣ
		Session* _session;
		// http���ܴ���
		std::vector<HttpRecvHandler> _recvHandlers;
	};

	#define G_HTTPAPPLICATION HttpApplication::getInstance()
}