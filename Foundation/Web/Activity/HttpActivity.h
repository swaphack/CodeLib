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
		virtual void doGet(HttpRequest* request);
		virtual void doPost(HttpResponse* response);
	private:
		void sendResponse(int id, HttpResponse* response);
	private:
		int _srcID;
	};
}