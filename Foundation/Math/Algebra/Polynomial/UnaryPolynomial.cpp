#pragma once

#include "UnaryPolynomial.h"

using namespace math;


UnaryPolynomial::UnaryPolynomial()
{

}

UnaryPolynomial::UnaryPolynomial(const std::map<int, float>& mapTerm)
{
	for (auto item : mapTerm)
	{
		UnaryPolynomialTerm term(item.first, item.second);
		int id = term.getID();
		_mapTerm[id] = term;
	}
}

UnaryPolynomial::UnaryPolynomial(const UnaryPolynomial& value)
	:Polynomial(value)
{

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