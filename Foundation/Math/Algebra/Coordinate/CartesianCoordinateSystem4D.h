#pragma once

#include "CartesianCoordinateSystem.h"

namespace math
{
	/**
	*	��ά�ѿ�������ϵ
	*/
	class CartesianCoordinateSystem4D : public CartesianCoordinateSystem<4>
	{
	public:
		CartesianCoordinateSystem4D();
		virtual ~CartesianCoordinateSystem4D();
	public:
		/**
		*	��������ϵ
		*/
		void loadIdentity();
	};
}