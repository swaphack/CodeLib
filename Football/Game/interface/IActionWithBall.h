#pragma once

#include "IAction.h"

namespace game
{
	struct Parabola;
	struct Point;

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
	*	停球
	*/
	class IStopBallAction : public IActionWithBall
	{
	public:
		virtual ~IStopBallAction() {}
	public:
	};

	/**
	*	传球
	*/
	class IPassAction : public IActionWithBall
	{
	public:
		virtual ~IPassAction() {}
	public:
		/**
		*	目标点
		*/
		virtual const Point& getDestination();
		/**
		*	传球曲线
		*/
		virtual const Parabola* getParabola() const = 0;
	};	

	/**
	*	运球
	*/
	class IDribbleBallAction : public IActionWithBall
	{
	public:
		virtual ~IDribbleBallAction() {}
	public:
	};

	/**
	*	拦截球
	*/
	class IInterceptBallAction : public IActionWithBall
	{
	public:
		virtual ~IInterceptBallAction() {}
	public:
	};

	/**
	*	假动作
	*/
	class IFakeBallAction : public IActionWithBall
	{
	public:
		virtual ~IFakeBallAction() {}
	public:
	};


	/**
	*	掷界外球
	*/
	class IThrowInBallAction : public IActionWithBall
	{
	public:
		virtual ~IThrowInBallAction() {}
	public:
	};

	/**
	*	射门
	*/
	class IShootBallAction : public IActionWithBall
	{
	public:
		virtual ~IShootBallAction() {}
	public:
	};
}