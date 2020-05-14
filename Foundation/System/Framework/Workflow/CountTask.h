#pragma once

#include "Task.h"

#include <cstdint>

namespace sys
{
	/**
	*	有次数限制的任务
	*/
	class CountTask : public Task
	{
	public:
		CountTask();
		CountTask(uint32_t nCount);
		virtual ~CountTask();
	public:
		/**
		*	是否自动释放
		*/
		virtual bool isOver();
	public:
		/**
		*	设置次数
		*/
		void setCount(uint32_t nCount);
		/**
		*	获取次数
		*/
		uint32_t getCount();
	private:
		// 次数
		uint32_t m_nCount = 0;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	执行一次的任务
	*/
	class OnceTask : public CountTask
	{
	public:
		OnceTask();
		virtual ~OnceTask();
	};
}
