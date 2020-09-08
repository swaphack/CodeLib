#include "Circle2d.h"
#include <cmath>

using namespace math;


Circle2d::Circle2d()
{

}

Circle2d::Circle2d(const Vector2& position, float radius)
{
	this->_position = position;
	this->_radius = radius;
}

Circle2d::Circle2d(const Circle2d& circle)
{
	this->_position = circle.getPosition();
	this->_radius = circle.getRadius();
}

Circle2d::~Circle2d()
{

}

const Vector2& Circle2d::getPosition() const
{
	return _position;
}

float Circle2d::getRadius() const
{
	return _radius;
}

bool Circle2d::contains(const Vector2& point)
{
	return pow(point.getX() - _position.getX(), 2) + pow(point.getY() - _position.getY(), 2) <= pow(_radius, 2);
}
