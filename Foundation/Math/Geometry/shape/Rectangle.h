#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"

namespace math
{
	/**
	*	¾ØÐÎ
	*/
	struct Rectangle : public Points<Vector3, 4>
	{
	public:
		Rectangle();
		Rectangle(const Vector3& leftBottom, const Vector3& rightBottom, const Vector3& rightTop, const Vector3& leftTop);
		Rectangle(const Vector3* points);
		virtual ~Rectangle();
	public:
		CREATE_INDEX_VALUE(LeftBottom, 0, Vector3);
		CREATE_INDEX_VALUE(RightBottom, 1, Vector3);
		CREATE_INDEX_VALUE(RightTop, 3, Vector3);
		CREATE_INDEX_VALUE(LeftTop, 3, Vector3);
	};
}
