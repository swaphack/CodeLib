#pragma once

#include "system.h"
#include "../Command/import.h"

namespace web
{
	class HttpActivity : public sys::Object
	{
	public:
		HttpActivity();
		virtual ~HttpActivity();
	public:
		void onReceiveRequest(int id, HttpRequest* request);
	protected:
		// 收到数据
		virtual void doGet(HttpRequest* request);
		// 发送给接收方
		virtual void doPost(HttpResponse* response);
		// 广播
		virtual void doBroadCast(HttpResponse* response);
	private:
		void sendResponse(int id, HttpResponse* response);
		void sendBroadcast(HttpResponse* response);
	private:
		int _srcID;
	};
}