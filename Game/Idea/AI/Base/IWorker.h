#pragma once

#include "Result.h"
#include "Event.h"

namespace idea
{
	// �¼�ִ����
	class IWorker
	{
	public:
		virtual ~IWorker() {}
	public:
		virtual Result* run(Event* e) = 0;
	};
}