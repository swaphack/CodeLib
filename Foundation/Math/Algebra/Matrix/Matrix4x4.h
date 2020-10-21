#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector4.h"
#include "Matrix4x1.h"
#include "SquareMatrix.h"

namespace math
{
	struct Matrix3x3;
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
	struct Matrix4x4 : public SquareMatrix4
	{
	public:
		Matrix4x4();
		Matrix4x4(const Matrix<float, 4, 4>& mat);
		Matrix4x4(const Matrix4x4& mat);
		Matrix4x4(const Matrix4x1& mat);
		Matrix4x4(const Matrix3x3& mat);
		Matrix4x4(const SquareMatrix4& mat);
		Matrix4x4(const float* value);
		Matrix4x4(const float value[4][4]);
		virtual ~Matrix4x4();
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
		void setRotate(const Vector3& radian);
		/**
		*	错切
		*/
		void setShear(float radianX, float radianY, float radianZ);
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
		*	绕线段轴旋转度数
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

		/**
		*	x错切
		*/
		void setShearX(float radian);
		/**
		*	y错切
		*/
		void setShearY(float radian);
		/**
		*	z错切
		*/
		void setShearZ(float radianX);
	public:
		Matrix4x1 operator*(const Matrix4x1& mat);
		Matrix4x4 operator*(const Matrix4x4& mat);
		Matrix4x4& operator=(const Matrix4x4& mat);
		Matrix4x4& operator=(const Matrix4x1& mat);
		Matrix4x4& operator=(const Matrix<float, 4, 4>& mat);
		Matrix4x4& operator=(const Matrix3x3& mat);

		operator SquareMatrix4();
	public:
		//--------------------------------------------------------------------------------
		// set a ortho (right hand)
		// (left, right, bottom, top, near, far)
		//--------------------------------------------------------------------------------
		static Matrix4x4 ortho(float left, float right, float bottom, float top,
			float znear, float zfar);
		//--------------------------------------------------------------------------------
		// set a perspective frustum (right hand)
		// (left, right, bottom, top, near, far)
		//--------------------------------------------------------------------------------
		static Matrix4x4 frustum(float left, float right, float bottom, float top,
			float znear, float zfar);

		static Matrix4x4 perspective(float fovyInDegrees, float aspectRatio,	float znear, float zfar);

		static Matrix4x4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& up);
		// rst
		static void getRST(const Vector3& rotate, const Vector3& scale, const Vector3& translate, Matrix4x4& outValue);
		// tsr
		static Matrix4x4 getTSR(const Vector3& translate, const Vector3& scale, const Vector3& rotate);

		// 坐标计算
		static Vector3 transpose(const Vector3& src, const Matrix4x4& mat);

		// 主视图
		static Matrix4x4 getFrontViewMatrix();
		// 后视图
		static Matrix4x4 getBackViewMatrix();
		// 俯视图
		static Matrix4x4 getTopViewMatrix();
		// 仰视图
		static Matrix4x4 getBottomViewMatrix();
		// 左视图
		static Matrix4x4 getLeftViewMatrix();
		// 右视图
		static Matrix4x4 getRightViewMatrix();
	};
}