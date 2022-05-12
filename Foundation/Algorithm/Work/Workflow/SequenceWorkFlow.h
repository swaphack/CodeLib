#pragma once

#include "WorkFlow.h"

namespace alg
{
	namespace work
	{
		/**
		*	Ë³Ðò¹¤×÷
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
