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
	bool bFixed = _type == sys::NumberType::Fixed;

	return getCString("%f%s", bFixed ? _value : ONE_HUNDRED * _value, bFixed ? "" : PERCENT_NUMBER_SIGN);
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
		value.set(sys::NumberType::Percent, PERCENT_ONE * atof(content.subString(0, content.getSize() - 1).getString()));
	}
	else
	{
		value.set(sys::NumberType::Fixed, atof(content.getString()));
	}

	return value;
}

bool sys::CSSNumber::isFixedValue() const
{
	return _type == sys::NumberType::Fixed;
}

bool sys::CSSNumber::isPercentValue() const
{
	return _type == sys::NumberType::Percent;
}
