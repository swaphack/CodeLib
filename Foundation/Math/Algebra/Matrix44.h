#pragma once

#include "Matrix.h"
#include "Vector3.h"
#include "Matrix41.h"

namespace math
{
	/**
	*	�Ľ׷���
	*/
	struct Matrix44 : Matrix
	{
		Matrix44();
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
	};
}