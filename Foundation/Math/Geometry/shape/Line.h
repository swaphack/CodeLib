#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"

namespace math
{
	/**
	*	线段
	*/
	struct Line : public Points<Vector3, 2>
	{
	public:
		Line();
		Line(const Vector3& p0, const Vector3& p1);
		Line(const Vector3* points);
		virtual ~Line();
	public:
		CREATE_INDEX_VALUE(Point0, 0, Vector3);
		CREATE_INDEX_VALUE(Point1, 1, Vector3);
	public:
		/**
		*	相等
		*/
		bool operator==(const Line& line) const;
		/**
		*	不相等
		*/
		bool operator!=(const Line& line) const;
	};
}
