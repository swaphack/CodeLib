#pragma once

#include "WorkFlow.h"

namespace alg
{
	namespace work
	{
		/**
		*	ѭ������
		*/
		class CycleWorkFlow : public WorkFlow
		{
		public:
			CycleWorkFlow();
			virtual ~CycleWorkFlow();
		public:
			virtual void onUpdate(float dt);
		};
	}
}
