#pragma once

#include "TaskLimit.h"

#include <cstdint>

namespace alg
{
	namespace work
	{
		/**
		*	�д������Ƶ�����
		*/
		class TaskCountLimit : public TaskLimit
		{
		public:
			TaskCountLimit();
			TaskCountLimit(uint32_t nCount);
			virtual ~TaskCountLimit();
		public:
			/**
			*	���ô���
			*/
			void setCount(uint32_t nCount);
			/**
			*	��ȡ����
			*/
			uint32_t getCurrentCount() const;
			/**
			*	�ܴ���
			*/
			uint32_t getTotalCount() const;
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
			// ��ǰ����
			uint32_t m_nCurrentCount = 0;
			// �ܴ���
			uint32_t m_nTotalCount = 0;
		};
	}
}
