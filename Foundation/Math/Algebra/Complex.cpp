#include "Complex.h"
#include <cassert>
#include <cmath>

using namespace math;

Complex::Complex()
{

}

Complex::Complex(float rez, float imz)
	:rez(rez), imz(imz)
{

}

Complex::Complex(const Complex& complex)
{
	rez = complex.rez;
	imz = complex.imz;
}

Complex Complex::operator+(const Complex& value)
{
	return Complex(rez + value.rez, imz + value.imz);
}

Complex Complex::operator-(const Complex& value)
{
	return Complex(rez - value.rez, imz - value.imz);
}

Complex Complex::operator*(const Complex& value)
{
	return Complex(rez * value.rez - imz * value.imz, rez * value.imz + imz * value.rez);
}

Complex Complex::operator*(float k)
{
	return Complex(rez * k, imz * k);
}

Complex Complex::operator/(const Complex& value)
{
	float a = rez * value.rez + imz * value.imz;
	float b = imz * value.rez - rez * value.imz;
	float c = value.rez + value.imz;

	assert(c != 0);
	return Complex(a / c, b / c);
}

Complex Complex::operator/(float k)
{
	assert(k != 0);
	return Complex(rez / k, imz / k);
}

Complex& Complex::operator+=(const Complex& value)
{
	rez += value.rez;
	imz += value.imz;
	return *this;
}

Complex& Complex::operator-=(const Complex& value)
{
	rez -= value.rez;
	imz -= value.imz;
	return *this;
}

Complex& Complex::operator*=(const Complex& value)
{
	float a = rez * value.rez - imz * value.imz;
	float b = rez * value.imz + imz * value.rez;

	rez = a;
	imz = b;
	return *this;
}

Complex& Complex::operator*=(float k)
{
	rez *= k;
	imz *= k;
	return *this;
}

Complex& Complex::operator/=(const Complex& value)
{
	float a = rez * value.rez + imz * value.imz;
	float b = imz * value.rez - rez * value.imz;
	float c = pow(value.rez,2) + pow(value.imz, 2);
	assert(c != 0);

	rez = a / c;
	imz = b / c;

	return *this;
}

Complex& Complex::operator/=(float k)
{
	assert(k != 0);
	rez *= k;
	imz *= k;
	return *this;
}

float Complex::getLength()
{
	return sqrtf(pow(rez, 2) + pow(imz, 2));
}

Complex Complex::getConjugate()
{
	return Complex(rez, -imz);
}

float Complex::getAngle()
{
	return atan2f(imz, rez);
}

