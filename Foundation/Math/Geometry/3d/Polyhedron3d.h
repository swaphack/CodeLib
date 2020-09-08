#pragma once

#include <cstdint>
#include "Algebra/import.h"
#include "Basic/VariableLengthArray.h"

namespace math
{
	/**
	*	多面体
	*/
	template<const int Length, const int... Sizes>
	struct Polyhedron3d : public VariableLengthArray<math::Vector3, Length, Sizes>
	{
	public:
		Polyhedron3d()
		{
			
		}
		virtual ~Polyhedron3d()
		{

		}
	public:
		/**
		*	是否包含点
		*	各个坐标面的投影都包含点
		*/
		bool contiains(const Vector3& point)
		{

			Polygon2d pxoy;
			Polygon2d pyoz;
			Polygon2d pxoz;

			Vector2 pxy(point.getX(), point.getY());
			Vector2 pyz(point.getY(), point.getZ());
			Vector2 pxz(point.getX(), point.getZ());

			for (int32_t i = 0; i < Length; i++)
			{
				pxoy = Surface3d::projectOnXOY(this->getValue(i));
				pyoz = Surface3d::projectOnYOZ(this->getValue(i));
				pxoz = Surface3d::projectOnXOZ(this->getValue(i));

				if (pxoy.contains(pxy) || pyoz.contains(pyz) || pyoz.contains(pxz))
				{
					return true;
				}
			}

			return false;
		}
		/**
		*	两多面体是否相交
		*	
		*/
		bool intersects(const Polyhedron3d& polyhedron)
		{
			return false;
		}
	};
}