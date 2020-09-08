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

math::Size::~Size()
{

}
