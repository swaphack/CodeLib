#include "FontCharDetail.h"

sys::FontCharDetail::FontCharDetail()
{
}

sys::FontCharDetail::~FontCharDetail()
{
}
void sys::FontCharDetail::setAdvance(float x, float y)
{
	_advX = x;
	_advY = y;
}
void sys::FontCharDetail::setAdvanceX(float x)
{
	_advX = x;
}
void sys::FontCharDetail::setAdvanceY(float y)
{
	_advY = y;
}
int sys::FontCharDetail::getAdvanceX() const
{
	return _advX;
}
int sys::FontCharDetail::getAdvanceY() const
{
	return _advY;
}
void sys::FontCharDetail::setDelta(float x, float y)
{
	_deltaX = x;
	_deltaY = y;
}
void sys::FontCharDetail::setDeltaX(float x)
{
	_deltaX = x;
}
void sys::FontCharDetail::setDeltaY(float y)
{
	_deltaY = y;
}
int sys::FontCharDetail::getDeltaX() const
{
	return _deltaX;
}
int sys::FontCharDetail::getDeltaY() const
{
	return _deltaY;
}