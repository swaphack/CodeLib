#pragma once

#include "system.h"
#include "../Command/import.h"
#include "../Http/import.h"

namespace web
{
	class HttpActivity : public sys::Object
	{
	public:
		HttpActivity();
		virtual ~HttpActivity();
	public:
		void onReceiveRequest(const char* sessionID, HttpRequest* request);
	protected:
		// �յ�http����
		virtual void doGet(HttpRequest* request);
		// ����http����
		virtual void doPost(HttpResponse* response);
		// �㲥
		virtual void doBroadCast(HttpResponse* response);
	private:
		void sendResponse(const char* sessionID, HttpResponse* response);
		void sendBroadcast(const char* sessionID, HttpResponse* response);
	private:
		std::string _sessionID;
	};
}