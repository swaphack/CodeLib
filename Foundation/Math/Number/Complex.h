#pragma once

#include "Number.h"
#include "Basic/base.h"
#include "Algebra/Matrix/Matrix2x2.h"
#include <vector>
namespace math
{
	/**
	*	复数
	*/
	struct Complex : public Number
	{
	public:
		Complex();
		Complex(float rez, float imz);
		Complex(const Complex& complex);
	public:
		/**
		*	实部
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(float, Rez, 0);
		/**
		*	虚部
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(float, Imz, 0);
	public:
		Complex operator+(const Complex& value) const;
		Complex operator-(const Complex& value) const;
		Complex operator*(const Complex& value) const;
		Complex operator/(const Complex& value) const;
		Complex operator*(float k) const;
		Complex operator/(float k) const;

		Complex& operator+=(const Complex& value);
		Complex& operator-=(const Complex& value);
		Complex& operator*=(const Complex& value);
		Complex& operator/=(const Complex& value);
		Complex& operator*=(float k);
		Complex& operator/=(float k);
	public:
		/**
		*	模 长度
		*/
		float getMagnitude() const;
		/**
		*	共轭复数
		*/
		Complex getConjugate() const;
		/**
		*	角度
		*/
		float getAngle() const;
		/**
		*	重置
		*/
		void reset();
	public:
		/**
		*	矩阵
		*/
		operator Matrix2x2() const;
	public:
		/**
		*	转为复数
		*/
		static Complex toComplex(float value);
		/**
		*	平方根转为复数
		*/
		static Complex sqrtToComplex(float value);
		/**
		*	复数开根号
		*/
		static std::vector<Complex> squareRootOf(const Complex& value, int count);
	};

	static inline Complex operator*(float k, const Complex& value)
	{
		return value * k;
	}
}