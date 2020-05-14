#pragma once

#include "Task.h"

#include <cstdint>

namespace sys
{
	/**
	*	计时任务
	*/
	class TimerTask : public Task
	{
	public:
		TimerTask();
		TimerTask(uint64_t nTime);
		virtual ~TimerTask();
	public:
		virtual bool isOver() override;
	public:
		/**
		*	设置时间
		*/
		void setTime(uint64_t nTime);
		/**
		*	获取时间
		*/
		uint64_t getTime();
	private:
		// 时间
		uint64_t m_nTime = 0;
	};
}
