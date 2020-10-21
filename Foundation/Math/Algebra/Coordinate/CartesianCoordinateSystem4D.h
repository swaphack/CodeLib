#pragma once

#include "CartesianCoordinateSystem.h"

namespace math
{
	/**
	*	四维笛卡尔坐标系
	*/
	class CartesianCoordinateSystem4D : public CartesianCoordinateSystem<4>
	{
	public:
		CartesianCoordinateSystem4D();
		virtual ~CartesianCoordinateSystem4D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	};
}