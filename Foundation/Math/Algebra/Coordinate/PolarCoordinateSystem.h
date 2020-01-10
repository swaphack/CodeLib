#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	¼«×ø±êÏµ
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
		*	°ë¾¶
		*/
		float _radius = 0;
	};
}