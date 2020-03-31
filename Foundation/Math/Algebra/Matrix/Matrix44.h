#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "Matrix41.h"

namespace math
{
	/**
	*	�Ľ׷���
	*/
	struct Matrix44 : public Matrix
	{
	public:
		Matrix44();
		Matrix44(const Matrix44& mat);
		Matrix44(const Matrix& mat);
		Matrix44(float* value);
	public:
		/**
		*	��׼��,��λ����
		*/
		void normalize();
		/**
		*	ƽ��
		*/
		void setTranslate(const Vector3& vector);
		/**
		*	����
		*/
		void setScale(const Vector3& vector);
		/**
		*	��ת
		*/
		void setRotate(const Vector3& rotation);
		/**
		*	��x����ת
		*/
		void setRotateX(float x);
		/**
		*	��y����ת
		*/
		void setRotateY(float y);
		/**
		*	��z����ת
		*/
		void setRotateZ(float z);
		/**
		*	������ת
		*/
		void setRotationByAxis(const Vector3& axis, float radian);
		/**
		*	�����߶���ת����
		*/
		void setRotationByLine(const Vector3& src, const Vector3& dest, float radian);
		/**
		*	ŷ����
		*/
		Vector3 getEularAngle();
	public:
		virtual Matrix41 operator*(const Matrix41& mat);
		virtual Matrix44 operator*(const Matrix44& mat);
	};
}