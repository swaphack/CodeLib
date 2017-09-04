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
		void init();
	};
}