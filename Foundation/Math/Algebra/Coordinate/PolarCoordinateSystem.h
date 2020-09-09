#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	������ϵ
	*/
	template<const int Count>
	class PolarCoordinateSystem : public CoordinateSystem<Count>
	{
	public:
		PolarCoordinateSystem();
		PolarCoordinateSystem(float radius);
		virtual ~PolarCoordinateSystem();
	public:
	protected:
	private:
		/**
		*	�뾶
		*/
		float _radius = 0;
	};
}