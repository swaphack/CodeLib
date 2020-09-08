#include "AABB.h"

using namespace math;

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
	return point32.getX() >= minPos.getX()
		&& point32.getX() <= maxPos.getX()
		&& point32.getY() >= minPos.getY()
		&& point32.getY() <= maxPos.getY();
}

bool AABB::contains(const Vector3& point32)
{
	return point32.getX() >= minPos.getX()
		&& point32.getX() <= maxPos.getX()
		&& point32.getY() >= minPos.getY()
		&& point32.getY() <= maxPos.getY()
		&& point32.getZ() >= minPos.getZ()
		&& point32.getZ() <= maxPos.getZ();
}

bool AABB::contains(const LineSegment2d& line)
{
	return contains(line.getSrc()) && contains(line.getDest());
}

bool AABB::contains(const LineSegment3d& line)
{
	return contains(line.getSrc()) && contains(line.getDest());
}

bool AABB::intersects(const LineSegment2d& line)
{
	if (!contains(line.getSrc()) && !contains(line.getDest()))
	{
		return false;
	}

	return true;
}

bool AABB::intersects(const LineSegment3d& line)
{
	if (!contains(line.getSrc()) && !contains(line.getDest()))
	{
		return false;
	}

	return true;
}

bool AABB::contains(const AABB& bounds)
{
	return bounds.Min().getX() >= Min().getX()
		&& bounds.Max().getX() <= Max().getX()
		&& bounds.Min().getY() >= Min().getY()
		&& bounds.Max().getY() <= Max().getY()
		&& bounds.Min().getZ() >= Min().getZ()
		&& bounds.Max().getZ() <= Max().getZ();
}

bool AABB::intersects(const AABB& bounds)
{
	float x0 = bounds.Min().getX();
	float x1 = bounds.Max().getX();
	float y0 = bounds.Min().getY();
	float y1 = bounds.Min().getY();
	float z0 = bounds.Min().getZ();
	float z1 = bounds.Min().getZ();

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
