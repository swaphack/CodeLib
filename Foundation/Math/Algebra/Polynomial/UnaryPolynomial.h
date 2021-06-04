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
		*	最高次数
		*/
		UnaryPolynomial(int order);
		virtual~UnaryPolynomial();
	public:
		/**
		*	次数
		*/
		int getOrder();
	public:
		/**
		*	设置项
		*/
		void setTerm(float coefficient, int exponential);
		/**
		*	获取指定幂指数的系数
		*/
		float getCoefficient(int exponential);
	};
}