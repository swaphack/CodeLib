#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	������ϵ
	*/
	class PolarCoordinateSystem : public CoordinateSystem
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