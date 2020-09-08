#pragma once

#include "Polygon2d.h"

namespace math
{
	/**
	*	Èý½ÇÐÎ
	*/
	struct Triangle2d
	{
	protected:
		Vector2 point0;

		Triangle2d(const Vector2& point0, const Vector2& point1, const Vector2& point2);
	};
}