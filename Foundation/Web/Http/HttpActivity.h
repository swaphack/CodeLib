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
		// 收到http请求
		virtual void doGet(sys::HttpRequest* request);
		// 发送http反馈
		virtual void doPost(sys::HttpResponse* response);
		// 广播
		virtual void doBroadCast(sys::HttpResponse* response);
	private:
		void sendResponse(const char* sessionID, sys::HttpResponse* response);
		void sendBroadcast(const char* sessionID, sys::HttpResponse* response);
	private:
		std::string _sessionID;
	};
}