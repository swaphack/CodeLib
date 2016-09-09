#pragma once

#include "IAction.h"

namespace game
{
	/**
	*	无球动作
	*/
	class IActionWithOutBall : public IAction
	{
	public:
		virtual ~IActionWithOutBall() {}
	public:

	};

	/**
	*	无球启动动作
	*/
	class IStartAction : public IActionWithOutBall
	{
	public:
		virtual ~IStartAction() {}
	};

	/**
	*	无球跑动动作
	*/
	class IRunAction : public IActionWithOutBall
	{
	public:
		virtual ~IRunAction() {}
	};

	/**
	*	无球急停动作
	*/
	class IEmergencyAction : public IActionWithOutBall
	{
	public:
		virtual ~IEmergencyAction() {}
	};

	/**
	*	无球转身动作
	*/
	class ITurnAroundAction : public IActionWithOutBall
	{
	public:
		virtual ~ITurnAroundAction() {}
	};

	/**
	*	无球假动作
	*/
	class IFeintAction : public IActionWithOutBall
	{
	public:
		virtual ~IFeintAction() {}
	};
}