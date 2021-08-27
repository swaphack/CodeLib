#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	һԪ���ζ���ʽ
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