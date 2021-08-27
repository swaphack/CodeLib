#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	一元三次多项式
	*	ax^3 + bx^2 + cx + d
	*/
	class UnaryCubicPolynomial : public UnaryPolynomial
	{
	public:
		UnaryCubicPolynomial();
		UnaryCubicPolynomial(float b, float c, float d);
		UnaryCubicPolynomial(float a, float b, float c, float d);
		virtual ~UnaryCubicPolynomial();
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