#include "AABB.h"
#include "Geometry/import.h"

using namespace sys;

AABB::AABB(const Vector3& center, const Vector3& size)
:center(center)
, size(size)
{
	minPos = center - size * 0.5f;
	maxPos = center + size * 0.5f;
}

AABB::AABB(const Vector2& center, const Vector2& size)
:center(center)
, size(size)
{
}

bool AABB::contains(const Vector2& point32)
{
	return point32.x >= minPos.x
		&& point32.x <= maxPos.x
		&& point32.y >= minPos.y
		&& point32.y <= maxPos.y;
}

bool AABB::contains(const Vector3& point32)
{
	return point32.x >= minPos.x
		&& point32.x <= maxPos.x
		&& point32.y >= minPos.y
		&& point32.y <= maxPos.y
		&& point32.z >= minPos.z
		&& point32.z <= maxPos.z;
}

bool AABB::contains(const Line2& line)
{
	return contains(line.src) && contains(line.dest);
}

bool AABB::contains(const Line3& line)
{
	return contains(line.src) && contains(line.dest);
}

bool AABB::int32ersects(const Line2& line)
{
	if (!contains(line.src) && !contains(line.dest))
	{
		return false;
	}

	return true;
}

bool AABB::int32ersects(const Line3& line)
{
	if (!contains(line.src) && !contains(line.dest))
	{
		return false;
	}

	return true;
}

bool AABB::contains(const AABB& bounds)
{
	return bounds.Min().x >= Min().x
		&& bounds.Max().x <= Max().x
		&& bounds.Min().y >= Min().y
		&& bounds.Max().y <= Max().y
		&& bounds.Min().z >= Min().z
		&& bounds.Max().z <= Max().z;
}

bool AABB::int32ersects(const AABB& bounds)
{
	float x0 = bounds.Min().x;
	float x1 = bounds.Max().x;
	float y0 = bounds.Min().y;
	float y1 = bounds.Min().y;
	float z0 = bounds.Min().z;
	float z1 = bounds.Min().z;

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
