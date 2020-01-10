#include "LineSegment.h"
#include "Geometry/2d/Rect.h"
#include "Cuboids.h"

using namespace math;

LineSegment::LineSegment()
{
}

LineSegment::LineSegment(const Vector3& src, const Vector3& dest) 
:src(src), 
dest(dest)
{

}

float LineSegment::getMagnitude() const
{
	return Vector3::distance(src, dest);
}

Vector3 LineSegment::getVector() const
{
	return dest - src;
}

bool LineSegment::contains(const Vector3& point)
{
	Cuboids cuboids(src, dest - src);
	if (!cuboids.contains(point))
	{
		return false;
	}

	Vector3 v0 = point - src;
	Vector3 v1 = dest - src;

	if (Vector3::cosAngle(v0, v1) != 0)
	{
		return false;
	}

	return false;
}

bool LineSegment::contains(const LineSegment& line)
{
	return false;
}

bool LineSegment::intersects(const LineSegment& line)
{
	Vector3 v0 = src - line.src;
	Vector3 v1 = dest - src;
	Vector3 v2 = line.dest - src;

	float d0 = Vector3::dot(v0, v1);
	float d1 = Vector3::dot(v1, v2);

	return d0 * d1 >= 0;
}

Vector3 LineSegment::closestPoint(const Vector3& point)
{

	float x0 = dest.getX() - src.getX();
	float y0 = dest.getY() - src.getY();
	float z0 = dest.getZ() - src.getZ();

	if (x0 == 0 && y0 == 0 && z0 == 0)
	{ // Ïß¶ÎÎªµã
		return src;
	}

	float k = -((src.getX() - point.getX()) * x0 + (src.getY() - point.getY()) * y0 + (src.getZ() - point.getZ()) * z0)
		/ (pow(x0, 2) + pow(y0, 2) + pow(z0, 2));

	float x = k * x0 + src.getX();
	float y = k * y0 + src.getY();
	float z = k * z0 + src.getZ();

	Vector3 result(x, y, z);
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

float LineSegment::distance(const LineSegment& line, const Vector3& point)
{
	Vector3 v0 = line.dest - line.src;
	Vector3 v1 = point - line.src;

	float top = Vector3::dot(v0, v1);
	float bottom = v0.getMagnitude();

	if (bottom == 0) return 0;

	return top / bottom;
}
