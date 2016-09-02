#pragma once

#include "IAction.h"

namespace game
{
	class IPlayer;
	struct Parabola;
	struct Point;

	/**
	*	���򣨰������ţ�����
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
}