#pragma once

#include "Plane.h"

using namespace math;

Plane::Plane(const Vector3& point0, const Vector3& point1, const Vector3& point2)
{
	Vector3 v1 = point1 - point0;
	Vector3 v2 = point2 - point0;

	_paramA = v1.getY() * v2.getZ() - v1.getZ() * v2.getY();
	_paramB = -(v1.getX() * v2.getZ() - v1.getZ() * v2.getX());
	_paramC = v1.getX() * v2.getY() - v1.getY() * v2.getX();

	_paramD  = -point0.getX() * _paramA + point0.getY() * _paramB - point0.getZ() * _paramC;

	_normal = Vector3(_paramA, _paramB, _paramC);
}

Plane::Plane(const Vector3& point, const Vector3& normal)
{
	_paramA = normal.getX();
	_paramB = normal.getY();
	_paramC = normal.getZ();

	_paramD = -(_paramA * point.getX() + _paramB * point.getY() + _paramC * point.getZ());

	_normal = normal;
}

Plane::Plane(float a, float b, float c, float d)
{
	_paramA = a;
	_paramB = b;
	_paramC = c;
	_paramD = d;

	_normal = Vector3(a, b, c);
}

Plane::Plane(const Plane& plane)
{

}

Plane::~Plane()
{

}

float Plane::getParamA() const
{
	return _paramA;
}

float Plane::getParamB() const
{
	return _paramB;
}

float Plane::getParamC() const
{
	return _paramC;
}

const Vector3& Plane::getNormal() const
{
	return _normal;
}

float Plane::getParamD() const
{
	return _paramD;
}

float Plane::getDistanceWithPoint(const Vector3& point) const
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC * point.getZ() + _paramD;
	float b = sqrt(pow(_paramA, 2) + pow(_paramB, 2) + pow(_paramC, 2));

	return a / b;
}

bool math::Plane::getIntersectPointWithLine(const Line3d& line, Vector3& point) const
{
	float delta = Vector3::dot(_normal, line.getDirection());
	if (delta == 0)
	{// 与平面平行
		return false;
	}

	float t = -(Vector3::dot(_normal, line.getPoint()) + _paramD) / delta;
	if (t == 0)
	{// 在平面上
		return false;
	}
	point = line.getPoint() + t * line.getDirection();

	return true;
}

bool math::Plane::getIntersectLineWithPlane(const Plane& plane, Line3d& line) const
{
	Vector3 direction = Vector3::cross(this->getNormal(), plane.getNormal());

	Matrix3x3 mat;
	mat.setRow(0, math::Vector3(getParamA(), getParamB(), getParamC()));
	mat.setRow(1, math::Vector3(plane.getParamA(), plane.getParamB(), plane.getParamC()));
	mat.setRow(2, direction);

	float det = mat.getDetValue();
	if (det == 0)
	{
		return false;
	}

	Matrix3x3 inverse = mat.getInverse();

	Vector3 point = inverse * Vector3(-getParamD(), -plane.getParamD(), 0);

	line = Line3d(point, direction);

	return true;
}

bool math::Plane::getIntersectPointWithTwoPlanes(const Plane& plane1, const Plane& plane2, Vector3& point) const
{
	Matrix3x3 mat;
	mat.setRow(0, math::Vector3(getParamA(), getParamB(), getParamC()));
	mat.setRow(1, math::Vector3(plane1.getParamA(), plane1.getParamB(), plane1.getParamC()));
	mat.setRow(2, math::Vector3(plane2.getParamA(), plane2.getParamB(), plane2.getParamC()));

	float det = mat.getDetValue();
	if (det == 0)
	{
		return false;
	}

	Matrix3x3 inverse = mat.getInverse();

	point = inverse * Vector3(-getParamD(), -plane1.getParamD(), -plane2.getParamD());

	return false;
}
