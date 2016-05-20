#pragma once

#include "Result.h"
#include "Event.h"

namespace idea
{
	// 事件执行者
	class IWorker
	{
	public:
		virtual ~IWorker() {}
	public:
		virtual Result* run(Event* e) = 0;
	};
}