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
		static Scheduler* createOnce(float delayTime, const SCHEDULER_FUNC& func);
		static Scheduler* createSchedule(float delayTime, float totalTime, float intervalTime, const SCHEDULER_FUNC& func);
		static Scheduler* createForever(float delayTime, float intervalTime, const SCHEDULER_FUNC& func);
	public:
		virtual void update(float interval);
		// 设置动作执行事件
		void setHandler(Node* target, SCHEDULER_DELEGATE_HANDLER handler);
		// 设置动作执行事件
		void setHandler(const SCHEDULER_FUNC& func);
	public:
		// 延迟时间
		void setDelayTime(float time);
		// 间隔时间
		void setIntervalTime(float time);
		// 总时长
		void setTotalTime(float time);
	protected:
		// 动作执行事件
		SCHEDULER_DELEGATE _handler;
		// 动作执行事件
		SCHEDULER_FUNC _func = nullptr;
		
		// 延迟时间
		float _delayTime = 0;
		// 间隔周期
		float _intervalTime = 0;
		// 总时长
		float _totalTime = 0;
		// 当前时间
		float _currentTime = 0;
	};
}