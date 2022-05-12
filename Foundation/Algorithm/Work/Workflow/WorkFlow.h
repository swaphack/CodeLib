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
		*	������
		*/
		class WorkFlow : public Task
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
			/**
			*	��ȡ��������
			*/
			WorkDataMap* getSharedData();
		protected:
			/**
			*	����
			*/
			virtual void onUpdate(float dt);
		protected:
			// ��������
			std::list<Task*> _tasks;
			// ��ǰ�������й�������
			WorkDataMap _sharedData;
		};
	}
}
