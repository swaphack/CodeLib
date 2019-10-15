#pragma once

#include "Bit.h"

namespace sys
{
	class Number
	{
	public:
		Number();
		virtual ~Number();
	public:
		virtual Number operator+(const Number& value);
		virtual Number operator-(const Number& value);
		virtual Number operator*(const Number& value);
		virtual Number operator/(const Number& value);

		virtual Number& operator+=(const Number& value);
		virtual Number& operator-=(const Number& value);
		virtual Number& operator*=(const Number& value);
		virtual Number& operator/=(const Number& value);

		virtual bool operator>(const Number& value);
		virtual bool operator>=(const Number& value);
		virtual bool operator<(const Number& value);
		virtual bool operator<=(const Number& value);
		virtual bool operator==(const Number& value);
		virtual bool operator!=(const Number& value);
	private:
		// �ڴ�����С
		uint64_t m_nCapactiy = 0;
		// ����
		uint8_t* m_pData = nullptr;
		// �߶ȳ��� ����1
		uint64_t m_nHeightLength = 0;
		// ��λ���� С��1
		uint64_t m_nLowLength = 0;
	};
}