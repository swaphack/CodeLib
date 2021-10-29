#pragma once

#include "../Object.h"
#include <functional>

namespace sys
{
	typedef std::function<void()> TaskFunc;

	class ITaskEvent
	{
	public:
		virtual ~ITaskEvent() {};
		virtual void doEvent() = 0;
	};

	class Task : public Object
	{
	public:
		Task();
		virtual ~Task();
	public:
		/**
		*	初始化
		*/
		virtual void start();
		/**
		*	更新
		*/
		virtual void update();
		/**
		*	释放
		*/
		virtual void finish();
		/**
		*	是否结束
		*/
		virtual bool isOver() const;
	public:
		/**
		*	设置任务执行函数
		*/
		void setTaskFunc(const TaskFunc& func);
		/**
		*	设置任务事件
		*/
		void setTaskEvent(const ITaskEvent* pEvt);
	private:
		// 任务执行函数
		TaskFunc _func = nullptr;
		// 任务事件
		ITaskEvent* _event = nullptr;
	};	
}