#pragma once

#include "system.h"

namespace web
{
	class HttpActivity : public sys::Object
	{
	public:
		HttpActivity();
		virtual ~HttpActivity();
	protected:
		void onReceiveRequest(const std::string& sessionID, sys::HttpRequest* request);
		void onReceiveResponse(const std::string& sessionID, sys::HttpResponse* response);
	protected:
		// �յ�http����
		virtual void doGetRequest(sys::HttpRequest* request);
		// �յ�http����
		virtual void doGetResponse(sys::HttpResponse* response);
	protected:
		// ����http����
		void doPostResponse(sys::HttpResponse* response);
		// ����http����
		void doPostResponse(sys::HttpRequest* request);
		// ���͸�ָ��Ŀ��
		void doPostResponse(int destID, sys::HttpResponse* response);
		// ���͸�ָ��Ŀ��
		void doPostRequest(int destID, sys::HttpRequest* request);
		// ���͸�ָ��Ŀ��
		void doPostResponse(const std::string& sessionID, sys::HttpResponse* response);
		// ���͸�ָ��Ŀ��
		void doPostRequest(const std::string& sessionID, sys::HttpRequest* request);
		// �㲥
		void doBroadCast(sys::HttpResponse* response);
		// �㲥
		void doBroadCast(sys::HttpRequest* request);
	protected:
		std::string _sessionID;
	};
}