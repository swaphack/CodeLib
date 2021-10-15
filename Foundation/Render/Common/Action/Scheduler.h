#pragma once

#include "Action.h"

namespace render
{
	typedef void (Node::* SCHEDULER_DELEGATE_HANDLER)(float interval);
	#define SCHEDULER_DELEGATE_SCHEDULER(SELECTOR) static_cast<SCHEDULER_DELEGATE_HANDLER>(&SELECTOR)

	typedef std::pair<Node*, SCHEDULER_DELEGATE_HANDLER> SCHEDULER_DELEGATE;

	typedef std::function<void(float interval)> SCHEDULER_FUNC;

	// �����Զ�ʱ��
	class Scheduler : public Action
	{
	public:
		Scheduler();
		virtual ~Scheduler();
	public:
		static Scheduler* createOnce(float delayTime, const SCHEDULER_FUNC& func);
		static Scheduler* createSchedule(float delayTime, float totalTime, float intervalTime, const SCHEDULER_FUNC& func);
		static Scheduler* createForever(float delayTime, float intervalTime, const SCHEDULER_FUNC& func);
	public:
		virtual void update(float interval);
		// ���ö���ִ���¼�
		void setHandler(Node* target, SCHEDULER_DELEGATE_HANDLER handler);
		// ���ö���ִ���¼�
		void setHandler(const SCHEDULER_FUNC& func);
	public:
		// �ӳ�ʱ��
		void setDelayTime(float time);
		// ���ʱ��
		void setIntervalTime(float time);
		// ��ʱ��
		void setTotalTime(float time);
	protected:
		// ����ִ���¼�
		SCHEDULER_DELEGATE _handler;
		// ����ִ���¼�
		SCHEDULER_FUNC _func = nullptr;
		
		// �ӳ�ʱ��
		float _delayTime = 0;
		// �������
		float _intervalTime = 0;
		// ��ʱ��
		float _totalTime = 0;
		// ��ǰʱ��
		float _currentTime = 0;
	};
}