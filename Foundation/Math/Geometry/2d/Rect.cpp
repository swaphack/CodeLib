#include "Rect.h"

using namespace math;

Rect::Rect()
{

}

Rect::Rect(const Vector2& orgin, const Size& size)
{
	_origin = orgin;
	_size = size;
}

Rect::Rect(float x, float y, float w, float h)
{
	_origin.setX(x);
	_origin.setY(y);
	_size.setWidth(w);
	_size.setHeight(h);
}

float Rect::getMaxY() const
{
	return getY() + getHeight();
}

float Rect::getMinY() const
{
	return getY();
}

float Rect::getMaxX() const
{
	return getX() + getWidth();
}

float Rect::getMinX() const
{
	return _origin.getX();
}

float Rect::getHeight() const
{
	return _size.getHeight();
}

float Rect::getWidth() const
{
	return _size.getWidth();
}

float Rect::getY() const
{
	return _origin.getY();
}

float Rect::getX() const
{
	return _origin.getX();
}

void Rect::set(float x, float y, float w, float h)
{
	_origin.setX(x);
	_origin.setY(y);
	_size.setWidth(w);
	_size.setHeight(h);
}

void Rect::set(const Vector2& origin, const Size& size)
{
	_origin = origin;
	_size = size;
}

bool Rect::contains(const Vector2& point)
{
	return contains(point.getX(), point.getY());
}

bool Rect::contains(float x, float y)
{
	return (x >= getMinX() && x <= getMaxX())
		&& (y >= getMinY() && y <= getMaxY());
}

bool Rect::intersect(const Rect& rect)
{
	return intersect(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
}

bool Rect::intersect(float x, float y, float w, float h)
{
	return !(getMaxX() < x || x + w < getMinX() ||
		getMaxY() < y || y + h < getMinY());
}

Rect Rect::intersectRect(const Rect& rect)
{
	if (!intersect(rect))
	{
		return Rect();
	}

	Rect* pRect = &(Rect&)rect;

	Rect merge = unionRect(rect);
	float x0 = this->getMinX() == merge.getMinX() ? pRect->getMinX() : this->getMinX();
	float x1 = this->getMaxX() == merge.getMaxX() ? pRect->getMaxX() : this->getMaxX();
	float y0 = this->getMinY() == merge.getMinY() ? pRect->getMinY() : this->getMinY();
	float y1 = this->getMaxY() == merge.getMaxY() ? pRect->getMaxY() : this->getMaxY();

	return Rect(x0, y0, x1 - x0, y1 - y0);
}

Rect Rect::unionRect(const Rect& rect)
{
	Rect* pRect = &(Rect&)rect;

	float x0 = this->getMinX() < pRect->getMinX() ? this->getMinX() : pRect->getMinX();
	float x1 = this->getMaxX() > pRect->getMaxX() ? this->getMaxX() : pRect->getMaxX();
	float y0 = this->getMinY() < pRect->getMinY() ? this->getMinY() : pRect->getMinY();
	float y1 = this->getMaxY() > pRect->getMaxY() ? this->getMaxY() : pRect->getMaxY();

	return Rect(x0, y0, x1 - x0, y1 - y0);
}

Rect& Rect::operator=(const Rect& rect)
{
	_origin = rect._origin;
	_size = rect._size;
	return *this;
}

const Vector2& Rect::getOrigin() const
{
	return _origin;
}

const Size& Rect::getSize() const
{
	return _size;
}

Rect::~Rect()
{

}

void Rect::setOrigin(float x, float y)
{
	this->_origin.set(x, y);
}

void Rect::setSize(float x, float y)
{
	this->_size.set(x, y);
}
