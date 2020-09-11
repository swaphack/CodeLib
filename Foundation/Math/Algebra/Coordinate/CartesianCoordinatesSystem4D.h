#pragma once

#include "CartesianCoordinatesSystem.h"

namespace math
{
	/**
	*	四维笛卡尔坐标系
	*/
	class CartesianCoordinatesSystem4D : public CartesianCoordinatesSystem<4>
	{
	public:
		CartesianCoordinatesSystem4D();
		virtual ~CartesianCoordinatesSystem4D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	};
}