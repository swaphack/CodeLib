#pragma once
#include <cstdint>
#include <string>

#include "Basic/Array2D.h"

namespace math
{
	/**
	*	行列式
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
		*	阶数
		*/
		size_t getOrder() const;
		/**
		*	重置
		*/
		void reset(size_t order);
		/**
		*	设置
		*/
		void set(const float* val, size_t order);
	public:
		/**
		*	行列式相乘
		*/
		Determinant operator*(const Determinant& det);
	public:
		/**
		*	获取转置
		*/
		Determinant transpose();
		/**
		*	相乘
		*/
		Determinant mul(float k, size_t row);
		/**
		*	相加
		*/
		Determinant add(const Determinant& det, size_t row);
		/**
		*	值
		*/
		float getMagnitude() const;
		/**
		*	余子式
		*/
		Determinant getMinor(size_t i, size_t j) const;
	public:
		/**
		*	获取逆序数
		*/
		static int getInverseNumber(float* data, int len);
	};
}