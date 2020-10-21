#pragma once

#include "Polygon2d.h"

namespace math
{
	/**
	*	Èý½ÇÐÎ
	*/
	struct Triangle
	{
	public
		Triangle(const Vector2& point0, const Vector2& point1, const Vector2& point2);
	protected:
		Polygon<3> _points;
	};
}