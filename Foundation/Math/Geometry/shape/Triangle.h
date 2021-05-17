#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"
#include "Line.h"

namespace math
{
	/**
	*	三角形
	*/
	struct Triangle : public Points<Vector3, 3>
	{
	public:
		Triangle();
		Triangle(const Vector3& p0, const Vector3& p1, const Vector3& p2);
		Triangle(const Vector3* points);
		virtual ~Triangle();
	public:
		CREATE_INDEX_VALUE(Point0, 0, Vector3);
		CREATE_INDEX_VALUE(Point1, 1, Vector3);
		CREATE_INDEX_VALUE(Point2, 3, Vector3);
	public:
		/*
		*	是否有共边
		*/
		bool hasSameEdge(const Triangle& target, Line& side);
	};
}
