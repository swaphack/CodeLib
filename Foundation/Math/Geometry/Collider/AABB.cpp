#include "AABB.h"

using namespace math;

AABB::AABB(const Vector3& center, const Vector3& volume)
{
	this->set(center, volume);
}

AABB::AABB(const Vector2& center, const Vector2& size)
{
	this->set(center, size);
}

void math::AABB::set(const Vector2& center, const Vector2& size)
{
	_center = center;
	_volume = size;

	_minPos = center - size * 0.5f;
	_maxPos = center + size * 0.5f;
}

void math::AABB::set(const Vector3& center, const Vector3& volume)
{
	_center = center;
	_volume = volume;

	_minPos = center - volume * 0.5f;
	_maxPos = center + volume * 0.5f;
}

bool AABB::contains(const Vector2& point32)
{
	return point32.getX() >= _minPos.getX()
		&& point32.getX() <= _maxPos.getX()
		&& point32.getY() >= _minPos.getY()
		&& point32.getY() <= _maxPos.getY();
}

bool AABB::contains(const Vector3& point32)
{
	return point32.getX() >= _minPos.getX()
		&& point32.getX() <= _maxPos.getX()
		&& point32.getY() >= _minPos.getY()
		&& point32.getY() <= _maxPos.getY()
		&& point32.getZ() >= _minPos.getZ()
		&& point32.getZ() <= _maxPos.getZ();
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
	return bounds.getMin().getX() >= getMin().getX()
		&& bounds.getMax().getX() <= getMax().getX()
		&& bounds.getMin().getY() >= getMin().getY()
		&& bounds.getMax().getY() <= getMax().getY()
		&& bounds.getMin().getZ() >= getMin().getZ()
		&& bounds.getMax().getZ() <= getMax().getZ();
}

bool AABB::intersects(const AABB& bounds)
{
	float x0 = bounds.getMin().getX();
	float x1 = bounds.getMax().getX();
	float y0 = bounds.getMin().getY();
	float y1 = bounds.getMin().getY();
	float z0 = bounds.getMin().getZ();
	float z1 = bounds.getMin().getZ();

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

const Vector3& math::AABB::getMin() const 
{ 
	return _minPos; 
}

const Vector3& math::AABB::getMax() const 
{ 
	return _maxPos; 
}

const Vector3& math::AABB::getVolume() const 
{
	return _volume; 
}

void AABB::operator=(const AABB& aabb)
{
	_center = aabb._center;
	_volume = aabb._volume;
}

bool AABB::hitRay(const Ray& ray) const
{
	float dmin = INT_MIN;
	float dmax = INT_MAX;

	const math::Vector3& srcPoint = ray.getSrcPoint();
	const math::Vector3& direction = ray.getDirection();

	float t1x = (_minPos.getX() - srcPoint.getX()) / direction.getX();
	float t2x = (_maxPos.getX() - srcPoint.getX()) / direction.getX();

	float min = MIN(t1x, t2x);
	float max = MAX(t1x, t2x);
	if (dmin < min) dmin = min;
	if (dmax > max) dmax = max;

	float t1y = (_minPos.getY() - srcPoint.getY()) / direction.getY();
	float t2y = (_maxPos.getY() - srcPoint.getY()) / direction.getY();

	min = MIN(t1y, t2y);
	max = MAX(t1y, t2y);
	if (dmin < min) dmin = min;
	if (dmax > max) dmax = max;

	float t1z = (_minPos.getZ() - srcPoint.getZ()) / direction.getZ();
	float t2z = (_maxPos.getZ() - srcPoint.getZ()) / direction.getZ();

	min = MIN(t1z, t2z);
	max = MAX(t1z, t2z);
	if (dmin < min) dmin = min;
	if (dmax > max) dmax = max;

	return dmin < dmax;
}
