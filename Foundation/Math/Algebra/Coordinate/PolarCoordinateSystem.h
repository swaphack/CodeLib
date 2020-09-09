#pragma once

#include "CoordinateSystem.h"

namespace math
{
	/**
	*	¼«×ø±êÏµ
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
		*	°ë¾¶
		*/
		float _radius = 0;
	};
}