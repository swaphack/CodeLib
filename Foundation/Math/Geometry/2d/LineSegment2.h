#pragma once

#include "Algebra/Vector/Vector2.h"
#include "Geometry/base/Points.h"

namespace math
{
	struct LineSegment2 : public Points<Vector2, 2>
	{
	public:
		LineSegment2();
		LineSegment2(Vector2 src, Vector2 dest);
	public:
		CREATE_INDEX_VALUE(Src, 0, Vector2);
		CREATE_INDEX_VALUE(Dest, 1, Vector2);
	public:
		/**
		*	长度
		*/
		float getMagnitude() const;
		/**
		*	方向向量
		*/
		Vector2 getVector() const;
		/**
		*	两向量是否相交
		*/
		bool intersects(const LineSegment2& line, Vector2& point);
	};
}