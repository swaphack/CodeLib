#include "Ray.h"

using namespace math;

math::Ray::Ray(const Vector3& srcPoint, const Vector3& direction)
:_point(srcPoint)
,_direction(direction)
{
}

math::Ray::~Ray()
{
}

void math::Ray::setPoint(const Vector3& srcPoint)
{
	_point = srcPoint;
}

const Vector3& math::Ray::getPoint() const
{
	return _point;
}

void math::Ray::setDirection(const Vector3& direction)
{
	_direction = direction;
}

const Vector3& math::Ray::getDirection() const
{
	return _direction;
}
