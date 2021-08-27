#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	一元二次多项式
	*	ax^2 + bx + c
	*/
	class UnaryQuadraticPolynomial : public UnaryPolynomial
	{
	public:
		UnaryQuadraticPolynomial();
		UnaryQuadraticPolynomial(float b, float c);
		UnaryQuadraticPolynomial(float a, float b, float c);
		virtual ~UnaryQuadraticPolynomial();
	public:
		/**
		*	设置系数
		*/
		void setCoefficient(float b, float c);
		/**
		*	设置系数
		*/
		void setCoefficient(float a, float b, float c);
	public:
		/**
		*	获取方程组的解
		*/
		std::vector<Complex> getEquationSolution();
	private:

	};
}