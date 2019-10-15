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
		// 内存分配大小
		uint64_t m_nCapactiy = 0;
		// 数据
		uint8_t* m_pData = nullptr;
		// 高度长度 大于1
		uint64_t m_nHeightLength = 0;
		// 地位长度 小于1
		uint64_t m_nLowLength = 0;
	};
}