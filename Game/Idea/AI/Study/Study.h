#pragma once

#include "macros.h"

namespace idea
{
	// 学习
	class Study : public Method
	{
	public:
		Study();
		virtual ~Study();
	public:
		// 学习
		virtual Result* run(Event* e);
	};
}