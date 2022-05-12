#pragma once

#include "TaskLimit.h"

#include <cstdint>

namespace alg
{
	namespace work
	{
		/**
		*	��ʱ����
		*/
		class TaskTimeLimit : public TaskLimit
		{
		public:
			TaskTimeLimit();
			TaskTimeLimit(float nTime);
			virtual ~TaskTimeLimit();
		public:
			/**
			*	����ʱ��
			*/
			void setTime(float nTime);
			/**
			*	��ȡ��ǰ����ʱ��
			*/
			float getCurrentTime() const;
			/**
			*	��ȡ��ʱ��
			*/
			float getTotalTime() const;
		protected:
			/**
			*	����
			*/
			virtual void onUpdate(float dt);
			/**
			*	����
			*/
			virtual void onReset();
		private:
			// ��ǰʱ��
			float m_fCurrentTime = 0;
			// ��ʱ��
			float m_fTotalTime = 0;
		};
	}
}
