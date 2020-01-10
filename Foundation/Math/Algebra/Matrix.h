#pragma once

#include <cstdint>

#include "Vector.h"
#include "Basic/Array2D.h"

namespace math
{
	/**
	*	����
	*/
	struct Matrix : public Array2D<float>
	{
	public:
		Matrix(int h, int w);
	public:
		/**
		*	�������
		*/
		Matrix operator+(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix operator-(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix operator*(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix& operator+=(const Matrix& mat);
		/**
		*	�������
		*/
		Matrix& operator-=(const Matrix& mat);
		/**
		*	������չϵ��
		*/
		Matrix& operator*=(float k);
	};
}