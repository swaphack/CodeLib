#pragma once

#include "macros.h"

namespace idea
{
	// ��¼
	class Log : public IWorker
	{
	public:
		Log();
		~Log();
	public:
		// ������־
		virtual Result* run(Event* e);
	};
}