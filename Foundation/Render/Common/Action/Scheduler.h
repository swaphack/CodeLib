#pragma once

#include "Action.h"

namespace render
{
	typedef void (Node::* SCHEDULER_DELEGATE_HANDLER)(float interval);
	#define SCHEDULER_DELEGATE_SCHEDULER(SELECTOR) static_cast<SCHEDULER_DELEGATE_HANDLER>(&SELECTOR)

	typedef std::pair<Node*, SCHEDULER_DELEGATE_HANDLER> SCHEDULER_DELEGATE;

	typedef std::function<void(float interval)> SCHEDULER_FUNC;

	// 周期性定时器
	class Scheduler : public Action
	{
	public:
		Scheduler();
		virtual ~Scheduler();
	public:
		virtual void update(float interval);
		// 设置动作执行事件
		void setHandler(Node* target, SCHEDULER_DELEGATE_HANDLER handler);
		// 设置动作执行事件
		void setHandler(SCHEDULER_FUNC func);
	protected:
		// 动作执行事件
		SCHEDULER_DELEGATE _handler;
		// 动作执行事件
		SCHEDULER_FUNC _func = nullptr;
	};
}