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
		*	��ʼ��
		*/
		virtual void start();
		/**
		*	����
		*/
		virtual void update();
		/**
		*	�ͷ�
		*/
		virtual void finish();
		/**
		*	�Ƿ����
		*/
		virtual bool isOver() const;
	public:
		/**
		*	��������ִ�к���
		*/
		void setTaskFunc(const TaskFunc& func);
		/**
		*	���������¼�
		*/
		void setTaskEvent(const ITaskEvent* pEvt);
	private:
		// ����ִ�к���
		TaskFunc _func = nullptr;
		// �����¼�
		ITaskEvent* _event = nullptr;
	};	
}