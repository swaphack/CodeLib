#pragma once

#include "TaskLimit.h"

namespace alg
{
	namespace work
	{
		/**
		*	��Զִ�е�����
		*/
		class TaskForeverLimit : public TaskLimit
		{
		public:
			TaskForeverLimit();
			virtual ~TaskForeverLimit();
		protected:
			/**
			*	����
			*/
			virtual void onUpdate(float dt);
		};
	}
}
