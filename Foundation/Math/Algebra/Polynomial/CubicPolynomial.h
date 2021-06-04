#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	һԪ���ζ���ʽ
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
		*	����ϵ��
		*/
		void setCoefficient(float b, float c, float d);
		/**
		*	����ϵ��
		*/
		void setCoefficient(float a, float b, float c, float d);
	public:
		/**
		*	��ȡ������Ľ�
		*/
		std::vector<Complex> getEquationSolution();
	private:

	};
}