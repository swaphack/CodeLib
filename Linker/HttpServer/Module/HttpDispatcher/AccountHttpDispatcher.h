#pragma once

#include "macros.h"

namespace hs
{
	// ÓÐ¿ÎÇëÇó
	class AccountHttpDispatcher : public HttpDispatcher
	{
	public:
		AccountHttpDispatcher();
		virtual ~AccountHttpDispatcher();
	public:
		virtual bool hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response);
	protected:
	private:
	};
}