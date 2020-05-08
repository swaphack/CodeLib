#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "Matrix41.h"

namespace math
{
	/**
	*	�Ľ׷���
	*	00 01 02 03
	*	10 11 12 13
	*	20 21 22 23
	*	30 31 32 33

	*	00 01 02 03
	*	04 05 06 07
	*	08 09 10 11
	*	12 13 14 15

	*	���� 00,05,10
	*	λ�� 12,13,14
	*	��תx 05 06 09 10
	*	��תy 00 02 08 10
	*	��תz 00 01 04 05
	*/
	struct Matrix44 : public Matrix
	{
	public:
		Matrix44();
		Matrix44(const Matrix44& mat);
		Matrix44(const Matrix& mat);
		Matrix44(float* value);
		virtual ~Matrix44();
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
		//--------------------------------------------------------------------------------
		// set a ortho (right hand)
		// (left, right, bottom, top, near, far)
		//--------------------------------------------------------------------------------
		static Matrix44 ortho(float l, float r, float b, float t, float n, float f);
		//--------------------------------------------------------------------------------
		// set a perspective frustum (right hand)
		// (left, right, bottom, top, near, far)
		//--------------------------------------------------------------------------------
		static Matrix44 perspective(float l, float r, float b, float t, float n, float f);
		//--------------------------------------------------------------------------------
		// set a symmetric perspective frustum
		// ((vertical, degrees) field of view, (width/height) aspect ratio, near, far)
		//--------------------------------------------------------------------------------
		static Matrix44 verticalPerspective(float fov, float aspect, float front, float back);
		//--------------------------------------------------------------------------------
		// set a symmetric perspective frustum
		// ((horizontal, degrees) field of view, (width/height) aspect ratio, near, far)
		//--------------------------------------------------------------------------------
		static Matrix44 horizontalPerspective(float fov, float aspect, float front, float back);

		static Matrix44 lookAt(const Vector3& target, const Vector3& eye, const Vector3& up);
	public:
		virtual Matrix41 operator*(const Matrix41& mat);
		virtual Matrix44 operator*(const Matrix44& mat);
	};
}