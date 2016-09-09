#pragma once

#include "IAction.h"

namespace game
{
	/**
	*	������
	*/
	class IActionWithOutBall : public IAction
	{
	public:
		virtual ~IActionWithOutBall() {}
	public:

	};

	/**
	*	������������
	*/
	class IStartAction : public IActionWithOutBall
	{
	public:
		virtual ~IStartAction() {}
	};

	/**
	*	�����ܶ�����
	*/
	class IRunAction : public IActionWithOutBall
	{
	public:
		virtual ~IRunAction() {}
	};

	/**
	*	����ͣ����
	*/
	class IEmergencyAction : public IActionWithOutBall
	{
	public:
		virtual ~IEmergencyAction() {}
	};

	/**
	*	����ת����
	*/
	class ITurnAroundAction : public IActionWithOutBall
	{
	public:
		virtual ~ITurnAroundAction() {}
	};

	/**
	*	����ٶ���
	*/
	class IFeintAction : public IActionWithOutBall
	{
	public:
		virtual ~IFeintAction() {}
	};
}