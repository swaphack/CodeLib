#pragma once
#include <cstdint>
#include <map>

#include "Polynomial.h"

namespace math
{
	/**
	*	一元多项式
	*/
	class UnaryPolynomial : public Polynomial
	{
	public:
		struct UnaryPolynomialTerm : public PolynomialTerm
		{
		public:
			UnaryPolynomialTerm() {}
			UnaryPolynomialTerm(float coefficient, float exponential)
			{
				this->setCoefficient(coefficient);
				std::map<int, float> exponentials;
				exponentials.insert(std::make_pair(1, exponential));
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

				return _mapExponentials.begin()->first;
			}
		};
	public:
		UnaryPolynomial();
		UnaryPolynomial(const std::map<float, float>& mapTerm);
		UnaryPolynomial(const UnaryPolynomial& value);
		virtual~UnaryPolynomial();
	public:
		/**
		*	次数
		*/
		int getOrder();
	};
}