#include "Complex.h"
#include <cassert>
#include <cmath>

using namespace math;

Complex::Complex()
{

}

Complex::Complex(float rez, float imz)
	: Complex()
{
	this->setRez(rez);
	this->setImz(imz);
}

Complex::Complex(const Complex& complex)
{
	this->setRez(complex.getRez());
	this->setImz(complex.getImz());
}

Complex Complex::operator+(const Complex& value) const
{
	return Complex(getRez() + value.getRez(), getImz() + value.getImz());
}

Complex Complex::operator-(const Complex& value) const
{
	return Complex(getRez() - value.getRez(), getImz() - value.getImz());
}

Complex Complex::operator*(const Complex& value) const
{
	return Complex(getRez() * value.getRez() - getImz() * value.getImz(), getRez() * value.getImz() + getImz() * value.getRez());
}

Complex Complex::operator*(float k) const
{
	return Complex(getRez() * k, getImz() * k);
}

Complex Complex::operator/(const Complex& value) const
{
	float a = getRez() * value.getRez() + getImz() * value.getImz();
	float b = getImz() * value.getRez() - getRez() * value.getImz();
	float c = pow(value.getRez(), 2) + pow(value.getImz(), 2);
	assert(c != 0);

	return Complex(a / c, b / c);
}

Complex Complex::operator/(float k) const
{
	assert(k != 0);
	return Complex(getRez() / k, getImz() / k);
}

Complex& Complex::operator+=(const Complex& value)
{
	setRez(getRez() + value.getRez());
	setImz(getImz() + value.getImz());
	return *this;
}

Complex& Complex::operator-=(const Complex& value)
{
	setRez(getRez() - value.getRez());
	setImz(getImz() - value.getImz());
	return *this;
}

Complex& Complex::operator*=(const Complex& value)
{
	float a = getRez() * value.getRez() - getImz() * value.getImz();
	float b = getRez() * value.getImz() + getImz() * value.getRez();

	setRez(a);
	setImz(b);
	return *this;
}

Complex& Complex::operator*=(float k)
{
	setRez(getRez() * k);
	setImz(getImz() * k);
	return *this;
}

Complex& Complex::operator/=(const Complex& value)
{
	float a = getRez() * value.getRez() + getImz() * value.getImz();
	float b = getImz() * value.getRez() - getRez() * value.getImz();
	float c = pow(value.getRez(),2) + pow(value.getImz(), 2);
	assert(c != 0);

	setRez(a / c);
	setImz(b / c);
	return *this;
}

Complex& Complex::operator/=(float k)
{
	assert(k != 0);
	setRez(getRez() / k);
	setRez(getImz() / k);
	return *this;
}

float Complex::getMagnitude() const
{
	return sqrtf(pow(getRez(), 2) + pow(getImz(), 2));
}

Complex Complex::getConjugate() const
{
	return Complex(getRez(), -getImz());
}

float Complex::getAngle() const
{
	return atan2f(getImz(), getRez());
}

void Complex::reset()
{
	setRez(0);
	setImz(0);
}
