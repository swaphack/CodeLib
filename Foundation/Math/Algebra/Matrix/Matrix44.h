#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector4.h"
#include "Matrix41.h"

namespace math
{
	struct Matrix33;
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
		*	标准化,单位矩阵
		*/
		void loadIdentity();
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
		Vector3 getEularAngle() const;
		/**
		*	位置
		*/
		Vector3 getPosition() const;
		/**
		*	缩放比例
		*/
		Vector3 getScale() const;
		/**
		*	行
		*/
		Vector4 getRow(int column) const;
		/**
		*	行
		*/
		void setRow(int column, const Vector4& value);
		/**
		*	列
		*/
		Vector4 getColumn(int column) const;
		/**
		*	列
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
		// 坐标计算
		static Vector3 transpose(const Vector3& src, const Matrix44& mat);
	};
}