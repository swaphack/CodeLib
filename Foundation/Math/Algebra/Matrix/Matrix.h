#pragma once

#include <cstdint>

#include "Basic/Array2D.h"

namespace math
{
	/**
	*	矩阵
	*/
	struct Matrix : public Array2D<float>
	{
	public:
		Matrix();
		Matrix(int h, int w);
		Matrix(float* value, int h, int w);
		virtual ~Matrix();
	public:
		/**
		*	矩阵相加
		*/
		Matrix operator+(const Matrix& mat);
		/**
		*	矩阵相减
		*/
		Matrix operator-(const Matrix& mat);
		/**
		*	矩阵相乘
		*/
		Matrix operator*(const Matrix& mat);
		/**
		*	矩阵相加
		*/
		Matrix& operator+=(const Matrix& mat);
		/**
		*	矩阵相减
		*/
		Matrix& operator-=(const Matrix& mat);
		/**
		*	矩阵扩展系数
		*/
		Matrix& operator*=(float k);
		/**
		*	矩阵扩展系数
		*/
		Matrix operator*(float k);
		/**
		*	矩阵扩展系数
		*/
		Matrix operator/(float k);
	public:
		/**
		*	复制矩阵元素
		*/
		Matrix& operator=(const Matrix& mat);
		/**
		*	获取转置矩阵
		*/
		Matrix getTranspose() const;
		/**
		*	行列式的值
		*/
		float getDetValue() const;
		/**
		*	余子式
		*/
		Matrix getMinor(int32_t i, int32_t j) const;
		/**
		*	伴随矩阵
		*/
		Matrix getAdjoint() const;
		/**
		*	逆矩阵
		*/
		Matrix getInverse() const;
	};
}