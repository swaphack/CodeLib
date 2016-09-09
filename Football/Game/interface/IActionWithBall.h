#pragma once

#include "IAction.h"

namespace game
{
	struct Parabola;
	struct Point;

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
	*	ͣ��
	*/
	class IStopBallAction : public IActionWithBall
	{
	public:
		virtual ~IStopBallAction() {}
	public:
	};

	/**
	*	����
	*/
	class IPassAction : public IActionWithBall
	{
	public:
		virtual ~IPassAction() {}
	public:
		/**
		*	Ŀ���
		*/
		virtual const Point& getDestination();
		/**
		*	��������
		*/
		virtual const Parabola* getParabola() const = 0;
	};	

	/**
	*	����
	*/
	class IDribbleBallAction : public IActionWithBall
	{
	public:
		virtual ~IDribbleBallAction() {}
	public:
	};

	/**
	*	������
	*/
	class IInterceptBallAction : public IActionWithBall
	{
	public:
		virtual ~IInterceptBallAction() {}
	public:
	};

	/**
	*	�ٶ���
	*/
	class IFakeBallAction : public IActionWithBall
	{
	public:
		virtual ~IFakeBallAction() {}
	public:
	};


	/**
	*	��������
	*/
	class IThrowInBallAction : public IActionWithBall
	{
	public:
		virtual ~IThrowInBallAction() {}
	public:
	};

	/**
	*	����
	*/
	class IShootBallAction : public IActionWithBall
	{
	public:
		virtual ~IShootBallAction() {}
	public:
	};
}