#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	一元二次多项式
	*	ax^3 + bx^2 + cx + d
	*/
	class CubicPolynomial : public UnaryPolynomial
	{
	public:
		CubicPolynomial();
		CubicPolynomial(float b, float c, float d);
		CubicPolynomial(float a, float b, float c, float d);
		virtual ~CubicPolynomial();
	public:
		/**
		*	设置系数
		*/
		void setCoefficient(float b, float c, float d);
		/**
		*	设置系数
		*/
		void setCoefficient(float a, float b, float c, float d);
	public:
		/**
		*	获取方程组的解
		*/
		std::vector<Complex> getEquationSolution();
	private:

	};
}