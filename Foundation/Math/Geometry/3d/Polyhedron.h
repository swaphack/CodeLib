#pragma once

#include <cstdint>
#include "Algebra/import.h"
#include "Basic/VariableLengthArray.h"

namespace math
{
	/**
	*	������
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
		*	�Ƿ������
		*	�����������ͶӰ��������
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
		*	���������Ƿ��ཻ
		*	
		*/
		bool intersects(const Polyhedron& polyhedron)
		{
			return false;
		}
	};
}