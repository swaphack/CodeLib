#pragma once

namespace slg
{
	// 任务条件
	class TaskCondition
	{
	public:
		virtual ~TaskCondition() {}
	public:
		virtual bool isFinish() = 0;
	protected:
	private:
	};
}