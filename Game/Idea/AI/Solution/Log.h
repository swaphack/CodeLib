#pragma once

#include "macros.h"
#include "system.h"

namespace idea
{	
	// ��¼
	class Log : public IWorker
	{
	public:
		Log();
		virtual ~Log();
	public:
		Event* mark();
		// ������־
		virtual Result* run(Event* e);
	};
}