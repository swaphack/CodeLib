#include "Size.h"

using namespace math;

Size::Size()
	:Vector(2)
{

}

Size::Size(float w, float h)
	: Size()
{
	this->setWidth(w);
	this->setHeight(h);
}

Size::Size(const Size& size)
	:Size(size.getWidth(), size.getHeight())
{
}

void Size::set(float w, float h)
{
	this->setWidth(w);
	this->setHeight(h);
}

math::Size::~Size()
{

}
