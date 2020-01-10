#pragma once

#include "Integer.h"
#include "Rational.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	����
	*/
	class Fraction : public Rational
	{
	public:
		Fraction();
		Fraction(const Integer& value);
		Fraction(const Integer& numerator, const Integer& denominator);
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Integer, Numerator, 0);
		/**
		*	��ĸ
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Integer, Denominator, 1);
	public:
		Fraction operator+(const Fraction& value) const;
		Fraction operator-(const Fraction& value) const;
		Fraction operator*(const Fraction& value) const;
		Fraction operator/(const Fraction& value) const;

		Fraction& operator+=(const Fraction& value);
		Fraction& operator-=(const Fraction& value);
		Fraction& operator*=(const Fraction& value);
		Fraction& operator/=(const Fraction& value);
	public:
		bool operator>(const Fraction& value) const;
		bool operator>=(const Fraction& value) const;
		bool operator<(const Fraction& value) const;
		bool operator<=(const Fraction& value) const;
		bool operator==(const Fraction& value) const;
		bool operator!=(const Fraction& value) const;
	};
}