#pragma once

#include "UnaryPolynomial.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	һԪ���ζ���ʽ
	*	ax^2 + bx + c
	*/
	class QuadraticPolynomial : public UnaryPolynomial
	{
	public:
		QuadraticPolynomial();
		QuadraticPolynomial(float b, float c);
		QuadraticPolynomial(float a, float b, float c);
		virtual ~QuadraticPolynomial();
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