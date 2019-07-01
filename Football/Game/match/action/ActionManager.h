#pragma once

#include "../../base/ITimer.h"

#include <set>

namespace game
{
	class ActionManager : public ITimer
	{
	public:
		ActionManager();
		virtual ~ActionManager();
	public:
		/**
		*	添加动作
		*/
		virtual void addAction(ITimer* action);
		/**
		*	移除动作
		*/
		virtual void removeAction(ITimer* action);
		/**
		*	移除所有动作
		*/
		virtual void removeAllActions();
		/**
		*	更新
		*/
		virtual void update(float dt);
	private:
		std::set<ITimer*> m_sActions;
	};
}