#pragma once

namespace game
{
	class IPlayer;
	class IBall;

	/**
	*	比赛动作
	*/
	class IAction
	{
	public:
		virtual ~IAction() {}
	public:
		/**
		*	发起者
		*/
		virtual const IPlayer* getPlayer() const = 0;
		/**
		*	发起者
		*/
		virtual const IPlayer* getPlayer() const = 0;
		/**
		*	触犯规则
		*/
		virtual int getBreakRuleID() const = 0;
	};

	/**
	*	有球动作
	*/
	class IActionWithBall : public IAction
	{
	public:
		virtual ~IActionWithBall() {}
	public:
		/**
		*	球
		*/
		virtual const IBall* getBall() const = 0;
	};

	/**
	*	无球动作
	*/
	class IActionWithOutBall : public IAction
	{
	public:
		virtual ~IActionWithOutBall() {}
	public:
		
	};
}