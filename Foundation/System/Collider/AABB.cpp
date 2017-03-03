#include "AABB.h"
#include "../Geometry/import.h"

using namespace sys;

AABB::AABB(const Vector3& center, const Vector3& size)
:center(center)
, size(size)
{

}

AABB::AABB(const Vector2& center, const Vector2& size)
:center(center)
, size(size)
{
}

bool AABB::contains(const Vector2& point)
{
	return point.x >= minX()
		&& point.x <= maxX()
		&& point.y >= minY()
		&& point.y <= maxY();
}

bool AABB::contains(const Vector3& point)
{
	return point.x >= minX()
		&& point.x <= maxX()
		&& point.y >= minY()
		&& point.y <= maxY()
		&& point.z >= minZ()
		&& point.z <= maxZ();
}

bool AABB::contains(const Line2& line)
{
	return contains(line.src) && contains(line.dest);
}

bool AABB::contains(const Line3& line)
{
	return contains(line.src) && contains(line.dest);
}

bool AABB::intersects(const Line2& line)
{
	float x0 = minX();
	float x1 = maxX();
	float y0 = minY();
	float y1 = maxY();
	float z0 = minZ();
	float z1 = maxZ();

	Vector3 v0(x0, y0, z0);
	Vector3 v1(x0, y1, z0);
	Vector3 v2(x0, y0, z1);
	Vector3 v3(x0, y1, z1);

	return true;
}

bool AABB::intersects(const Line3& line)
{
	if (!contains(line.src) && !contains(line.dest))
	{
		return false;
	}

	return true;
}

bool AABB::contains(const AABB& bounds)
{
	return bounds.minX() >= minX()
		&& bounds.maxX() <= maxX()
		&& bounds.minY() >= minY()
		&& bounds.maxY() <= maxY()
		&& bounds.minZ() >= minZ()
		&& bounds.maxZ() <= maxZ();
}

bool AABB::intersects(const AABB& bounds)
{
	float x0 = bounds.minX();
	float x1 = bounds.maxX();
	float y0 = bounds.minY();
	float y1 = bounds.maxY();
	float z0 = bounds.minZ();
	float z1 = bounds.maxZ();

	Vector3 v0(x0, y0, z0);
	Vector3 v1(x0, y1, z0);
	Vector3 v2(x0, y0, z1);
	Vector3 v3(x0, y1, z1);
	Vector3 v4(x1, y0, z0);
	Vector3 v5(x1, y1, z0);
	Vector3 v6(x1, y0, z1);
	Vector3 v7(x1, y1, z1);

	if (contains(v0)) return true;
	if (contains(v1)) return true;
	if (contains(v2)) return true;
	if (contains(v3)) return true;
	if (contains(v4)) return true;
	if (contains(v5)) return true;
	if (contains(v6)) return true;
	if (contains(v7)) return true;

	return false;
}

void AABB::operator=(const AABB& aabb)
{
	center = aabb.center;
	size = aabb.size;
}

float AABB::minX()
{
	return center.x - size.x * 0.5f;
}

float AABB::minY()
{
	return center.y - size.y * 0.5f;
}

float AABB::minZ()
{
	return center.z - size.z * 0.5f;
}

float AABB::maxX()
{
	return center.x + size.x * 0.5f;
}

float AABB::maxY()
{
	return center.y + size.y * 0.5f;
}

float AABB::maxZ()
{
	return center.z + size.z * 0.5f;
}

float AABB::minX() const
{
	return center.x - size.x * 0.5f;
}

float AABB::minY() const
{
	return center.y - size.y * 0.5f;
}

float AABB::minZ() const
{
	return center.z - size.z * 0.5f;
}

float AABB::maxX() const
{
	return center.x + size.x * 0.5f;
}

float AABB::maxY() const
{
	return center.y + size.y * 0.5f;
}

float AABB::maxZ() const
{
	return center.z + size.z * 0.5f;
}
