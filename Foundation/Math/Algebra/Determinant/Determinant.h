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
		Determinant(size_t order);
		Determinant(const float* val, size_t order);
		Determinant(const Determinant& det);
		virtual ~Determinant();
	public:
		/**
		*	����
		*/
		size_t getOrder() const;
		/**
		*	����
		*/
		void reset(size_t order);
		/**
		*	����
		*/
		void set(const float* val, size_t order);
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
		Determinant mul(float k, size_t row);
		/**
		*	���
		*/
		Determinant add(const Determinant& det, size_t row);
		/**
		*	ֵ
		*/
		float getMagnitude() const;
		/**
		*	����ʽ
		*/
		Determinant getMinor(size_t i, size_t j) const;
	public:
		/**
		*	��ȡ������
		*/
		static int getInverseNumber(float* data, int len);
	};
}