#pragma once

#include "Polygon.h"
#include "Geometry/base/Vector2.h"

namespace math
{
	/**
	*	������
	*/
	struct Triangle
	{
	protected:
		Vector2 point0;

		Triangle(const Vector2& point0, const Vector2& point1, const Vector2& point2);
	};
}