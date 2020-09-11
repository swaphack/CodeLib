#pragma once

#include "CartesianCoordinatesSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	��ά�ѿ�������ϵ
	*/
	class CartesianCoordinatesSystem3D : public CartesianCoordinatesSystem<3>
	{
	public:
		enum Axis3D
		{
			X,
			Y,
			Z,
		};
	public:
		CartesianCoordinatesSystem3D();
		virtual ~CartesianCoordinatesSystem3D();
	public:
		/**
		*	��������ϵ
		*/
		void loadIdentity();
	public:
		/**
		*	����3d����ϵ���㣬�ᣬ������
		*/
		static CartesianCoordinatesSystem3D create(const Vector3& point, Axis3D eAxis, const Vector3& vector);
	};
}