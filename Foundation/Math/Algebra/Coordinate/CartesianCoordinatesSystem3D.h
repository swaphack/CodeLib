#pragma once

#include "CartesianCoordinatesSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	三维笛卡尔坐标系
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
		*	基本坐标系
		*/
		void loadIdentity();
	public:
		/**
		*	创建3d坐标系，点，轴，轴向量
		*/
		static CartesianCoordinatesSystem3D create(const Vector3& point, Axis3D eAxis, const Vector3& vector);
	};
}