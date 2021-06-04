#pragma once
#include <cstdint>
#include <map>

#include "Polynomial.h"

namespace math
{
	/**
	*	һԪ����ʽ
	*/
	class UnaryPolynomial : public Polynomial
	{
	public:
		struct UnaryPolynomialTerm : public PolynomialTerm
		{
		public:
			UnaryPolynomialTerm() {}
			UnaryPolynomialTerm(float coefficient, int exponential)
			{
				this->setCoefficient(coefficient);
				std::map<int, int> exponentials;
				exponentials.insert(std::make_pair(PolynomialTermUnknowID::UnknowX, exponential));
				this->setExponentials(exponentials);
			}
			UnaryPolynomialTerm(const UnaryPolynomialTerm& value)
			{
				this->setCoefficient(value.getCoefficient());
				this->setExponentials(value.getExponentials());
			}
		protected:
			virtual int generateID()
			{
				if (_mapExponentials.size() == 0)
				{
					return 0;
				}

				return _mapExponentials.begin()->second;
			}
		};
	public:
		UnaryPolynomial();
		UnaryPolynomial(const std::map<float, int>& mapTerm);
		UnaryPolynomial(const UnaryPolynomial& value);
		/**
		*	��ߴ���
		*/
		UnaryPolynomial(int order);
		virtual~UnaryPolynomial();
	public:
		/**
		*	����
		*/
		int getOrder();
	public:
		/**
		*	������
		*/
		void setTerm(float coefficient, int exponential);
		/**
		*	��ȡָ����ָ����ϵ��
		*/
		float getCoefficient(int exponential);
	};
}