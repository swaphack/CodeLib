#pragma once

#include "macros.h"

namespace hs
{
	// �п�����
	class AccountHttpDispatcher : public HttpDispatcher
	{
	public:
		AccountHttpDispatcher();
		virtual ~AccountHttpDispatcher();
	public:
		void init();
	};
}