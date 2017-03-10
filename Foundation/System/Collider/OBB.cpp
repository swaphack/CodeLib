#include "OBB.h"
#include "../Geometry/import.h"

using namespace sys;

OBB::OBB(const Vector3& center, const Vector3& size, const Vector3& rotation)
:center(center)
, size(size)
, rotation(rotation)
{

}

bool OBB::contains(const Vector2& point)
{
	return false;
}

bool OBB::contains(const Vector3& point)
{
	return false;
}

bool OBB::contains(const Line2& line)
{
	return false;
}

bool OBB::contains(const Line3& line)
{
	return false;
}

bool OBB::contains(const OBB& bounds)
{
	return false;
}

bool OBB::intersects(const OBB& bounds)
{
	Matrix44 matr0;
	matr0.rotate(rotation);

	float x00 = minX();
	float x01 = maxX();
	float y00 = minY();
	float y01 = maxY();
	float z00 = minZ();
	float z01 = maxZ();
	
	Vector3 points0[8];
	points0[0] = Vector3(x00, y00, z00);
	points0[1] = Vector3(x00, y01, z00);
	points0[2] = Vector3(x00, y00, z01);
	points0[3] = Vector3(x00, y01, z01);
	points0[4] = Vector3(x01, y00, z00);
	points0[5] = Vector3(x01, y01, z00);
	points0[6] = Vector3(x01, y00, z01);
	points0[7] = Vector3(x01, y01, z01);

	Matrix44 matr1;
	matr1.rotate(bounds.rotation);

	float x10 = bounds.minX();
	float x11 = bounds.maxX();
	float y10 = bounds.minY();
	float y11 = bounds.maxY();
	float z10 = bounds.minZ();
	float z11 = bounds.maxZ();

	Vector3 points1[8];
	points1[0] = Vector3(x10, y10, z10);
	points1[1] = Vector3(x10, y11, z10);
	points1[2] = Vector3(x10, y10, z11);
	points1[3] = Vector3(x10, y11, z11);
	points1[4] = Vector3(x11, y10, z10);
	points1[5] = Vector3(x11, y11, z10);
	points1[6] = Vector3(x11, y10, z11);
	points1[7] = Vector3(x11, y11, z11);

	Matrix matp(1, 4);
	int count = 8;
	for (int i = 0; i < count; i++)
	{
		matp[0] = points0[i].x;
		matp[1] = points0[i].y;
		matp[2] = points0[i].z;
		matp[3] = 1;

		matp *= matr0;

		points0[i].x = matp[0];
		points0[i].y = matp[1];
		points0[i].z = matp[2];

		matp[0] = points1[i].x;
		matp[1] = points1[i].y;
		matp[2] = points1[i].z;
		matp[3] = 1;

		matp *= matr1;

		points1[i].x = matp[0];
		points1[i].y = matp[1];
		points1[i].z = matp[2];
	}



	return false;
}

void OBB::operator=(const OBB& obb)
{
	this->center = obb.center;
	this->size = obb.size;
	this->rotation = obb.rotation;
}

float OBB::minX()
{
	return center.x - size.x * 0.5f;
}

float OBB::minY()
{
	return center.y - size.y * 0.5f;
}

float OBB::minZ()
{
	return center.z - size.z * 0.5f;
}

float OBB::maxX()
{
	return center.x + size.x * 0.5f;
}

float OBB::maxY()
{
	return center.y + size.y * 0.5f;
}

float OBB::maxZ()
{
	return center.z + size.z * 0.5f;
}

float OBB::minX() const
{
	return center.x - size.x * 0.5f;
}

float OBB::minY() const
{
	return center.y - size.y * 0.5f;
}

float OBB::minZ() const
{
	return center.z - size.z * 0.5f;
}

float OBB::maxX() const
{
	return center.x + size.x * 0.5f;
}

float OBB::maxY() const
{
	return center.y + size.y * 0.5f;
}

float OBB::maxZ() const
{
	return center.z + size.z * 0.5f;
}
