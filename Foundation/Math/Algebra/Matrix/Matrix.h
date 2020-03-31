#pragma once

#include <cstdint>

#include "Basic/Array2D.h"

namespace math
{
	/**
	*	����
	*/
	struct Matrix : public Array2D<float>
	{
	public:
		Matrix();
		Matrix(int h, int w);
		Matrix(float* value, int h, int w);
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
	public:
		/**
		*	���ƾ���Ԫ��
		*/
		Matrix& operator=(const Matrix& mat);
		/**
		*	��ȡת�þ���
		*/
		Matrix transpose() const;
	};
}