#pragma once

namespace slg
{
	// 任务条件
	class ITaskCondition
	{
	public:
		virtual ~ITaskCondition() {}
	public:
		virtual bool isFinish() = 0;
	};
}