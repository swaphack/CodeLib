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
		virtual ~Matrix();
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
		/**
		*	������չϵ��
		*/
		Matrix operator*(float k);
		/**
		*	������չϵ��
		*/
		Matrix operator/(float k);
	public:
		/**
		*	���ƾ���Ԫ��
		*/
		Matrix& operator=(const Matrix& mat);
		/**
		*	��ȡת�þ���
		*/
		Matrix getTranspose() const;
		/**
		*	����ʽ��ֵ
		*/
		float getDetValue() const;
		/**
		*	����ʽ
		*/
		Matrix getMinor(int32_t i, int32_t j) const;
		/**
		*	�������
		*/
		Matrix getAdjoint() const;
		/**
		*	�����
		*/
		Matrix getInverse() const;
	};
}