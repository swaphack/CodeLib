#pragma once

namespace game
{
	class IPlayer;
	class IBall;

	/**
	*	��������
	*/
	class IAction
	{
	public:
		virtual ~IAction() {}
	public:
		/**
		*	������
		*/
		virtual const IPlayer* getPlayer() const = 0;
		/**
		*	������
		*/
		virtual const IPlayer* getPlayer() const = 0;
		/**
		*	��������
		*/
		virtual int getBreakRuleID() const = 0;
	};

	/**
	*	������
	*/
	class IActionWithBall : public IAction
	{
	public:
		virtual ~IActionWithBall() {}
	public:
		/**
		*	��
		*/
		virtual const IBall* getBall() const = 0;
	};

	/**
	*	������
	*/
	class IActionWithOutBall : public IAction
	{
	public:
		virtual ~IActionWithOutBall() {}
	public:
		
	};
}