#pragma once

#include "WorkFlow.h"

namespace alg
{
	namespace work
	{	
		/**
		*	���й���
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
