#pragma once

#include "macros.h"

namespace hs
{
	// ÓÐ¿ÎÇëÇó
	class GuestHttpDispatcher : public HttpDispatcher
	{
	public:
		GuestHttpDispatcher();
		virtual ~GuestHttpDispatcher();
	public:
		void init();
	};
}