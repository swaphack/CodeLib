#include "PolarCoordinateSystem.h"

math::PolarCoordinateSystem::PolarCoordinateSystem()
{

}

math::PolarCoordinateSystem::PolarCoordinateSystem(float radius)
{
	_radius = radius;
}

math::PolarCoordinateSystem::~PolarCoordinateSystem()
{

}

void math::PolarCoordinateSystem::setRadius(float value)
{
	_radius = value;
}

float math::PolarCoordinateSystem::getRadius() const
{
	return _radius;
}

math::Vector2 math::PolarCoordinateSystem::getXYPoint(float radian)
{
	return Vector2(_radius * cosf(radian), _radius * sinf(radian));
}

math::Complex math::PolarCoordinateSystem::getComplex(float radian)
{
	return Complex(_radius * cosf(radian), _radius * sinf(radian));
}
