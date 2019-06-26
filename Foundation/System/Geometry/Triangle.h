#pragma once

#include "Polygon.h"

namespace sys
{
	/**
	*	Èý½ÇÐÎ
	*/
	struct Triangle
	{
		Triangle(const Vector3& point32s0, const Vector3& point32s1, const Vector3& point32s2);
		Triangle(const Vector2& point32s0, const Vector2& point32s1, const Vector2& point32s2);
	};
}