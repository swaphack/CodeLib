#pragma once

#include "CoordinateSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	笛卡尔坐标系
	*	直角坐标系
	*/
	template<const int Count>
	class CartesianCoordinateSystem : public CoordinateSystem<Count>
	{
		typedef CoordinateSystem<Count> base;
	public:
		CartesianCoordinateSystem()
		{}
		virtual ~CartesianCoordinateSystem()
		{}
	public:
		/**
		*	是否是单位坐标系
		*/
		bool isUnitSystem()
		{
			return base::_systemMatrix.isUnitMatrix();
		}

		
	protected:
	private:
	};

}
	