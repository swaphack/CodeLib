#pragma once

#include "TaskLimit.h"

#include <cstdint>

namespace alg
{
	namespace work
	{
		/**
		*	有次数限制的任务
		*/
		class TaskCountLimit : public TaskLimit
		{
		public:
			TaskCountLimit();
			TaskCountLimit(uint32_t nCount);
			virtual ~TaskCountLimit();
		public:
			/**
			*	设置次数
			*/
			void setCount(uint32_t nCount);
			/**
			*	获取次数
			*/
			uint32_t getCurrentCount() const;
			/**
			*	总次数
			*/
			uint32_t getTotalCount() const;
		protected:
			/**
			*	更新
			*/
			virtual void onUpdate(float dt);
			/**
			*	重置
			*/
			virtual void onReset();
		private:
			// 当前次数
			uint32_t m_nCurrentCount = 0;
			// 总次数
			uint32_t m_nTotalCount = 0;
		};
	}
}
