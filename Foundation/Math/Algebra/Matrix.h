#pragma once

#include <cstdint>

#include "Vector.h"
#include "Basic/Array2D.h"

namespace math
{
	/**
	*	矩阵
	*/
	struct Matrix : public Array2D<float>
	{
	public:
		Matrix(int h, int w);
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
	};
}