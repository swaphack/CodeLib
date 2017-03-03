#pragma once

#include "Polygon.h"

namespace sys
{
	/**
	*	������
	*/
	struct Triangle
	{
		Triangle(const Vector3& points0, const Vector3& points1, const Vector3& points2);
		Triangle(const Vector2& points0, const Vector2& points1, const Vector2& points2);
	};
}