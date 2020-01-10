#include "Decimal.h"

#include <cassert>
#include "Integer.h"

using namespace math;

Decimal::Decimal()
{

}

Decimal::Decimal(float value)
{
	*this = value;
}

Decimal::Decimal(double value)
{
	*this = value;
}

Decimal::Decimal(const Decimal& value)
{
	*this = value;
}

Decimal::Decimal(const Integer& value)
{
	*this = value;
}

Decimal::Decimal(const Fraction& value)
{
	*this = value;
}

Decimal::Decimal(long double value)
{
	*this = value;
}

Decimal::Decimal(int32_t value)
{
	*this = Integer(value);
}

Decimal Decimal::operator+(const Decimal& value) const
{
	return Decimal(_value + value.value());
}

Decimal Decimal::operator-(const Decimal& value) const
{
	return Decimal(_value - value.value());
}

Decimal Decimal::operator*(const Decimal& value) const
{
	return Decimal(_value * value.value());
}

Decimal Decimal::operator/(const Decimal& value) const
{
	assert(value.value() != 0);

	return Decimal(_value / value.value());
}

Decimal& Decimal::operator+=(const Decimal& value)
{
	_value = _value + value.value();

	return *this;
}

Decimal& Decimal::operator-=(const Decimal& value)
{
	_value = _value - value.value();

	return *this;
}

Decimal& Decimal::operator*=(const Decimal& value)
{
	_value = _value * value.value();

	return *this;
}

bool Decimal::operator>(const Decimal& value) const
{
	return _value > value.value();
}

bool Decimal::operator>=(const Decimal& value) const
{
	return _value >= value.value();
}

bool Decimal::operator<(const Decimal& value) const
{
	return _value < value.value();
}

bool Decimal::operator<=(const Decimal& value) const
{
	return _value <= value.value();
}

bool Decimal::operator==(const Decimal& value) const
{
	return _value == value.value();
}

bool Decimal::operator!=(const Decimal& value) const
{
	return _value != value.value();
}

Decimal& Decimal::operator=(float value)
{
	_value = value;

	return *this;
}

Decimal& Decimal::operator=(double value)
{
	_value = value;
	return *this;
}

Decimal& Decimal::operator=(const Decimal& value)
{
	_value = value.value();
	return *this;
}

Decimal& Decimal::operator=(const Integer& value)
{
	_value = value.value();
	return *this;
}

Decimal& Decimal::operator=(const Fraction& value)
{
	_value = 1.0 * value.getNumerator().value() / value.getDenominator().value();
	return *this;
}

Decimal& Decimal::operator=(long double value)
{
	_value = value;
	return *this;
}

long double Decimal::value() const
{
	return _value;
}

Decimal::operator float() const
{
	return (float)_value;
}

Decimal::operator double() const
{
	return (double)_value;
}

Decimal::operator Integer() const
{
	return Integer((int64_t)floor(_value));
}

Decimal::operator long double() const
{
	return _value;
}



