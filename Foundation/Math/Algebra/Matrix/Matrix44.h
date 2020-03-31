#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "Matrix41.h"

namespace math
{
	/**
	*	四阶方阵
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
		virtual Matrix41 operator*(const Matrix41& mat);
		virtual Matrix44 operator*(const Matrix44& mat);
	};
}