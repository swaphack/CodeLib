#pragma once

#include "CurvilinearCoordinateSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	�ѿ�������ϵ
	*	ֱ������ϵ
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
	