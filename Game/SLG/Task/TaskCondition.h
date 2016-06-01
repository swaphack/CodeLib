#pragma once

namespace slg
{
	struct _TaskCondition
	{
		_TaskCondition* next;

		_TaskCondition()
			:next(nullptr)
		{}
	};
	// 任务条件
	class ITaskCondition
	{
	public:
		virtual ~ITaskCondition() {}
	public:
		virtual bool isFinish() = 0;
	};
}