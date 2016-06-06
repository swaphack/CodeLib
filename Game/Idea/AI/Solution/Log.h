#pragma once

#include "macros.h"
#include "system.h"

namespace idea
{	
	// 记录
	class Log : public IWorker
	{
	public:
		Log();
		virtual ~Log();
	public:
		Event* mark();
		// 保存日志
		virtual Result* run(Event* e);
	};
}