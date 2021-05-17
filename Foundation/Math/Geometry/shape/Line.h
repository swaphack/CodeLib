#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"

namespace math
{
	/**
	*	�߶�
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
		*	���
		*/
		bool operator==(const Line& line) const;
		/**
		*	�����
		*/
		bool operator!=(const Line& line) const;
	};
}
