#pragma once

#include "macros.h"

namespace idea
{
	// 解决方案
	class Solution : public IWorker
	{
	public:
		Solution();
		virtual ~Solution();
	public:
		// 解决问题
		virtual Result* run(Event* e);
	};
}