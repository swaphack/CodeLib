#pragma once

#include "system.h"

#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024
	class HttpRequest;
	typedef void (sys::Object::*HTTP_RECV_HANDLER)(const char* sessionID, HttpRequest* data);

	struct HttpRecvHandler
	{
		sys::Object* target;
		HTTP_RECV_HANDLER hander;

		HttpRecvHandler() :target(nullptr), hander(nullptr){}

		void hand(const char* sessionID, HttpRequest* data)
		{
			if (!empty())
				(target->*hander)(sessionID, data);
		}

		bool equals(sys::Object* target, HTTP_RECV_HANDLER handler)
		{
			return this->target == target && this->hander == handler;
		}

		bool empty()
		{
			return target == nullptr || hander == nullptr;
		}

		void clean()
		{
			target = nullptr;
			hander = nullptr;
		}
	};
}