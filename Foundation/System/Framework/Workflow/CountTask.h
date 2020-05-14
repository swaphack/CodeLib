#pragma once

#include "Task.h"

#include <cstdint>

namespace sys
{
	/**
	*	�д������Ƶ�����
	*/
	class CountTask : public Task
	{
	public:
		CountTask();
		CountTask(uint32_t nCount);
		virtual ~CountTask();
	public:
		/**
		*	�Ƿ��Զ��ͷ�
		*/
		virtual bool isOver();
	public:
		/**
		*	���ô���
		*/
		void setCount(uint32_t nCount);
		/**
		*	��ȡ����
		*/
		uint32_t getCount();
	private:
		// ����
		uint32_t m_nCount = 0;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	ִ��һ�ε�����
	*/
	class OnceTask : public CountTask
	{
	public:
		OnceTask();
		virtual ~OnceTask();
	};
}
