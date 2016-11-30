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
		void onReceiveRequest(const char* sessionID, sys::HttpRequest* request);
		void onReceiveResponse(const char* sessionID, sys::HttpResponse* response);
	protected:
		// 收到http请求
		virtual void doGetRequest(sys::HttpRequest* request);
		// 收到http请求
		virtual void doGetResponse(sys::HttpResponse* response);
	protected:
		// 发送http反馈
		void doPostResponse(sys::HttpResponse* response);
		// 发送http反馈
		void doPostResponse(sys::HttpRequest* request);
		// 发送给指定目标
		void doPostResponse(int destID, sys::HttpResponse* response);
		// 发送给指定目标
		void doPostRequest(int destID, sys::HttpRequest* request);
		// 发送给指定目标
		void doPostResponse(const char* sessionID, sys::HttpResponse* response);
		// 发送给指定目标
		void doPostRequest(const char* sessionID, sys::HttpRequest* request);
		// 广播
		void doBroadCast(sys::HttpResponse* response);
		// 广播
		void doBroadCast(sys::HttpRequest* request);
	protected:
		std::string _sessionID;
	};
}