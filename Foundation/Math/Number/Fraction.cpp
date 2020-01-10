#include "Fraction.h"

#include <cassert>
using namespace math;


Fraction::Fraction()
{
	setNumerator(1);
	setDenominator(1);
}

Fraction::Fraction(const Integer& value)
{
	setNumerator(value);
	setDenominator(1);
}

Fraction::Fraction(const Integer& numerator, const Integer& denominator)
{
	assert(denominator.value() != Real::zero());

	setNumerator(numerator);
	setDenominator(denominator);
}

Fraction Fraction::operator+(const Fraction& value) const
{
	Integer a = this->getNumerator() * value.getDenominator() + this->getDenominator() * value.getNumerator();
	Integer b = this->getDenominator() * value.getDenominator();

	return Fraction(a, b);
}

Fraction Fraction::operator-(const Fraction& value) const
{
	Integer a = this->getNumerator() * value.getDenominator() - this->getDenominator() * value.getNumerator();
	Integer b = this->getDenominator() * value.getDenominator();

	return Fraction(a, b);
}

Fraction Fraction::operator*(const Fraction& value) const
{
	Integer a = this->getNumerator() * value.getNumerator();
	Integer b = this->getDenominator() * value.getDenominator();

	return Fraction(a, b);
}

Fraction Fraction::operator/(const Fraction& value) const
{
	Integer a = this->getNumerator() * value.getDenominator();
	Integer b = this->getDenominator() * value.getNumerator();

	return Fraction(a, b);
}

Fraction& Fraction::operator+=(const Fraction& value)
{
	Integer a = this->getNumerator() * value.getDenominator() + this->getDenominator() * value.getNumerator();
	Integer b = this->getDenominator() * value.getDenominator();

	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

Fraction& Fraction::operator-=(const Fraction& value)
{
	Integer a = this->getNumerator() * value.getDenominator() - this->getDenominator() * value.getNumerator();
	Integer b = this->getDenominator() * value.getDenominator();

	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

Fraction& Fraction::operator*=(const Fraction& value)
{
	Integer a = this->getNumerator() * value.getNumerator();
	Integer b = this->getDenominator() * value.getDenominator();

	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

Fraction& Fraction::operator/=(const Fraction& value)
{
	Integer a = this->getNumerator() * value.getDenominator();
	Integer b = this->getDenominator() * value.getNumerator();

	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

bool Fraction::operator>(const Fraction& value) const
{
	Fraction a = *this - value;

	return a.getDenominator() * a.getNumerator() > Integer::zero();
}

bool Fraction::operator>=(const Fraction& value) const
{
	Fraction a = *this - value;

	return a.getDenominator() * a.getNumerator() >= Integer::zero();
}

bool Fraction::operator<(const Fraction& value) const
{
	Fraction a = *this - value;

	return a.getDenominator() * a.getNumerator() < Integer::zero();
}

bool Fraction::operator<=(const Fraction& value) const
{
	Fraction a = *this - value;

	return a.getDenominator() * a.getNumerator() <= Integer::zero();
}

bool Fraction::operator==(const Fraction& value) const
{
	Fraction a = *this - value;

	return a.getDenominator() * a.getNumerator() == Integer::zero();
}

bool Fraction::operator!=(const Fraction& value) const
{
	Fraction a = *this - value;

	return a.getDenominator() * a.getNumerator() != Integer::zero();
}
