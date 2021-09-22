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
	return (this->_center - point).getSqrMagnitude() <= powf(this->_radius, 2);
}

bool math::SphereBB::contains(const Vector3& point)
{
	return (this->_center - point).getSqrMagnitude() <= powf(this->_radius, 2);
}

bool math::SphereBB::hitRay(const Ray& ray) const
{
	const auto& srcPoint = ray.getSrcPoint();
	const auto& direction = ray.getDirection();

	float a = direction.getSqrMagnitude();
	float b = 2 * direction.getX() * (srcPoint.getX() - _center.getX())
		+ 2 * direction.getY() * (srcPoint.getY() - _center.getY())
		+ 2 * direction.getZ() * (srcPoint.getZ() - _center.getZ());
	float c = _center.getSqrMagnitude() + srcPoint.getSqrMagnitude()
		- 2 * (_center.getX() * srcPoint.getX() + _center.getY() * srcPoint.getY() + _center.getZ() * srcPoint.getZ())
		- powf(this->_radius, 2);

	float delta = powf(b, 2) - 4 * a * c;

	return delta >= 0;
}
