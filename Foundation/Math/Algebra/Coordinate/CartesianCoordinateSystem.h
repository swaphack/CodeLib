#pragma once

#include "CurvilinearCoordinateSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	笛卡尔坐标系
	*	直角坐标系
	*/
	template<const int Count>
	class CartesianCoordinateSystem : public CurvilinearCoordinateSystem<Count>
	{
	public:
		CartesianCoordinateSystem()
		{}
		virtual ~CartesianCoordinateSystem()
		{}
	public:

	protected:
	private:
	};

}
	