#pragma once

#include "Integer.h"
#include "Rational.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	分数
	*/
	class Fraction : public Rational
	{
	public:
		Fraction();
		Fraction(const Integer& value);
		Fraction(const Integer& numerator, const Integer& denominator);
	public:
		/**
		*	分子
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Integer, Numerator, 0);
		/**
		*	分母
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