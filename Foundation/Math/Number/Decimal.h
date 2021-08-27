#pragma once

#include "Rational.h"

#include "Integer.h"
#include "Fraction.h"

namespace math
{
	/**
	*	Ð¡Êý
	*/
	class Decimal : public Rational
	{
	public:
		Decimal();
		Decimal(int32_t value);
		Decimal(float value);
		Decimal(double value);
		Decimal(long double value);
		Decimal(const Decimal& value);
		Decimal(const Integer& value);
		Decimal(const Fraction& value);
	public:
		Decimal operator+(const Decimal& value) const;
		Decimal operator-(const Decimal& value) const;
		Decimal operator*(const Decimal& value) const;
		Decimal operator/(const Decimal& value) const;

		Decimal& operator+=(const Decimal& value);
		Decimal& operator-=(const Decimal& value);
		Decimal& operator*=(const Decimal& value);
		Decimal& operator/=(const Decimal& value);
	public:
		bool operator>(const Decimal& value) const;
		bool operator>=(const Decimal& value) const;
		bool operator<(const Decimal& value) const;
		bool operator<=(const Decimal& value) const;
		bool operator==(const Decimal& value) const;
		bool operator!=(const Decimal& value) const;
	public:
		Decimal& operator=(float value);
		Decimal& operator=(double value);
		Decimal& operator=(long double value);
		Decimal& operator=(const Decimal& value);
		Decimal& operator=(const Integer& value);
		Decimal& operator=(const Fraction& value);
	public:
		double value() const;
		operator int() const;
		operator float() const;
		operator double() const;
		operator long double() const;
		operator Integer() const;
	private:
		long double _value = 0;
	};
}