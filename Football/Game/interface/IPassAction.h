#pragma once

#include "IAction.h"

namespace game
{
	class IPlayer;
	struct Parabola;
	struct Point;

	/**
	*	传球（包括射门）动作
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
}