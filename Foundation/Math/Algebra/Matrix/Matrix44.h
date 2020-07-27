#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector4.h"
#include "Matrix41.h"

namespace math
{
	struct Matrix33;
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
	struct Matrix44 : public Matrix<float, 4,4>
	{
	public:
		Matrix44();
		Matrix44(const Matrix<float, 4, 4>& mat);
		Matrix44(const Matrix44& mat);
		Matrix44(const Matrix41& mat);
		Matrix44(const Matrix33& mat);
		Matrix44(const float* value);
		virtual ~Matrix44();
	public:
		/**
		*	��׼��,��λ����
		*/
		void loadIdentity();
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
		Vector3 getEularAngle() const;
		/**
		*	λ��
		*/
		Vector3 getPosition() const;
		/**
		*	���ű���
		*/
		Vector3 getScale() const;
		/**
		*	��
		*/
		Vector4 getRow(int column) const;
		/**
		*	��
		*/
		void setRow(int column, const Vector4& value);
		/**
		*	��
		*/
		Vector4 getColumn(int column) const;
		/**
		*	��
		*/
		void setColumn(int column, const Vector4& value);
	public:
		Matrix41 operator*(const Matrix41& mat);
		Matrix44 operator*(const Matrix44& mat);
		Matrix44& operator=(const Matrix44& mat);
		Matrix44& operator=(const Matrix41& mat);
		Matrix44& operator=(const Matrix<float, 4, 4>& mat);
		Matrix44& operator=(const Matrix33& mat);
	public:
		//--------------------------------------------------------------------------------
		// set a ortho (right hand)
		// (left, right, bottom, top, near, far)
		//--------------------------------------------------------------------------------
		static Matrix44 ortho(float left, float right, float bottom, float top,
			float znear, float zfar);
		//--------------------------------------------------------------------------------
		// set a perspective frustum (right hand)
		// (left, right, bottom, top, near, far)
		//--------------------------------------------------------------------------------
		static Matrix44 frustum(float left, float right, float bottom, float top,
			float znear, float zfar);

		static Matrix44 perspective(float fovyInDegrees, float aspectRatio,	float znear, float zfar);

		static Matrix44 lookAt(const Vector3& eye, const Vector3& center, const Vector3& up);
		// rst
		static void getRST(const Vector3& rotate, const Vector3& scale, const Vector3& translate, Matrix44& outValue);
		// tsr
		static Matrix44 getTSR(const Vector3& translate, const Vector3& scale, const Vector3& rotate);
		// �������
		static Vector3 transpose(const Vector3& src, const Matrix44& mat);
	};
}