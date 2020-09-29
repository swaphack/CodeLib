#include "CSSSize.h"

sys::CSSSize::CSSSize()
{
}

sys::CSSSize::~CSSSize()
{
}

void sys::CSSSize::setWidth(NumberType eType, float value)
{
	_width.set(eType, value);
}

void sys::CSSSize::setWidth(const CSSNumber& value)
{
	_width = value;
}

const sys::CSSNumber& sys::CSSSize::getWidth() const
{
	return _width;
}

void sys::CSSSize::setHeight(NumberType eType, float value)
{
	_height.set(eType, value);
}

void sys::CSSSize::setHeight(const CSSNumber& value)
{
	_height = value;
}

const sys::CSSNumber& sys::CSSSize::getHeight() const
{
	return _height;
}
