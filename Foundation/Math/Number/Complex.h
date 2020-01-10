#pragma once

#include "Number.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	����
	*/
	struct Complex : public Number
	{
	public:
		Complex();
		Complex(float rez, float imz);
		Complex(const Complex& complex);
	public:
		/**
		*	ʵ��
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(float, Rez, 0);
		/**
		*	�鲿
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
		*	ģ ����
		*/
		float getMagnitude() const;
		/**
		*	�����
		*/
		Complex getConjugate() const;
		/**
		*	�Ƕ�
		*/
		float getAngle() const;
		/**
		*	����
		*/
		void reset();
	};
}