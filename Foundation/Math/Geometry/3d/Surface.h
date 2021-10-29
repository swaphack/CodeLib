#pragma once

#include <cstdlib>
#include "Algebra/import.h"
#include "Geometry/GeometryUtiity.h"
namespace math
{
	/**
	*	表面
	*/
	template<const int Length>
	struct Surface : public Array<math::Vector3, Length>
	{
	public:
		Surface() {}
		Surface(const Surface& surface) 
		{
			this->assign(surface.getValue());
		}
		Surface(const std::vector<math::Vector3>& points)
		{
			this->assign(&points[0]);
		}
		Surface(const math::Vector3* points)
		{
			this->assign(points);
		}

		virtual ~Surface() {}
	public:
		/**
		*	法向量
		*/
		Vector3 normalVector() const
		{
			Vector3 v0 = (*this)[1] - (*this)[0];
			Vector3 v1 = (*this)[2] - (*this)[1];

			return Vector3::cross(v0, v1);
		}
		/**
		*	是否包含点
		*	先判断是否共面，再判断投影是否包含
		*/
		bool contains(const Vector3& point) const
		{
			if (!isCoplanar(*this, point))
			{ // 不共面
				return false;
			}

			Vector2 pxy(point.getX(), point.getY());
			Vector2 pyz(point.getY(), point.getZ());
			Vector2 pxz(point.getX(), point.getZ());

			Polygon pxoy(GeometryUtiity::projectSurfaceOnXOY(*this));
			Polygon pyoz(GeometryUtiity::projectSurfaceOnYOZ(*this));
			Polygon pxoz(GeometryUtiity::projectSurfaceOnXOZ(*this));

			if (pxoy.contains(pxy) || pyoz.contains(pyz) || pyoz.contains(pxz))
			{
				return true;
			}

			return false;
		}
		/**
		*	重载=
		*/
		Surface& operator=(const Surface& surface)
		{
			this->assign(surface.getValue());
		}
	};
}