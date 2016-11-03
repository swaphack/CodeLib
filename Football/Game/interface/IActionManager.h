#pragma once

namespace game
{
	class IAction;
	class IPlayer;
	/**
	*	比赛场景
	*/
	class IActionManager
	{
	public:
		virtual ~IActionManager() {}
	public:
		/**
		*	添加动作
		*/
		virtual void addAction(IAction* action) = 0;
		/**
		*	移除动作
		*/
		virtual void removeAction(IAction* action) = 0;
		/**
		*	移除所有动作
		*/
		virtual void removeAllActions() = 0;
	};
}