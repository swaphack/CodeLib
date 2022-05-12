#pragma once

#include "system.h"

namespace alg
{
	namespace work
	{
		class Task;

		/**
		*	��������
		*/
		class TaskLimit : public sys::Object
		{
		public:
			TaskLimit();
			virtual ~TaskLimit();
		public:
			/**
			*	����
			*/
			virtual void update(float dt);
		public:
			/**
			*	�Ƿ񴥷�����
			*/
			bool isTrigger() const;
			/**
			*	�����Ƿ񴥷�����
			*/
			void setTrigger(bool bTrigger);
			/**
			*	����
			*/
			void reset();
		public:
			/**
			*	��������
			*/
			void setTask(Task* task);
			/**
			*	��ȡ����
			*/
			Task* getTask() const;
		protected:
			/**
			*	����
			*/
			virtual void onUpdate(float dt);
			/**
			*	����
			*/
			virtual void onReset();
		protected:
			// ��������
			bool _bTrigger = false;
			// ����
			Task* _task = nullptr;

		};
	}
}