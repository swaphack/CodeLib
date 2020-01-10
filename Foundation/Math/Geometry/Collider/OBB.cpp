#include "OBB.h"

using namespace math;

OBB::OBB(const Vector3& center, const Vector3& size, const Vector3& rotation)
:center(center)
, size(size)
, rotation(rotation)
{
	extents = size * 0.5f;

	//Matrix44 mat;
	//mat.rotate(rotation);

	Vector3 minp = center - extents;
	Vector3 maxp = center + extents;

	//Quaternion quaternion = Quaternion::rotate(rotation);
}

OBB::OBB(const Vector3& center, const Vector3& size)
:OBB(center, size, Vector3())
{
}

bool OBB::contains(const Vector2&  point32)
{
	return false;
}

bool OBB::contains(const Vector3& point32)
{
	return false;
}

bool OBB::contains(const LineSegment2& line)
{
	return false;
}

bool OBB::contains(const LineSegment& line)
{
	return false;
}

bool OBB::contains(const OBB& bounds)
{
	return false;
}

bool OBB::intersects(const OBB& bounds)
{
	Vector3 nv = bounds.center - center;
	

	//Matrix44 mat1;
	//mat1.rotate(bounds.rotation);

	return false;
}

void OBB::operator=(const OBB& obb)
{
	this->center = obb.center;
	this->size = obb.size;
	this->rotation = obb.rotation;
	this->extents = extents;
}
