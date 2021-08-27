#pragma once

#include <cstdlib>
#include "Algebra/import.h"
#include "Geometry/GeometryUtiity.h"
namespace math
{
	/**
	*	����
	*/
	template<typename T,
		const int Length,
		typename = std::enable_if<std::is_base_of<math::Vector3, T>::value, T>::type>
	struct Surface : public Array<T, Length>
	{
	public:
		Surface() {}
		Surface(const Surface& surface) 
		{
			this->assign(surface.getValue());
		}
		Surface(const T* poins)
		{
			this->assign(poins);
		}

		virtual ~Surface() {}
	public:
		/**
		*	������
		*/
		Vector3 normalVector() const
		{
			Vector3 v0 = (*this)[1] - (*this)[0];
			Vector3 v1 = (*this)[2] - (*this)[1];

			return Vector3::cross(v0, v1);
		}
		/**
		*	�Ƿ������
		*	���ж��Ƿ��棬���ж�ͶӰ�Ƿ����
		*/
		bool contains(const Vector3& point)
		{
			if (!isCoplanar(*this, point))
			{ // ������
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
		*	����=
		*/
		Surface& operator=(const Surface& surface)
		{
			this->assign(surface.getValue());
		}
	};
}