#pragma once

namespace slg
{
	// ��������
	class ITaskCondition
	{
	public:
		virtual ~ITaskCondition() {}
	public:
		virtual bool isFinish() = 0;
	};
}