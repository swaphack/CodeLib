#include "Nature.h"

using namespace math;

Nature::Nature()
{

}

Nature::Nature(uint8_t value)
{
	*this = value;
}

Nature::Nature(uint16_t value)
{
	*this = value;
}

Nature::Nature(uint32_t value)
{
	*this = value;
}

Nature::Nature(uint64_t value)
{
	*this = value;
}

Nature::Nature(const Nature& value)
{
	*this = value;
}

Nature Nature::operator+(const Nature& value)const
{
	return Nature(_value + value.value());
}

Nature Nature::operator-(const Nature& value)const
{
	return Nature(_value - value.value());
}

Nature Nature::operator*(const Nature& value) const
{
	return Nature(_value * value.value());
}

Nature& Nature::operator+=(const Nature& value)
{
	_value += value.value();
	return *this;
}

Nature& Nature::operator-=(const Nature& value)
{
	_value -= value.value();
	return *this;
}

Nature& Nature::operator*=(const Nature& value)
{
	_value *= value.value();
	return *this;
}

bool Nature::operator>(const Nature& value) const
{
	return _value > value.value();
}

bool Nature::operator>=(const Nature& value) const
{
	return _value >= value.value();
}

bool Nature::operator<(const Nature& value) const
{
	return _value < value.value();
}

bool Nature::operator<=(const Nature& value) const
{
	return _value <= value.value();
}

bool Nature::operator==(const Nature& value) const
{
	return _value == value.value();
}

bool Nature::operator!=(const Nature& value) const
{
	return _value != value.value();
}

Nature& Nature::operator=(uint8_t value)
{
	_value = value;
	return *this;
}

Nature& Nature::operator=(uint16_t value)
{
	_value = value;
	return *this;
}

Nature& Nature::operator=(uint32_t value)
{
	_value = value;
	return *this;
}

Nature& Nature::operator=(uint64_t value)
{
	_value = value;
	return *this;
}

Nature& Nature::operator=(const Nature& value)
{
	_value = value.value();
	return *this;
}

uint64_t Nature::value() const
{
	return _value;
}

Nature::operator uint8_t() const
{
	return (uint8_t)_value;
}

Nature::operator uint16_t() const
{
	return (uint16_t)_value;
}

Nature::operator uint32_t() const
{
	return (uint32_t)_value;
}

Nature::operator uint64_t() const
{
	return (uint64_t)_value;
}

