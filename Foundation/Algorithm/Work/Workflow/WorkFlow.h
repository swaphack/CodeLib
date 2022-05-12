#pragma once

#include "Work/Task/Task.h"
#include "Work/Base/WorkData.h"
#include "Work/Base/WorkDataMap.h"
#include <list>
#include <string>
#include <map>

namespace alg
{
	namespace work
	{
		/**
		*	工作流
		*/
		class WorkFlow : public Task
		{
		public:
			WorkFlow();
			virtual ~WorkFlow();
		public:
			/**
			*	添加任务
			*/
			void addTask(Task* task);
			/**
			*	移除任务
			*/
			void removeTask(Task* task);
			/**
			*	移除所有任务
			*/
			void removeAllTasks();
		public:
			/**
			*	获取共享数据
			*/
			WorkDataMap* getSharedData();
		protected:
			/**
			*	更新
			*/
			virtual void onUpdate(float dt);
		protected:
			// 所有任务
			std::list<Task*> _tasks;
			// 当前工作流中共享数据
			WorkDataMap _sharedData;
		};
	}
}
