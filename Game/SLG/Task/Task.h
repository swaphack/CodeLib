#pragma once

#include "TaskCondition.h"
#include "TaskReward.h"

namespace slg
{
	// ����
	class Task
	{
	public:
		virtual ~Task() {}
	public:
		// ��ȡ��������
		virtual ITaskCondition* getCondition() = 0;
		// ��ȡ������
		virtual ITaskReward* getReward() = 0;
		// ��ȡ��������
		virtual const char* getDescribe() = 0;
	};
}