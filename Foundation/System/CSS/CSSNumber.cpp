#include "CSSNumber.h"
#include "Base/macros.h"
#include "Type/String.h"

sys::CSSNumber::CSSNumber() 
{}

sys::CSSNumber::CSSNumber(NumberType eType, float value)
	:_type(eType),
	_value(value)
{

}

sys::CSSNumber& sys::CSSNumber::operator+=(const CSSNumber& value)
{
	ASSERT(value.getType() == getType());

	_value += value.getValue();

	return *this;
}

sys::CSSNumber& sys::CSSNumber::operator-=(const CSSNumber& value)
{
	ASSERT(value.getType() == getType());

	_value -= value.getValue();

	return *this;
}

bool sys::CSSNumber::operator==(const CSSNumber& value)
{
	return getType() == value.getType() && getValue() == value.getValue();
}

bool sys::CSSNumber::operator!=(const CSSNumber& value)
{
	return getType() != value.getType() || getValue() != value.getValue();
}

sys::CSSNumber sys::CSSNumber::operator+(const CSSNumber& value)
{
	ASSERT(value.getType() == getType());

	return CSSNumber(getType(), _value + value.getValue());
}

sys::CSSNumber sys::CSSNumber::operator-(const CSSNumber& value)
{
	ASSERT(value.getType() == getType());

	return CSSNumber(getType(), _value - value.getValue());
}

sys::CSSNumber& sys::CSSNumber::operator=(const CSSNumber& value)
{
	_type = value.getType();
	_value = value.getValue();

	return *this;
}

sys::NumberType sys::CSSNumber::getType() const
{
	return _type;
}

void sys::CSSNumber::setType(NumberType eType)
{
	_type = eType;
}

float sys::CSSNumber::getValue() const
{
	return _value;
}

float sys::CSSNumber::getRealValue() const
{
	if (isFixedValue()) return _value;
	else if(isPercentValue()) return _value * PERCENT_ONE;
	return _value;
}

float sys::CSSNumber::getRealValue(float value) const
{
	if (isFixedValue()) return _value;
	else if (isPercentValue()) return value * _value * PERCENT_ONE;
	return value;
}

float sys::CSSNumber::getRealValueWithDefault(float defaultValue) const
{
	if (isFixedValue()) return _value;
	else if (isPercentValue()) return _value * PERCENT_ONE;
	return defaultValue;
}

float sys::CSSNumber::getRealValueWithDefault(float value, float defaultValue) const
{
	if (isFixedValue()) return _value;
	else if (isPercentValue()) return value * _value * PERCENT_ONE;
	return defaultValue;
}

void sys::CSSNumber::setValue(float value)
{
	_value = value;
}

void sys::CSSNumber::set(NumberType eType, float value)
{
	_type = eType;
	_value = value;
}

std::string sys::CSSNumber::toString() const
{
	std::string str = getCString("%f", _value);
	if (isPercentValue())
	{
		str += "%";
	}

	return str;
}

std::string sys::CSSNumber::toString(int digits) const
{
	std::string spotFormat = getCString("0.%d", digits);
	spotFormat = "%" + spotFormat + "f";
	std::string str = getCString(spotFormat.c_str(), _value);
	if (isPercentValue())
	{
		str += "%";
	}

	return str;
}

sys::CSSNumber sys::CSSNumber::load(const std::string& text)
{
	CSSNumber value;

	if (text.empty())
	{
		value.set(NumberType::Fixed, 0);

		return value;
	}

	String content = text;
	if (content.endWith(PERCENT_NUMBER_SIGN))
	{
		value.set(sys::NumberType::Percent, atof(content.subString(0, content.getSize() - 1).getString()));
	}
	else
	{
		value.set(sys::NumberType::Fixed, atof(content.getString()));
	}

	return value;
}

bool sys::CSSNumber::isRelativeType() const
{
	return isFixedValue() || isPercentValue();
}

bool sys::CSSNumber::isFixedValue() const
{
	return _type == sys::NumberType::Fixed;
}

bool sys::CSSNumber::isPercentValue() const
{
	return _type == sys::NumberType::Percent;
}
