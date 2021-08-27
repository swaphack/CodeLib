#include "UnaryQuarticPolynomial.h"

math::UnaryQuarticPolynomial::UnaryQuarticPolynomial()
{
	this->setCoefficient(1, 1, 1, 1, 1);
}

math::UnaryQuarticPolynomial::UnaryQuarticPolynomial(float b, float c, float d, float e)
{
	this->setCoefficient(b, c, d, e);
}

math::UnaryQuarticPolynomial::UnaryQuarticPolynomial(float a, float b, float c, float d, float e)
{
	this->setCoefficient(a, b, c, d, e);
}

math::UnaryQuarticPolynomial::~UnaryQuarticPolynomial()
{
}

void math::UnaryQuarticPolynomial::setCoefficient(float b, float c, float d, float e)
{
	this->setCoefficient(1, b, c, d, e);
}

void math::UnaryQuarticPolynomial::setCoefficient(float a, float b, float c, float d, float e)
{
	this->removeAllTerms();
	this->setTerm(a, 4);
	this->setTerm(b, 3);
	this->setTerm(c, 2);
	this->setTerm(d, 1);
	this->setTerm(d, 0);
}

std::vector<math::Complex> math::UnaryQuarticPolynomial::getEquationSolution()
{
	float a = getCoefficient(4);
	float b = getCoefficient(3);
	float c = getCoefficient(2);
	float d = getCoefficient(1);
	float e = getCoefficient(0);

	std::vector<math::Complex> result;

	return result;
}
