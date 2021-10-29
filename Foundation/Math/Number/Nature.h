#pragma once

#include "Integer.h"
#include <cstdint>

namespace math
{
	/**
	*	×ÔÈ»Êý
	*/
	class Nature : public Integer
	{
	public:
		Nature();
		Nature(uint8_t value);
		Nature(uint16_t value);
		Nature(uint32_t value);
		Nature(uint64_t value);
		Nature(const Nature& value);
	public:
		Nature operator+(const Nature& value) const;
		Nature operator-(const Nature& value) const;
		Nature operator*(const Nature& value) const;

		Nature& operator+=(const Nature& value);
		Nature& operator-=(const Nature& value);
		Nature& operator*=(const Nature& value);
	public:
		bool operator>(const Nature& value) const;
		bool operator>=(const Nature& value) const;
		bool operator<(const Nature& value) const;
		bool operator<=(const Nature& value) const;
		bool operator==(const Nature& value) const;
		bool operator!=(const Nature& value) const;
	public:
		Nature& operator=(uint8_t value);
		Nature& operator=(uint16_t value);
		Nature& operator=(uint32_t value);
		Nature& operator=(uint64_t value);
		Nature& operator=(const Nature& value);
	public:
		uint64_t value() const;
	public:
		operator uint8_t() const;
		operator uint16_t() const;
		operator uint32_t() const;
		operator uint64_t() const;
	private:
		uint64_t _value = 0;
	};
}