#include "Circle.h"
#include <cmath>

using namespace math;


Circle::Circle()
{

}

Circle::Circle(const Vector2& position, float radius)
{
	this->_position = position;
	this->_radius = radius;
}

Circle::Circle(const Circle& circle)
{
	this->_position = circle.getPosition();
	this->_radius = circle.getRadius();
}

Circle::~Circle()
{

}

const Vector2& Circle::getPosition() const
{
	return _position;
}

float Circle::getRadius() const
{
	return _radius;
}

bool Circle::contains(const Vector2& point)
{
	return pow(point.getX() - _position.getX(), 2) + pow(point.getY() - _position.getY(), 2) <= pow(_radius, 2);
}
