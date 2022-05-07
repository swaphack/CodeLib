#pragma once

#include "CoordinateSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	�ѿ�������ϵ
	*	ֱ������ϵ
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
		*	�Ƿ��ǵ�λ����ϵ
		*/
		bool isUnitSystem()
		{
			return base::_systemMatrix.isUnitMatrix();
		}

		
	protected:
	private:
	};

}
	