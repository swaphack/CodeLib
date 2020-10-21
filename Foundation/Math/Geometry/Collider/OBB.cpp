#include "OBB.h"

using namespace math;

OBB::OBB(const Vector3& center, const Vector3& volume, const Vector3& rotation)
{
	this->set(center, volume, rotation);
}

OBB::OBB(const Vector3& center, const Vector3& size)
:OBB(center, size, Vector3())
{
}

const Vector3& math::OBB::getVolume() const
{
	return _volume;
}

const Vector3& math::OBB::getRotation() const
{
	return _rotation;
}

void math::OBB::set(const Vector3& center, const Vector3& size, const Vector3& rotation)
{
	this->set(center, size);
	_rotation = rotation;
}

void math::OBB::set(const Vector3& center, const Vector3& size)
{
	_center = center;
	_volume = size;
}

bool OBB::contains(const Vector2& point)
{
	return false;
}

bool OBB::contains(const Vector3& point)
{
	return false;
}

bool OBB::contains(const LineSegment2d& line)
{
	return false;
}

bool OBB::contains(const LineSegment3d& line)
{
	return false;
}

bool math::OBB::intersects(const LineSegment2d& line)
{
	return false;
}

bool math::OBB::intersects(const LineSegment3d& line)
{
	return false;
}

bool OBB::contains(const OBB& bounds)
{
	return false;
}

bool OBB::intersects(const OBB& bounds)
{
	Vector3 nv = bounds._center - _center;
	

	//Matrix44 mat1;
	//mat1.rotate(bounds._rotation);

	return false;
}

void OBB::operator=(const OBB& obb)
{
	this->_center = obb._center;
	this->_volume = obb._volume;
	this->_rotation = obb._rotation;
}
