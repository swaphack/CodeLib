#pragma once
#include <cstdint>
#include <string>

#include "Basic/Array2D.h"

namespace math
{
	/**
	*	����ʽ
	*/
	struct Determinant : public Array2D<float>
	{
	public:
		Determinant();
		Determinant(int32_t order);
		Determinant(float* val, int32_t order);
		Determinant(const Determinant& det);
		virtual ~Determinant();
	public:
		/**
		*	����
		*/
		int32_t getOrder() const;
		/**
		*	����
		*/
		void reset(int32_t order);
		/**
		*	����
		*/
		void set(float* val, int32_t order);
	public:
		/**
		*	����ʽ���
		*/
		Determinant operator*(const Determinant& det);
	public:
		/**
		*	��ȡת��
		*/
		Determinant transpose();
		/**
		*	���
		*/
		Determinant mul(float k, int32_t row);
		/**
		*	���
		*/
		Determinant add(const Determinant& det, int32_t row);
		/**
		*	ֵ
		*/
		float getMagnitude() const;
	public:
		/**
		*	��ȡ������
		*/
		static int getInverseNumber(float* data, int len);
	};
}