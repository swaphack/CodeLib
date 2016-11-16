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
		// 发送给指定目标
		virtual void doPost(int destID, sys::HttpResponse* response);
		// 广播
		virtual void doBroadCast(sys::HttpResponse* response);
	protected:
		std::string _sessionID;
	};
}