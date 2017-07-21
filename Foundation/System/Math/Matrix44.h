#pragma once

#include "Matrix.h"
#include "Vector3.h"

namespace sys
{
	/**
	*	四阶方阵
	*/
	struct Matrix44 : Matrix
	{
		Matrix44();
		/**
		*	标准化,单位矩阵
		*/
		void normalize();
		/**
		*	平移
		*/
		void translate(const Vector3& vector);
		/**
		*	缩放
		*/
		void scale(const Vector3& vector);

		/**
		*	旋转
		*/
		void rotate(const Vector3& rotation);
		/**
		*	绕x轴旋转
		*/
		void rotateX(float x);
		/**
		*	绕y轴旋转
		*/
		void rotateY(float y);
		/**
		*	绕z轴旋转
		*/
		void rotateZ(float z);
	public:
		/**
		*	旋转
		*/
		static Matrix44 createWithRotation(const Vector3& rotation);
		/**
		*	绕轴旋转度数
		*/
		static Matrix44 createWithRotationByAxis(const Vector3& axis, float radian);
	};
}