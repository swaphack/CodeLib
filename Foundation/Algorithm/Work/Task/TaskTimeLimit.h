#pragma once

#include "TaskLimit.h"

#include <cstdint>

namespace alg
{
	namespace work
	{
		/**
		*	计时任务
		*/
		class TaskTimeLimit : public TaskLimit
		{
		public:
			TaskTimeLimit();
			TaskTimeLimit(float nTime);
			virtual ~TaskTimeLimit();
		public:
			/**
			*	设置时间
			*/
			void setTime(float nTime);
			/**
			*	获取当前运行时间
			*/
			float getCurrentTime() const;
			/**
			*	获取总时间
			*/
			float getTotalTime() const;
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
			// 当前时间
			float m_fCurrentTime = 0;
			// 总时长
			float m_fTotalTime = 0;
		};
	}
}
