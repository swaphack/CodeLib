#pragma once

#include "macros.h"

namespace idea
{
	// 记录
	class Log : public IWorker
	{
	public:
		Log();
		~Log();
	public:
		// 保存日志
		virtual Result* run(Event* e);
	};
}