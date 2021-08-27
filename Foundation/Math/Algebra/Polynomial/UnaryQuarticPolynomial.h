#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	一元二次多项式
	*	ax^4 + bx^3 + cx^2 + dx + e
	*/
	class UnaryQuarticPolynomial : public UnaryPolynomial
	{
	public:
		UnaryQuarticPolynomial();
		UnaryQuarticPolynomial(float b, float c, float d, float e);
		UnaryQuarticPolynomial(float a, float b, float c, float d, float e);
		virtual ~UnaryQuarticPolynomial();
	public:
		/**
		*	设置系数
		*/
		void setCoefficient(float b, float c, float d, float e);
		/**
		*	设置系数
		*/
		void setCoefficient(float a, float b, float c, float d, float e);
	public:
		/**
		*	获取方程组的解
		*/
		std::vector<Complex> getEquationSolution();
	private:

	};
}