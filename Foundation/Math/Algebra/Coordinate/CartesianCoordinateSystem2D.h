#pragma once

#include "CartesianCoordinateSystem.h"

namespace math
{
	/**
	*	二维笛卡尔坐标系
	*/
	class CartesianCoordinateSystem2D : public CartesianCoordinateSystem<2>
	{
	public:
		enum Axis2D
		{
			X,
			Y
		};
	public:
		CartesianCoordinateSystem2D();
		virtual ~CartesianCoordinateSystem2D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	};
}
