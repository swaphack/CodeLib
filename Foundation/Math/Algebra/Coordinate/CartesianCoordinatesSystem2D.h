#pragma once

#include "CartesianCoordinatesSystem.h"

namespace math
{
	/**
	*	二维笛卡尔坐标系
	*/
	class CartesianCoordinatesSystem2D : public CartesianCoordinatesSystem<2>
	{
	public:
		enum Axis2D
		{
			X,
			Y
		};
	public:
		CartesianCoordinatesSystem2D();
		virtual ~CartesianCoordinatesSystem2D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	};
}
