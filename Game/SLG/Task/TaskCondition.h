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
	// ��������
	class ITaskCondition
	{
	public:
		virtual ~ITaskCondition() {}
	public:
		virtual bool isFinish() = 0;
	};
}