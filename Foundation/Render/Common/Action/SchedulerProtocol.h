#pragma once

namespace render
{

	class Scheduler;

	class SchedulerProtocol
	{
	public:
		SchedulerProtocol();
		virtual ~SchedulerProtocol();
	public:
		/** 
		*	开始
		*/
		virtual void start();
		/**
		*	恢复
		*/ 
		virtual void pause();
		/**
		*	暂停
		*/ 
		virtual void resume();
		/**
		*	结束
		*/ 
		virtual void stop();
		/**
		*	获取定时器
		*/
		Scheduler* getScheduler() const;
	protected:
		/**
		*	添加定时器
		*/ 
		virtual void registerScheduler();
		/**
		*	移除定时器
		*/ 
		virtual void unregisterScheduler();
	protected:
		/**
		*	获取定时器
		*/
		Scheduler* _scheduler = nullptr;
	};
}
