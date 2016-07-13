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
		// 收到http请求
		virtual void doGet(HttpRequest* request);
		// 发送http反馈
		virtual void doPost(HttpResponse* response);
		// 广播
		virtual void doBroadCast(HttpResponse* response);
	private:
		void sendResponse(const char* sessionID, HttpResponse* response);
		void sendBroadcast(const char* sessionID, HttpResponse* response);
	private:
		std::string _sessionID;
	};
}