#include "Line3.h"
#include "Plane.h"
#include "Matrix22.h"

#include <cassert>

using namespace math;

Line3::Line3(const Vector3& src, const Vector3& dest)
{
	_point = src;
	_direction = dest - src;
}

Line3::Line3(const Plane& plane0, const Plane& plane1)
{
	// Áî z = 0 ¼ÆËã×ø±ê
	Matrix22 d = Matrix22(plane0.getParamA(), plane0.getParamB(), plane1.getParamA(), plane1.getParamB());
	Matrix22 dx = Matrix22(-plane0.getParamD(), plane0.getParamB(), -plane1.getParamD(), plane1.getParamB());
	Matrix22 dy = Matrix22(plane0.getParamA(), -plane0.getParamD(), plane1.getParamA(), - plane1.getParamD());

	float base = d.getValue();

	assert(base != 0);

	_point = Vector3(dx.getValue() / base, dy.getValue() / base, 0);

	
	Vector3 n0 = plane0.normal();
	Vector3 n1 = plane1.normal();

	float x = n0.getY() * n1.getZ() - n0.getZ() * n1.getY();
	float y = n0.getZ() * n1.getX() - n0.getX() * n1.getZ();
	float z = n0.getX() * n1.getY() - n0.getY() * n1.getX();

	_direction = Vector3(x, y, z);
}

Line3::Line3(const Line3& line)
{
	_point = line.getPoint();
	_direction = line.getDirection();
}

Line3::~Line3()
{

}

const Vector3& Line3::getPoint() const
{
	return _point;
}

const Vector3& Line3::getDirection() const
{
	return _direction;
}

float Line3::getDistanceWithPoint(const Vector3& point)
{
	Vector3 vec = point - _point;
	
	float a = Vector3::cross(vec, _direction).getMagnitude();
	
	float b = _direction.getMagnitude();

	return a / b;
}

bool Line3::contains(const Vector3& point)
{
	Vector3 diff = point - _point;

	float a = diff.getX() / _direction.getX();
	float b = diff.getY() / _direction.getY();
	float c = diff.getZ() / _direction.getZ();

	return a == b && b == c;
}

bool Line3::isParallel(const Line3& line)
{
	Vector3 v0 = getDirection();
	Vector3 v1 = line.getDirection();

	return Vector3::cross(v0, v1).getMagnitude() == 0;
}

bool Line3::isIntersect(const Line3& line)
{
	if (isParallel(line))
	{
		return false;
	}

	Vector3 p0 = getPoint();
	Vector3 p1 = line.getPoint();

	Vector3 d = p1 - p0;

	Vector3 v0 = getDirection();
	Vector3 v1 = line.getDirection();

	Vector3 v = v1 - v0;
	return Vector3::cross(d, v).getMagnitude() == 0;


}
