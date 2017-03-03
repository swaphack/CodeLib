#include "Line3.h"
#include "../Collider/import.h"

using namespace sys;

Line3::Line3()
{
}

Line3::Line3(const Vector3& src, const Vector3& dest) 
:src(src), 
dest(dest)
{

}

float Line3::getLength()
{
	return Vector3::distance(src, dest);
}

Vector3 Line3::getVector()
{
	return dest - src;
}

Vector3 Line3::getVector() const
{
	return dest - src;
}

AABB Line3::getBounds()
{
	Vector3 size = (dest - src) * 0.5f;
	Vector3 center = src + size;
	return AABB(center, size);
}

AABB Line3::getBounds() const
{
	Vector3 size = (dest - src) * 0.5f;
	Vector3 center = src + size;
	return AABB(center, size);
}

bool Line3::contains(const Vector3& point)
{
	Vector3 v0 = point - src;
	Vector3 v1 = dest - src;

	if (Vector3::dot(v0, v1) != 0)
	{
		return false;
	}

	AABB bounds = getBounds();
	return bounds.contains(point);
}

bool Line3::intersects(const Line3& line)
{
	AABB bounds0 = getBounds();
	AABB bounds1 = line.getBounds();
	// 先简单判断包围盒是否相交
	if (!bounds0.intersects(bounds1))
	{
		return false;
	}

	Vector3 v0 = src - line.src;
	Vector3 v1 = dest - src;
	Vector3 v2 = line.dest - src;

	float d0 = Vector3::dot(v0, v1);
	float d1 = Vector3::dot(v1, v2);

	return d0 * d1 >= 0;
}

Vector3 Line3::closestPoint(const Vector3& point)
{
	Vector3 result;

	float x0 = dest.x - src.x;
	float y0 = dest.y - src.y;
	float z0 = dest.z - src.z;

	if (x0 == 0 && y0 == 0 && z0 == 0)
	{ // 线段为点
		return src;
	}

	float k = -((src.x - point.x) * x0 + (src.y - point.y) * y0 + (src.z - point.z) * z0)
		/ (pow(x0, 2) + pow(y0, 2) + pow(z0, 2));

	result.x = k * x0 + src.x;
	result.y = k * y0 + src.y;
	result.z = k * z0 + src.z;
	if (!contains(result))
	{
		if (Vector3::distance(src, result) < Vector3::distance(dest, result))
		{
			result = src;
		}
		else
		{
			result = dest;
		}
	}

	return result;
}

float Line3::distance(const Line3& line, const Vector3& point)
{
// 	float x0 = line.dest.x - line.src.x;
// 	float y0 = line.dest.y - line.src.y;
// 	float z0 = line.dest.z - line.src.z;
// 
// 	float a = y0 * z0;
// 	float b = -x0 * z0;
// 	float c = -x0 * y0;
// 	float d = -line.src.x * y0 * z0 + line.src.y * x0 * z0 + line.src.z * x0 * y0;
// 	float top = abs(a * point.x + b * point.y + c * point.z + d);
// 	float bottom = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
// 
// 	if (bottom == 0) return 0;
// 
// 	return top / bottom;

	Vector3 v0 = line.dest - line.src;
	Vector3 v1 = point - line.src;

	float top = Vector3::cross(v0, v1).getLength();
	float bottom = v0.getLength();

	if (bottom == 0) return 0;

	return top / bottom;
}