#pragma once

namespace math
{
	// 复数
	struct Complex
	{
	public:
		// 实部
		float rez = 0;
		// 虚部
		float imz = 0;
	public:
		Complex();
		Complex(float rez, float imz);
		Complex(const Complex& complex);
	public:
		Complex operator+(const Complex& value);
		Complex operator-(const Complex& value);
		Complex operator*(const Complex& value);
		Complex operator/(const Complex& value);
		Complex operator*(float k);
		Complex operator/(float k);

		Complex& operator+=(const Complex& value);
		Complex& operator-=(const Complex& value);
		Complex& operator*=(const Complex& value);
		Complex& operator/=(const Complex& value);
		Complex& operator*=(float k);
		Complex& operator/=(float k);

		// 模 长度
		float getLength();
		// 共轭复数
		Complex getConjugate();
		// 角度
		float getAngle();
	protected:
	private:
	};
}