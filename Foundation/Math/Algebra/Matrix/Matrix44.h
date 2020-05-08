#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "Matrix41.h"

namespace math
{
	/**
	*	四阶方阵
	*	00 01 02 03
	*	10 11 12 13
	*	20 21 22 23
	*	30 31 32 33

	*	00 01 02 03
	*	04 05 06 07
	*	08 09 10 11
	*	12 13 14 15

	*	缩放 00,05,10
	*	位移 12,13,14
	*	旋转x 05 06 09 10
	*	旋转y 00 02 08 10
	*	旋转z 00 01 04 05
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
		*	标准化,单位矩阵
		*/
		void normalize();
		/**
		*	平移
		*/
		void setTranslate(const Vector3& vector);
		/**
		*	缩放
		*/
		void setScale(const Vector3& vector);
		/**
		*	旋转
		*/
		void setRotate(const Vector3& rotation);
		/**
		*	绕x轴旋转
		*/
		void setRotateX(float x);
		/**
		*	绕y轴旋转
		*/
		void setRotateY(float y);
		/**
		*	绕z轴旋转
		*/
		void setRotateZ(float z);
		/**
		*	绕轴旋转
		*/
		void setRotationByAxis(const Vector3& axis, float radian);
		/**
		*	绕轴线段旋转度数
		*/
		void setRotationByLine(const Vector3& src, const Vector3& dest, float radian);
		/**
		*	欧拉角
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