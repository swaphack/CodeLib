#include "SphereBB.h"

math::SphereBB::SphereBB(const Vector2& center, float radius)
{
	this->set(center, radius);
}

math::SphereBB::SphereBB(const Vector3& center, float radius)
{
	this->set(center, radius);
}

const float& math::SphereBB::getRadius() const
{
	return _radius;
}

void math::SphereBB::set(const Vector2& center, float radius)
{
	this->_center = center;
	this->_radius = radius;
}

void math::SphereBB::set(const Vector3& center, float radius)
{
	this->_center = center;
	this->_radius = radius;
}

bool math::SphereBB::contains(const Vector2& point)
{
	return (this->_center - point).getMagnitudeSqr() <= powf(this->_radius, 2);
}

bool math::SphereBB::contains(const Vector3& point)
{
	return (this->_center - point).getMagnitudeSqr() <= powf(this->_radius, 2);
}
