#pragma once

#include "system.h"

namespace web
{
	class HttpActivity : public sys::Object
	{
	public:
		HttpActivity();
		virtual ~HttpActivity();
	public:
		void onReceiveRequest(const char* sessionID, sys::HttpRequest* request);
	protected:
		// �յ�http����
		virtual void doGet(sys::HttpRequest* request);
		// ����http����
		virtual void doPost(sys::HttpResponse* response);
		// ���͸�ָ��Ŀ��
		virtual void doPost(int destID, sys::HttpResponse* response);
		// �㲥
		virtual void doBroadCast(sys::HttpResponse* response);
	protected:
		std::string _sessionID;
	};
}