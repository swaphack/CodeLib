#pragma once

#include <list>

namespace sys
{
	class Task;
	/**
	*
	*/
	class WorkFlow
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
		virtual void update();
	private:
		// 所有任务
		std::list<Task*> _tasks;
	};
}
