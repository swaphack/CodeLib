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
		virtual void update(float interval);
		// ���ö���ִ���¼�
		void setHandler(Node* target, SCHEDULER_DELEGATE_HANDLER handler);
		// ���ö���ִ���¼�
		void setHandler(SCHEDULER_FUNC func);
	protected:
		// ����ִ���¼�
		SCHEDULER_DELEGATE _handler;
		// ����ִ���¼�
		SCHEDULER_FUNC _func = nullptr;
	};
}