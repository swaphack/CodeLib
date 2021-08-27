#include "UnaryQuadraticPolynomial.h"

math::UnaryQuadraticPolynomial::UnaryQuadraticPolynomial()
{
	this->setCoefficient(1, 1, 1);
}

math::UnaryQuadraticPolynomial::UnaryQuadraticPolynomial(float b, float c)
{
	this->setCoefficient(b, c);
}

math::UnaryQuadraticPolynomial::UnaryQuadraticPolynomial(float a, float b, float c)
{
	this->setCoefficient(a, b, c);
}

math::UnaryQuadraticPolynomial::~UnaryQuadraticPolynomial()
{
}

void math::UnaryQuadraticPolynomial::setCoefficient(float b, float c)
{
	this->setCoefficient(1, b, c);
}

void math::UnaryQuadraticPolynomial::setCoefficient(float a, float b, float c)
{
	this->removeAllTerms();
	this->setTerm(a, 2);
	this->setTerm(b, 1);
	this->setTerm(c, 0);
}

std::vector<math::Complex> math::UnaryQuadraticPolynomial::getEquationSolution()
{
	float a = getCoefficient(2);
	float b = getCoefficient(1);
	float c = getCoefficient(0);

	std::vector<Complex> result;

	float delta = powf(b, 2) - 4 * a * c;

	Complex sqrtD = Complex::sqrtToComplex(delta);
	
	if (a != 0)
	{
		Complex t1 = (Complex::toComplex(-b) + sqrtD) / Complex::toComplex(2 * a);
		Complex t2 = (Complex::toComplex(-b) - sqrtD) / Complex::toComplex(2 * a);
		result.push_back(t1);
		result.push_back(t2);
	}
	return result;
}
