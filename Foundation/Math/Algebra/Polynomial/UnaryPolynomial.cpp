#pragma once

#include "UnaryPolynomial.h"

using namespace math;


UnaryPolynomial::UnaryPolynomial()
{

}

UnaryPolynomial::UnaryPolynomial(const std::map<float, int>& mapTerm)
{
	for (auto item : mapTerm)
	{
		UnaryPolynomialTerm term(item.first, item.second);
		_mapTerm[item.second] = term;
	}
}

UnaryPolynomial::UnaryPolynomial(const UnaryPolynomial& value)
	:Polynomial(value)
{

}

math::UnaryPolynomial::UnaryPolynomial(int order)
{
	for (int i = 0; i <= order; i++)
	{
		UnaryPolynomialTerm term(0, i);
		_mapTerm[i] = term;
	}
}

UnaryPolynomial::~UnaryPolynomial()
{

}

int UnaryPolynomial::getOrder()
{
	int order = 0;
	for (auto item : _mapTerm)
	{
		if (item.first > order)
		{
			order = item.first;
		}
	}

	return order;
}

void math::UnaryPolynomial::setTerm(float coefficient, int exponential)
{
	auto it = _mapTerm.find(exponential);
	if (it != _mapTerm.end())
	{
		it->second.setCoefficient(coefficient);
	}
	else
	{
		UnaryPolynomialTerm term(coefficient, exponential);
		_mapTerm[exponential] = term;
	}
}

float math::UnaryPolynomial::getCoefficient(int exponential)
{
	auto it = _mapTerm.find(exponential);
	if (it != _mapTerm.end())
	{
		return it->second.getCoefficient();
	}

	return 0;
}
