#pragma once

#include "Rational.h"
#include <cstdint>

namespace math
{
	/**
	*	整数
	*/
	class Integer : public Rational
	{
	public:
		Integer();
		Integer(int8_t value);
		Integer(int16_t value);
		Integer(int32_t value);
		Integer(int64_t value);
		Integer(uint8_t value);
		Integer(uint16_t value);
		Integer(uint32_t value);
		Integer(uint64_t value);
		Integer(const Integer& value);
	public:
		Integer operator+(const Integer& value) const;
		Integer operator-(const Integer& value) const;
		Integer operator*(const Integer& value) const;

		Integer& operator+=(const Integer& value);
		Integer& operator-=(const Integer& value);
		Integer& operator*=(const Integer& value);
	public:
		bool operator>(const Integer& value) const;
		bool operator>=(const Integer& value) const;
		bool operator<(const Integer& value) const;
		bool operator<=(const Integer& value) const;
		bool operator==(const Integer& value) const;
		bool operator!=(const Integer& value) const;
	public:
		Integer& operator=(int8_t value);
		Integer& operator=(int16_t value);
		Integer& operator=(int32_t value);
		Integer& operator=(int64_t value);
		Integer& operator=(uint8_t value);
		Integer& operator=(uint16_t value);
		Integer& operator=(uint32_t value);
		Integer& operator=(uint64_t value);
		Integer& operator=(const Integer& value);
	public:
		int64_t value() const;
		operator int8_t() const;
		operator int16_t() const;
		operator int32_t() const;
		operator int64_t() const;
		operator uint8_t() const;
		operator uint16_t() const;
		operator uint32_t() const;
		operator uint64_t() const;
	public:
		/**
		*	零因子
		*/
		static Integer zero();
		/**
		*	单位元
		*/
		static Integer identity();
	protected:
	private:
		int64_t _value = 0;
	};
}