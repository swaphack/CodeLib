#pragma once

#include "system.h"

#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024
	class HttpRequest;
	typedef void (sys::Object::*HTTP_RECV_HANDLER)(const char* sessionID, HttpRequest* data);

	typedef std::pair<sys::Object*, HTTP_RECV_HANDLER> HttpRecvHandler;
}