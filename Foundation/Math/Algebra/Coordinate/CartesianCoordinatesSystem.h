#pragma once

#include "CurvilinearCoordinatesSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	�ѿ�������ϵ
	*	ֱ������ϵ
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
	