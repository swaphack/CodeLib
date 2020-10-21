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
	struct Polyhedron : public VariableLengthArray<math::Vector3, Length, Sizes>
	{
	public:
		Polyhedron()
		{
			
		}
		virtual ~Polyhedron()
		{

		}
	public:
		/**
		*	是否包含点
		*	各个坐标面的投影都包含点
		*/
		bool contiains(const Vector3& point)
		{

			Polygon pxoy;
			Polygon pyoz;
			Polygon pxoz;

			Vector2 pxy(point.getX(), point.getY());
			Vector2 pyz(point.getY(), point.getZ());
			Vector2 pxz(point.getX(), point.getZ());

			for (int32_t i = 0; i < Length; i++)
			{
				pxoy = Surface::projectOnXOY(this->getValue(i));
				pyoz = Surface::projectOnYOZ(this->getValue(i));
				pxoz = Surface::projectOnXOZ(this->getValue(i));

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
		bool intersects(const Polyhedron& polyhedron)
		{
			return false;
		}
	};
}