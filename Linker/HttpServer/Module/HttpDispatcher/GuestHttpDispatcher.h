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
		void init();
	};
}