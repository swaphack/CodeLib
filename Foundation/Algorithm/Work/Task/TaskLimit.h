#pragma once

#include "system.h"

namespace alg
{
	namespace work
	{
		class Task;

		/**
		*	任务限制
		*/
		class TaskLimit : public sys::Object
		{
		public:
			TaskLimit();
			virtual ~TaskLimit();
		public:
			/**
			*	更新
			*/
			virtual void update(float dt);
		public:
			/**
			*	是否触发限制
			*/
			bool isTrigger() const;
			/**
			*	设置是否触发限制
			*/
			void setTrigger(bool bTrigger);
			/**
			*	重置
			*/
			void reset();
		public:
			/**
			*	设置任务
			*/
			void setTask(Task* task);
			/**
			*	获取任务
			*/
			Task* getTask() const;
		protected:
			/**
			*	更新
			*/
			virtual void onUpdate(float dt);
			/**
			*	重置
			*/
			virtual void onReset();
		protected:
			// 触发限制
			bool _bTrigger = false;
			// 任务
			Task* _task = nullptr;

		};
	}
}