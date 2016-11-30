#pragma once

#include "system.h"

#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024
	class sys::HttpRequest;
	typedef void (sys::Object::*HTTP_RECV_REQUEST_HANDLER)(const char* sessionID, sys::HttpRequest* data);

	class sys::HttpResponse;
	typedef void (sys::Object::*HTTP_RECV_RESPONE_HANDLER)(const char* sessionID, sys::HttpResponse* data);

	typedef std::pair<sys::Object*, HTTP_RECV_REQUEST_HANDLER> HttpRecvRequestHandler;
	typedef std::pair<sys::Object*, HTTP_RECV_RESPONE_HANDLER> HttpRecvResponseHandler;
}