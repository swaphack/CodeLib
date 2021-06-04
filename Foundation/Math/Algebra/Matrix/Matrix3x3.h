#pragma once

#include "Matrix.h"
#include "../Vector/Vector2.h"
#include "Matrix4x4.h"
#include "SquareMatrix.h"

namespace math
{
	/**
	*	���׷���
	*/
	struct Matrix3x3 : public SquareMatrix3
	{
	public:
		Matrix3x3();
		Matrix3x3(const float* value);
		Matrix3x3(const Vector3& row0, const Vector3& row1, const Vector3& row2);
		Matrix3x3(const Matrix3x3& mat);
		Matrix3x3(const SquareMatrix3& mat);
		Matrix3x3(const SquareMatrix<float, 3>& mat);
		Matrix3x3(const Matrix4x4& mat);
		virtual ~Matrix3x3();
	public:
		/**
		*	��׼��,��λ����
		*/
		void loadIdentity();
		/**
		*	ƽ��
		*/
		void setTranslate(const Vector2& vector);

		/**
		*	����
		*/
		void setScale(const Vector2& vector);

		/**
		*	��ת
		*/
		void setRotate(float rotation);

		/**
		*	����
		*/
		void setShear(float radianX, float radianY);
	public:
		Matrix3x3& operator=(const Matrix4x4& mat);
		Matrix3x3& operator=(const Matrix3x3& mat);

		Matrix3x3 operator*(const Matrix3x3& mat);
		Vector3 operator*(const Vector3& v);

		operator SquareMatrix3();
	};
}