#pragma once

#include "macros.h"

namespace hs
{
	// �п�����
	class GuestHttpDispatcher : public HttpDispatcher
	{
	public:
		GuestHttpDispatcher();
		virtual ~GuestHttpDispatcher();
	public:
		virtual bool hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response);
	};
}