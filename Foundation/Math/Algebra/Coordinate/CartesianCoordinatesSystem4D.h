#pragma once

#include "CartesianCoordinatesSystem.h"

namespace math
{
	/**
	*	��ά�ѿ�������ϵ
	*/
	class CartesianCoordinatesSystem4D : public CartesianCoordinatesSystem<4>
	{
	public:
		CartesianCoordinatesSystem4D();
		virtual ~CartesianCoordinatesSystem4D();
	public:
		/**
		*	��������ϵ
		*/
		void loadIdentity();
	};
}