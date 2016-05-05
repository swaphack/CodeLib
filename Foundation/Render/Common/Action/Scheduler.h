#pragma once

#include "Action.h"

namespace render
{
	typedef void (sys::Object::*ACTION_UPDATE)(float intervale);
	#define SEL_ACTION_UPDATE(SELECTOR) static_cast<ACTION_UPDATE>(&SELECTOR)

	// 周期性定时器
	class Scheduler : public Action
	{
	public:
		Scheduler();
		virtual ~Scheduler();
	public:
		virtual void update(float interval);
		// 设置动作执行事件
		void setHandler(const ACTION_UPDATE handler);
	protected:
		// 动作执行事件
		ACTION_UPDATE _handler;
	};
}