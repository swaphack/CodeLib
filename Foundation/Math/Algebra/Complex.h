#pragma once

namespace math
{
	// ����
	struct Complex
	{
	public:
		// ʵ��
		float rez = 0;
		// �鲿
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

		// ģ ����
		float getLength();
		// �����
		Complex getConjugate();
		// �Ƕ�
		float getAngle();
	protected:
	private:
	};
}