#pragma once

#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace hs
{
	class HttpReceiver : public web::HttpActivity
	{
	public:
		HttpReceiver();
	protected:
		// ����������
		virtual void doGetRequest(sys::HttpRequest* request);
	};
}