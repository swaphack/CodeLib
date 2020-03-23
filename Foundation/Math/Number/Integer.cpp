#include "Integer.h"

using namespace math;


Integer::Integer()
{

}

Integer::Integer(int8_t value)
{
	*this = value;
}

Integer::Integer(int16_t value)
{
	*this = value;
}

Integer::Integer(int32_t value)
{
	*this = value;
}

Integer::Integer(int64_t value)
{
	*this = value;
}

Integer::Integer(uint8_t value)
{
	*this = value;
}

Integer::Integer(uint16_t value)
{
	*this = value;
}

Integer::Integer(uint32_t value)
{
	*this = value;
}

Integer::Integer(uint64_t value)
{
	*this = value;
}

Integer::Integer(const Integer& value)
{
	*this = value;
}

Integer Integer::operator+(const Integer& value) const
{
	return Integer(_value + value.value());
}

Integer Integer::operator-(const Integer& value) const
{
	return Integer(_value - value.value());
}

Integer Integer::operator*(const Integer& value) const
{
	return Integer(_value * value.value());
}

Integer& Integer::operator+=(const Integer& value)
{
	_value += value.value();
	return *this;
}

Integer& Integer::operator-=(const Integer& value)
{
	_value -= value.value();
	return *this;
}

Integer& Integer::operator*=(const Integer& value)
{
	_value *= value.value();
	return *this;
}

bool Integer::operator>(const Integer& value) const
{
	return _value > value.value();
}

bool Integer::operator>=(const Integer& value) const
{
	return _value >= value.value();
}

bool Integer::operator<(const Integer& value) const
{
	return _value < value.value();
}

bool Integer::operator<=(const Integer& value) const
{
	return _value <= value.value();
}

bool Integer::operator==(const Integer& value) const
{
	return _value == value.value();
}

bool Integer::operator!=(const Integer& value) const
{
	return _value != value.value();
}

Integer& Integer::operator=(int8_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(int16_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(int32_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(int64_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(uint8_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(uint16_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(uint32_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(uint64_t value)
{
	_value = value;
	return *this;
}

Integer& Integer::operator=(const Integer& value)
{
	_value = value.value(); 
	return *this;
}

Integer::operator int8_t() const
{
	return (int8_t)_value;
}

Integer::operator int16_t() const
{
	return (int16_t)_value;
}

Integer::operator int32_t() const
{
	return (int32_t)_value;
}

Integer::operator int64_t() const
{
	return (int64_t)_value;
}

Integer::operator uint8_t() const
{
	return (uint8_t)_value;
}

Integer::operator uint16_t() const
{
	return (uint16_t)_value;
}

Integer::operator uint32_t() const
{
	return (uint32_t)_value;
}

Integer::operator uint64_t() const
{
	return (uint64_t)_value;
}

int64_t Integer::value() const
{
	return _value;
}

Integer Integer::zero()
{
	return Integer(Real::zero());
}

Integer Integer::identity()
{
	return Integer(Real::identity());
}
