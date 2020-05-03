#pragma once

#include <cstdint>

#include "Complex.h"
#include "Basic/Array2D.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	矩阵
	*/
	struct Matrixi : public Array2D<Complex>
	{
	public:
		Matrixi(int h, int w);
		virtual ~Matrixi();
	public:
		/**
		*	矩阵相加
		*/
		virtual Matrixi operator+(const Matrixi& mat);
		/**
		*	矩阵相减
		*/
		virtual Matrixi operator-(const Matrixi& mat);
		/**
		*	矩阵相乘
		*/
		virtual Matrixi operator*(const Matrixi& mat);
		/**
		*	矩阵相加
		*/
		virtual Matrixi& operator+=(const Matrixi& mat);
		/**
		*	矩阵相减
		*/
		virtual Matrixi& operator-=(const Matrixi& mat);
		/**
		*	矩阵扩展系数
		*/
		virtual Matrixi& operator*=(float k);
	};
}