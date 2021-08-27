#pragma once

#include "Algebra/import.h"
#include "Geometry/2d/LineSegment2d.h"
#include "Geometry/2d/Line2d.h"
#include "Geometry/base/Points.h"
#include <cstdint>
#include "Basic/base.h"

namespace math
{
	/**
	*	ƽ�漸�εĶ����
	*/
	template<const int Length>
	struct PolygonPoints : public Points<math::Vector2, Length>
	{
	public:
		PolygonPoints() {}
		PolygonPoints(const PolygonPoints& polygon)
		{
			this->assign(polygon.getValue());
		}
		PolygonPoints(const math::Vector2* vpoints)
		{
			this->assign(vpoints);
		}

		virtual ~PolygonPoints() {}
	public:
		/**
		*	����=
		*/
		PolygonPoints& operator=(const PolygonPoints& polygon)
		{
			this->assign(polygon.getValue());
		}
	};
}