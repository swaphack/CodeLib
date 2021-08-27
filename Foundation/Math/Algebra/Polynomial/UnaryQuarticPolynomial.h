#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	һԪ���ζ���ʽ
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
		*	����ϵ��
		*/
		void setCoefficient(float b, float c, float d, float e);
		/**
		*	����ϵ��
		*/
		void setCoefficient(float a, float b, float c, float d, float e);
	public:
		/**
		*	��ȡ������Ľ�
		*/
		std::vector<Complex> getEquationSolution();
	private:

	};
}