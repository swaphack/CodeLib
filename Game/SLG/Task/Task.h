#pragma once

#include "TaskCondition.h"
#include "TaskReward.h"

namespace slg
{
	// 任务
	class Task
	{
	public:
		virtual ~Task() {}
	public:
		// 获取任务条件
		virtual ITaskCondition* getCondition() = 0;
		// 获取任务奖励
		virtual ITaskReward* getReward() = 0;
		// 获取任务描述
		virtual const char* getDescribe() = 0;
	};
}