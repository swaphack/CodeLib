#pragma once

#include "web.h" 
#include "system.h"

namespace gw
{
	class GateWay : public web::WebApplication
	{
	public:
		GateWay(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~GateWay();
	public:
		virtual void init();
	protected:
	private:
	};
}