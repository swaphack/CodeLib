#pragma once

namespace slg
{
	// ��������
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