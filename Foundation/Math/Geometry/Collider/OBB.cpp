#include "OBB.h"
#include "AABB.h"

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
	return contains(Vector3(point));
}

bool OBB::contains(const Vector3& point)
{
	math::Matrix4x4 mat;
	math::Matrix4x4::getRST(_rotation, math::Vector3(1, 1, 1), _center, mat);

	math::Vector3 pos = math::Matrix4x4::transpose(point, mat.getInverse());

	AABB box(math::Vector3(0, 0, 0), _volume);

	return box.contains(pos);
}

bool OBB::contains(const LineSegment2d& line)
{
	return contains(line.getSrc()) && contains(line.getDest());
}

bool OBB::contains(const LineSegment3d& line)
{
	return contains(line.getSrc()) && contains(line.getDest());
}

bool math::OBB::intersects(const LineSegment2d& line)
{
	return contains(line.getSrc()) || contains(line.getDest());
}

bool math::OBB::intersects(const LineSegment3d& line)
{
	return contains(line.getSrc()) || contains(line.getDest());
}

void OBB::operator=(const OBB& obb)
{
	this->_center = obb._center;
	this->_volume = obb._volume;
	this->_rotation = obb._rotation;
}

bool math::OBB::hitRay(const Ray& ray) const
{


	return false;
}
