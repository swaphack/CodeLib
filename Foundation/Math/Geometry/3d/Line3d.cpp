#include "Line3d.h"
#include "Plane.h"
#include "Algebra/import.h"

#include <cassert>

using namespace math;

Line3d::Line3d(const Vector3& src, const Vector3& dest)
{
	_point = src;
	_direction = dest - src;
}

Line3d::Line3d(const Plane& plane0, const Plane& plane1)
{
	// 令 z = 0 计算坐标
	Matrix2x2 d = Matrix2x2(plane0.getParamA(), plane0.getParamB(), plane1.getParamA(), plane1.getParamB());
	Matrix2x2 dx = Matrix2x2(-plane0.getParamD(), plane0.getParamB(), -plane1.getParamD(), plane1.getParamB());
	Matrix2x2 dy = Matrix2x2(plane0.getParamA(), -plane0.getParamD(), plane1.getParamA(), - plane1.getParamD());

	float base = d.getDetValue();

	assert(base != 0);

	_point = Vector3(dx.getDetValue() / base, dy.getDetValue() / base, 0);

	
	Vector3 n0 = plane0.getNormal();
	Vector3 n1 = plane1.getNormal();

	float x = n0.getY() * n1.getZ() - n0.getZ() * n1.getY();
	float y = n0.getZ() * n1.getX() - n0.getX() * n1.getZ();
	float z = n0.getX() * n1.getY() - n0.getY() * n1.getX();

	_direction = Vector3(x, y, z);
}

Line3d::Line3d(const Line3d& line)
{
	_point = line.getPoint();
	_direction = line.getDirection();
}

Line3d::~Line3d()
{

}

const Vector3& Line3d::getPoint() const
{
	return _point;
}

const Vector3& Line3d::getDirection() const
{
	return _direction;
}

float Line3d::getDistanceWithPoint(const Vector3& point)
{
	Vector3 vec = point - _point;
	
	float a = Vector3::cross(vec, _direction).getMagnitude();
	
	float b = _direction.getMagnitude();

	return a / b;
}

bool Line3d::contains(const Vector3& point)
{
	Vector3 diff = point - _point;

	float a = diff.getX() / _direction.getX();
	float b = diff.getY() / _direction.getY();
	float c = diff.getZ() / _direction.getZ();

	return a == b && b == c;
}

bool Line3d::isParallel(const Line3d& line)
{
	Vector3 v0 = getDirection();
	Vector3 v1 = line.getDirection();

	return Vector3::cross(v0, v1).getMagnitude() == 0;
}

bool Line3d::isIntersect(const Line3d& line)
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

bool math::Line3d::getIntersectPoint(const Line3d& line, Vector3& point)
{
	Vector3 v1 = Vector3::normalize(this->_direction);
	Vector3 v2 = Vector3::normalize(line.getDirection());

	float delta = v1.getSqrMagnitude() * v2.getSqrMagnitude() - powf(Vector3::dot(v1, v2), 2);

	if (delta == 0)
	{// 平行
		return false;
	}


	float s1 = 1.0f / delta * (
			v2.getSqrMagnitude() * Vector3::dot(line.getPoint() - this->getPoint(), v1)
			+ Vector3::dot(v1, v2) * Vector3::dot(this->getPoint() - line.getPoint(), v2)
		);

	point = this->getPoint() + s1 * this->getDirection();

	return true;
}
