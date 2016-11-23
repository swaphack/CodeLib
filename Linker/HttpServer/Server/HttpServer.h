#pragma once

#include "web.h" 
#include "system.h"

namespace hs
{
	class HttpServer : public web::WebApplication
	{
	public:
		HttpServer(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~HttpServer();
	public:
		void initSelf();
	};

	#define sHttpServer static_cast<HttpServer*>(web::WebApplication::getInstance())
}