#pragma once

#include "Geometry/base/Vector2.h"

namespace math
{
	struct LineSegment2
	{
	public:
		Vector2 src;
		Vector2 dest;
	public:
		LineSegment2();
		LineSegment2(Vector2 sr, Vector2 dest);
	public:

	};
}