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
		*	��ʼ
		*/
		virtual void start();
		/**
		*	�ָ�
		*/ 
		virtual void pause();
		/**
		*	��ͣ
		*/ 
		virtual void resume();
		/**
		*	����
		*/ 
		virtual void stop();
		/**
		*	��ȡ��ʱ��
		*/
		Scheduler* getScheduler() const;
	protected:
		/**
		*	��Ӷ�ʱ��
		*/ 
		virtual void registerScheduler();
		/**
		*	�Ƴ���ʱ��
		*/ 
		virtual void unregisterScheduler();
	protected:
		/**
		*	��ȡ��ʱ��
		*/
		Scheduler* _scheduler = nullptr;
	};
}
