#pragma once

#include "Work/Base/WorkObject.h"
#include <functional>
#include <set>
#include "TaskLimit.h"

namespace alg
{
	namespace work
	{
		class WorkFlow;

		class ITaskEvent
		{
		public:
			virtual ~ITaskEvent() {};
		public:
			virtual void doEvent(float dt) = 0;
		};
		/**
		*	任务
		*/
		class Task : public WorkObject
		{
		public:
			typedef std::function<void(float dt)> TaskFunc;
		public:
			Task();
			virtual ~Task();
		public:
			/**
			*	设置所属工作流
			*/
			void setWorkFlow(WorkFlow* workflow);
			/**
			*	获取所属工作流
			*/
			WorkFlow* getWorkFlow() const;
		public: // 数据
			/**
			*	设置工作流共享数据
			*/
			void setWorkFlowData(const std::string& name, void* data);
			/**
			*	获取工作流共享数据
			*/
			void* getWorkFlowData(const std::string& name) const;
		public:// 限制
			/**
			*	添加限制
			*/
			void addLimit(TaskLimit* limit);
			/**
			*	移除限制
			*/
			void removeLimit(TaskLimit* limit);
			/**
			*	移除所有限制
			*/
			void removeAllLimits();
		public:
			/**
			*	设置任务执行函数
			*/
			void setTaskFunc(const TaskFunc& func);
			/**
			*	设置任务事件
			*/
			void setTaskEvent(const ITaskEvent* pEvt);
		protected:
			/**
			*	更新
			*/
			virtual void onUpdate(float dt);
		private:
			// 任务执行函数
			TaskFunc _func = nullptr;
			// 任务事件
			ITaskEvent* _event = nullptr;
			// 工作流
			WorkFlow* _workflow = nullptr;
			// 限制
			std::set<TaskLimit*> _limits;
		};
	}
}