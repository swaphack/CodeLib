#pragma once

#include "WorkFlow.h"

namespace alg
{
	namespace work
	{
		/**
		*	˳����
		*/
		class SequenceWorkFlow : public WorkFlow
		{
		public:
			SequenceWorkFlow();
			virtual ~SequenceWorkFlow();
		public:
			virtual void onUpdate(float dt);
		};
	}
}
