#pragma once

#include "macros.h"

#include "Analysis.h"

namespace idea
{
	// ���
	class Solution : public IWorker
	{
	public:
		Solution();
		virtual ~Solution();
	public:
		// �������
		virtual Result* run(Event* e);
	};
}