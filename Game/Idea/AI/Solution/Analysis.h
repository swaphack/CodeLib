#pragma once

#include "macros.h"

namespace idea
{
	// ����
	class Analysis : public IWorker
	{
	public:
		Analysis();
		~Analysis();
	public:
		// ��������
		virtual Result* run(Event* e);
	};
}