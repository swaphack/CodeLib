#include "CSSSpace.h"

sys::CSSSpace::CSSSpace()
{
}

sys::CSSSpace::~CSSSpace()
{
}

void sys::CSSSpace::setLeft(NumberType eType, float value)
{
	_left.set(eType, value);
}

void sys::CSSSpace::setLeft(const CSSNumber& value)
{
	_left = value;
}

const sys::CSSNumber& sys::CSSSpace::getLeft() const
{
	return _left;
}

void sys::CSSSpace::setRight(NumberType eType, float value)
{
	_right.set(eType, value);
}

void sys::CSSSpace::setRight(const CSSNumber& value)
{
	_right = value;
}

const sys::CSSNumber& sys::CSSSpace::getRight() const
{
	return _right;
}

void sys::CSSSpace::setTop(NumberType eType, float value)
{
	_top.set(eType, value);
}

void sys::CSSSpace::setTop(const CSSNumber& value)
{
	_top = value;
}

const sys::CSSNumber& sys::CSSSpace::getTop() const
{
	return _top;
}

void sys::CSSSpace::setBottom(NumberType eType, float value)
{
	_bottom.set(eType, value);
}

void sys::CSSSpace::setBottom(const CSSNumber& value)
{
	_bottom = value;
}

const sys::CSSNumber& sys::CSSSpace::getBottom() const
{
	return _bottom;
}
