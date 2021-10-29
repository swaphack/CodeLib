#include "Size.h"

using namespace math;

Size::Size()
{

}

Size::Size(float w, float h)
{
	this->setWidth(w);
	this->setHeight(h);
}

Size::Size(const Vector2& size)
{
	this->setWidth(size.getX());
	this->setHeight(size.getY());
}

Size::Size(const Vector3& size)
{
	this->setWidth(size.getX());
	this->setHeight(size.getY());
}

Size::Size(const Size& size)
{
	this->setWidth(size.getWidth());
	this->setHeight(size.getHeight());
}

void Size::set(float w, float h)
{
	this->setWidth(w);
	this->setHeight(h);
}

bool math::Size::operator==(const Size& vec) const
{
	return getWidth() == vec.getWidth() && getHeight() == vec.getHeight();
}

bool math::Size::operator!=(const Size& vec) const
{
	return getWidth() != vec.getWidth() || getHeight() != vec.getHeight();
}

Size::operator Vector2() const
{
	return Vector2(getWidth(), getHeight());
}

math::Size::~Size()
{

}

/////////////////////////////////////////////////
IntSize::IntSize()
{

}

IntSize::IntSize(int w, int h)
{
	this->setWidth(w);
	this->setHeight(h);
}

IntSize::IntSize(const IntSize& size)
{
	this->setWidth(size.getWidth());
	this->setHeight(size.getHeight());
}

IntSize::~IntSize()
{
	
}

void IntSize::set(int w, int h)
{
	this->setWidth(w);
	this->setHeight(h);
}
