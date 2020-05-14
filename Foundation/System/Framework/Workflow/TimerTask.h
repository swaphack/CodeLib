#pragma once

#include "Task.h"

#include <cstdint>

namespace sys
{
	/**
	*	��ʱ����
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
		*	����ʱ��
		*/
		void setTime(uint64_t nTime);
		/**
		*	��ȡʱ��
		*/
		uint64_t getTime();
	private:
		// ʱ��
		uint64_t m_nTime = 0;
	};
}
