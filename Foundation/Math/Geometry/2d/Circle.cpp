#include "Circle.h"
#include <cmath>

using namespace math;


Circle::Circle()
{

}

Circle::Circle(const Vector3& position, float radius)
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

const Vector3& Circle::getPosition() const
{
	return _position;
}

float Circle::getRadius() const
{
	return _radius;
}

bool Circle::contains(const Vector3& point) const
{
	return (point - _position).getSqrMagnitude() < pow(_radius, 2);
}
