#pragma once

#include "WorkFlow.h"

namespace alg
{
	namespace work
	{	
		/**
		*	并行工作
		*/
		class SpawnWorkFlow : public WorkFlow
		{
		public:
			SpawnWorkFlow();
			virtual ~SpawnWorkFlow();
		public:
			virtual void onUpdate(float dt);
		};
	}
}
