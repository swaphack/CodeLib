#pragma once

#include "CartesianCoordinateSystem.h"

namespace math
{
	/**
	*	��ά�ѿ�������ϵ
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
		*	��������ϵ
		*/
		void loadIdentity();
	};
}
