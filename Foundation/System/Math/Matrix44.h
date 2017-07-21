#pragma once

#include "Matrix.h"
#include "Vector3.h"

namespace sys
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
		void translate(const Vector3& vector);
		/**
		*	����
		*/
		void scale(const Vector3& vector);

		/**
		*	��ת
		*/
		void rotate(const Vector3& rotation);
		/**
		*	��x����ת
		*/
		void rotateX(float x);
		/**
		*	��y����ת
		*/
		void rotateY(float y);
		/**
		*	��z����ת
		*/
		void rotateZ(float z);
	public:
		/**
		*	��ת
		*/
		static Matrix44 createWithRotation(const Vector3& rotation);
		/**
		*	������ת����
		*/
		static Matrix44 createWithRotationByAxis(const Vector3& axis, float radian);
	};
}