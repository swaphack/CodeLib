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
		*	�������
		*/
		void addTask(Task* task);
		/**
		*	�Ƴ�����
		*/
		void removeTask(Task* task);
		/**
		*	�Ƴ���������
		*/
		void removeAllTasks();
	public:
		virtual void update();
	private:
		// ��������
		std::list<Task*> _tasks;
	};
}
