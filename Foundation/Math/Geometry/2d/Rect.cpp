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

Rect::Rect(const Vector2& orgin, const Vector2& size)
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
	return getX();
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

bool Rect::contains(float x, float y) const
{
	return (x >= getMinX() && x <= getMaxX())
		&& (y >= getMinY() && y <= getMaxY());
}

bool Rect::contains(const Vector2& point) const
{
	return contains(point.getX(), point.getY());
}

bool math::Rect::contains(const Vector3& point) const
{
	return contains(point.getX(), point.getY());
}

bool math::Rect::contains(const Rect& rect) const
{
	return getMaxX() >= rect.getWidth()
		&& getMinX() <= rect.getMinX()
		&& getMaxY() >= rect.getHeight()
		&& getMinY() <= rect.getMinY();
}

bool math::Rect::includes(float x, float y) const
{
	return (x > getMinX() && x < getMaxX())
		&& (y > getMinY() && y < getMaxY());
}

bool math::Rect::includes(const Vector2& point) const
{
	return includes(point.getX(), point.getY());
}

bool math::Rect::includes(const Vector3& point) const
{
	return includes(point.getX(), point.getY());
}

bool math::Rect::includes(const Rect& rect) const
{
	return getMaxX() > rect.getWidth() 
		&& getMinX() < rect.getMinX()
		&& getMaxY() > rect.getHeight() 
		&& getMinY() < rect.getMinY();
}

Rect Rect::intersectRect(const Rect& rect) const
{
	if (!isOverlap(rect))
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

Rect Rect::unionRect(const Rect& rect) const
{
	Rect* pRect = &(Rect&)rect;

	float x0 = this->getMinX() < pRect->getMinX() ? this->getMinX() : pRect->getMinX();
	float x1 = this->getMaxX() > pRect->getMaxX() ? this->getMaxX() : pRect->getMaxX();
	float y0 = this->getMinY() < pRect->getMinY() ? this->getMinY() : pRect->getMinY();
	float y1 = this->getMaxY() > pRect->getMaxY() ? this->getMaxY() : pRect->getMaxY();

	return Rect(x0, y0, x1 - x0, y1 - y0);
}

bool math::Rect::isOverlap(const Rect& rect) const
{
	return (getMinX() >= rect.getMinX() && getMinX() >= rect.getMaxX())
		|| (getMinY() >= rect.getMinY() && getMinY() >= rect.getMaxY())
		|| (getMinX() >= rect.getMinX() && getMaxX() >= rect.getMaxX())
		|| (getMaxX() >= rect.getMinY() && getMaxY() >= rect.getMaxY());
}

math::Vector3 math::Rect::getAnchorPointByPosition(float x, float y)
{
	return math::Vector3();
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

void math::Rect::setOrigin(const Vector2& origin)
{
	this->_origin = origin;
}

void Rect::setSize(float x, float y)
{
	this->_size.set(x, y);
}

void math::Rect::setSize(const Size& size)
{
	this->_size = size;
}
