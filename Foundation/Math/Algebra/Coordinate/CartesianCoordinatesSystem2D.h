#pragma once

#include "CartesianCoordinatesSystem.h"

namespace math
{
	/**
	*	��ά�ѿ�������ϵ
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
		*	��������ϵ
		*/
		void loadIdentity();
	};
}
