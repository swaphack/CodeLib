#pragma once

#include "Action.h"

#include <set>

namespace render
{
	class Action;

	// 动作管理
	class ActionManager : public sys::ITimer
	{
	public:
		ActionManager();
		virtual ~ActionManager();
	public:
		// 更新
		void update(float interval);
		// 添加动作
		void addAction(Action* action);
		// 移除动作
		void removeAction(Action* action);
		// 移除所有动作
		void removeAllActions();

		void pauseAllActionsByTargets(sys::Object* target);
		void resumeAllActionsByTargets(sys::Object* target);
		void removeAllActionsByTargets(sys::Object* target);
	private:
		std::set<Action*> _actions;
	};

	#define G_ACTIONMANAGER sys::Instance<ActionManager>::getInstance()
}