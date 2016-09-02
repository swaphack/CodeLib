#pragma once

#include "Vector.h"

namespace game
{
	/**
	*	抛物线
	*/
	struct Parabola
	{
		/**
		*	起球点
		*/
		Vector Src;
		/**
		*	三维角度
		*/
		Vector Direction;
		/**
		*	三维速度
		*/
		Vector Speed;
	};
}