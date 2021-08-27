#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"
#include "Geometry/2d/Rect.h"

namespace math
{
	/**
	*	¾ØÐÎ¶¥µã
	*/
	struct RectPoints : public Points<Vector3, 4>
	{
	public:
		RectPoints();
		RectPoints(const Vector3& leftBottom, const Vector3& rightBottom, const Vector3& rightTop, const Vector3& leftTop);
		RectPoints(const Vector3* points);
		virtual ~RectPoints();
	public:
		CREATE_INDEX_VALUE(LeftBottom, 0, Vector3);
		CREATE_INDEX_VALUE(RightBottom, 1, Vector3);
		CREATE_INDEX_VALUE(RightTop, 2, Vector3);
		CREATE_INDEX_VALUE(LeftTop, 3, Vector3);
	public:
		operator Rect();
	};
}
