#include "BoundingBox.h"

math::BoundingBox::BoundingBox()
{
}

math::BoundingBox::BoundingBox(const Vector3& center)
{
	this->setCenter(center);
}

math::BoundingBox::~BoundingBox()
{
}

void math::BoundingBox::setCenter(const Vector3& center)
{
	_center = center;
}

const math::Vector3& math::BoundingBox::getCenter() const
{
	return _center;
}

bool math::BoundingBox::contains(const Vector2& point) const
{
	return false;
}

bool math::BoundingBox::contains(const Vector3& point) const
{
	return false;
}

bool math::BoundingBox::hitRay(const Ray& ray) const
{
	return false;
}
