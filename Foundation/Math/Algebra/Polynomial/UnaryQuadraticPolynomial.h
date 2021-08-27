#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	һԪ���ζ���ʽ
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
		*	����ϵ��
		*/
		void setCoefficient(float b, float c);
		/**
		*	����ϵ��
		*/
		void setCoefficient(float a, float b, float c);
	public:
		/**
		*	��ȡ������Ľ�
		*/
		std::vector<Complex> getEquationSolution();
	private:

	};
}