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
		*	����
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
			*	��������������
			*/
			void setWorkFlow(WorkFlow* workflow);
			/**
			*	��ȡ����������
			*/
			WorkFlow* getWorkFlow() const;
		public: // ����
			/**
			*	���ù�������������
			*/
			void setWorkFlowData(const std::string& name, void* data);
			/**
			*	��ȡ��������������
			*/
			void* getWorkFlowData(const std::string& name) const;
		public:// ����
			/**
			*	�������
			*/
			void addLimit(TaskLimit* limit);
			/**
			*	�Ƴ�����
			*/
			void removeLimit(TaskLimit* limit);
			/**
			*	�Ƴ���������
			*/
			void removeAllLimits();
		public:
			/**
			*	��������ִ�к���
			*/
			void setTaskFunc(const TaskFunc& func);
			/**
			*	���������¼�
			*/
			void setTaskEvent(const ITaskEvent* pEvt);
		protected:
			/**
			*	����
			*/
			virtual void onUpdate(float dt);
		private:
			// ����ִ�к���
			TaskFunc _func = nullptr;
			// �����¼�
			ITaskEvent* _event = nullptr;
			// ������
			WorkFlow* _workflow = nullptr;
			// ����
			std::set<TaskLimit*> _limits;
		};
	}
}