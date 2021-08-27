#include "UnaryCubicPolynomial.h"

math::UnaryCubicPolynomial::UnaryCubicPolynomial()
{
	this->setCoefficient(1, 1, 1, 1);
}

math::UnaryCubicPolynomial::UnaryCubicPolynomial(float b, float c, float d)
{
	this->setCoefficient(b, c, d);
}

math::UnaryCubicPolynomial::UnaryCubicPolynomial(float a, float b, float c, float d)
{
	this->setCoefficient(a, b, c, d);
}

math::UnaryCubicPolynomial::~UnaryCubicPolynomial()
{
}

void math::UnaryCubicPolynomial::setCoefficient(float b, float c, float d)
{
	this->setCoefficient(1, b, c, d);
}

void math::UnaryCubicPolynomial::setCoefficient(float a, float b, float c, float d)
{

	this->removeAllTerms();
	this->setTerm(a, 3);
	this->setTerm(b, 2);
	this->setTerm(c, 1);
	this->setTerm(d, 0);
}

std::vector<math::Complex> math::UnaryCubicPolynomial::getEquationSolution()
{
	float a = getCoefficient(3);
	float b = getCoefficient(2);
	float c = getCoefficient(1);
	float d = getCoefficient(0);

	float p = -1.0f / 3.0f * powf(a, 2) + b;
	float q = 2.0f / 27.0f * powf(a, 3) - 1.0f / 3.0f * a * b + c;

	float dp = p / 3.0f;
	float dq = q / 2.0f;

	float delta = -108.0f * (powf(dp, 3) + powf(dq, 2));
	float dDelta = powf(dp, 3) + powf(dq, 2);

	float theta = 1.0f / 3.0f * acosf(-dq / sqrtf(-powf(dp, 3)));

	Complex x1 = 2 * cosf(theta) * Complex::sqrtToComplex(-dp);
	Complex x2 = 2 * cosf(theta + 2.0f / 3.0f * M_PI) * Complex::sqrtToComplex(-dp);
	Complex x3 = 2 * cosf(theta - 2.0f / 3.0f * M_PI) * Complex::sqrtToComplex(-dp);

	std::vector<math::Complex> result;
	result.push_back(x1);
	result.push_back(x2);
	result.push_back(x3);

	return result;
}
