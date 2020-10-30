#pragma once

#include "CartesianCoordinateSystem.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	��ά�ѿ�������ϵ
	*/
	class CartesianCoordinateSystem3D : public CartesianCoordinateSystem<3>
	{
	public:
		/// <summary>
		/// ��
		/// </summary>
		enum class Axis3D
		{
			X,
			Y,
			Z,
		};

		/// <summary>
		/// ���任
		/// </summary>
		enum class Axonometric
		{
			// ���Ȳ�߻�
			PositiveIsometric,
			// ������߻�
			PositiveTwoMeasurement,
			// б����߻�
			ObliqueTwoMeasurement,
		};
	public:
		CartesianCoordinateSystem3D();
		virtual ~CartesianCoordinateSystem3D();
	public:
		/**
		*	��������ϵ
		*/
		void loadIdentity();
	public:
		/**
		*	����3d����ϵ���㣬�ᣬ������
		*/
		static CartesianCoordinateSystem3D create(const Vector3& point, const Vector3& vector, Axis3D eAxis);
		/**
		*	����3d����ϵ���㣬�ᣬ������
		*/
		static CartesianCoordinateSystem3D createWithTwoPoints(const Vector3& srcPoint, const Vector3& destPoint, Axis3D eAxis);
		/**
		*	���任
		*/
		static CartesianCoordinateSystem3D createAxonometric(const Vector3& ratio, const Vector2& angle);
		/**
		*	���任
		*/
		static CartesianCoordinateSystem3D createAxonometric(Axonometric eType);
	};
}