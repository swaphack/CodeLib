#pragma once

#include "macros.h"

namespace idea
{
	// 分析
	class Analysis : public IWorker
	{
	public:
		Analysis();
		virtual ~Analysis();
	public:
		// 分析问题
		virtual Result* run(Event* e);
	};
}