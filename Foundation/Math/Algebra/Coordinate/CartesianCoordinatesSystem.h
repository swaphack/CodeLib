#pragma once

#include "CurvilinearCoordinatesSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	笛卡尔坐标系
	*	直角坐标系
	*/
	template<const int Count>
	class CartesianCoordinatesSystem : public CurvilinearCoordinatesSystem<Count>
	{
	public:
		CartesianCoordinatesSystem()
		{}
		virtual ~CartesianCoordinatesSystem()
		{}
	public:

	protected:
	private:
	};

}
	