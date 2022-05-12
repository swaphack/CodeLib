#pragma once

#include "TaskLimit.h"

namespace alg
{
	namespace work
	{
		/**
		*	永远执行的任务
		*/
		class TaskForeverLimit : public TaskLimit
		{
		public:
			TaskForeverLimit();
			virtual ~TaskForeverLimit();
		protected:
			/**
			*	更新
			*/
			virtual void onUpdate(float dt);
		};
	}
}
