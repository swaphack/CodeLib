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
		// �յ�����
		virtual void doGet(HttpRequest* request);
		// ���͸����շ�
		virtual void doPost(HttpResponse* response);
		// �㲥
		virtual void doBroadCast(HttpResponse* response);
	private:
		void sendResponse(int id, HttpResponse* response);
		void sendBroadcast(HttpResponse* response);
	private:
		int _srcID;
	};
}