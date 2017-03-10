#pragma once

#include "macros.h"

namespace sys
{
	struct Polygon;
	/**
	*	凸包
	*/
	struct Convex
	{
	public:
		/**
		*	判断由点构成的凸多边形
		*/
		static Polygon* createPolygon(Vector2* points, int count);
	};
}