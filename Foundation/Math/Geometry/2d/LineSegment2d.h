#pragma once

#include "Algebra/Vector/Vector2.h"
#include "Algebra/Vector/Vector3.h"
#include "Geometry/base/Points.h"

namespace math
{
	struct LineSegment2d : public Points<Vector2, 2>
	{
	public:
		LineSegment2d();
		LineSegment2d(const Vector2& src, const Vector2& dest);
		LineSegment2d(const Vector3& src, const Vector3& dest);
	public:
		CREATE_INDEX_VALUE(Src, 0, Vector2);
		CREATE_INDEX_VALUE(Dest, 1, Vector2);
	public:
		/**
		*	����
		*/
		float getMagnitude() const;
		/**
		*	��������
		*/
		Vector2 getVector() const;
		/**
		*	�������Ƿ��ཻ
		*/
		bool intersects(const LineSegment2d& line, Vector2& point) const;
	};
}