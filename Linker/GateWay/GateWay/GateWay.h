#pragma once

#include "web.h" 

namespace gw
{
	class GateWay : public web::WebApplication
	{
	public:
		GateWay(const char* ip, int port);
		virtual ~GateWay();
	public:
		virtual void init();
	protected:
	private:
	};
}