#pragma once

#include "CartesianCoordinateSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	三维笛卡尔坐标系
	*/
	class CartesianCoordinateSystem3D : public CartesianCoordinateSystem<3>
	{
	public:
		enum Axis3D
		{
			X,
			Y,
			Z,
		};
	public:
		CartesianCoordinateSystem3D();
		virtual ~CartesianCoordinateSystem3D();
	public:
		/**
		*	基本坐标系
		*/
		void loadIdentity();
	public:
		/**
		*	创建3d坐标系，点，轴，轴向量
		*/
		static CartesianCoordinateSystem3D create(const Vector3& point, const Vector3& vector, Axis3D eAxis);
		/**
		*	创建3d坐标系，点，轴，轴向量
		*/
		static CartesianCoordinateSystem3D createWithTwoPoints(const Vector3& srcPoint, const Vector3& destPoint, Axis3D eAxis);
	};
}