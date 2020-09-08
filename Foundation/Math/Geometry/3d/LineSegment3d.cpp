#include "LineSegment3d.h"
#include "Geometry/2d/Rect.h"
#include "Cuboids3d.h"

using namespace math;

LineSegment3d::LineSegment3d()
{
}

LineSegment3d::LineSegment3d(const Vector3& src, const Vector3& dest) 
{
	this->setSrc(src);
	this->setDest(dest);
}

float LineSegment3d::getMagnitude() const
{
	return Vector3::distance(getSrc(), getDest());
}

Vector3 LineSegment3d::getVector() const
{
	return getDest() - getSrc();
}

bool LineSegment3d::contains(const Vector3& point)
{
	Vector3 p = getVector();
	Cuboids3d cuboids(getSrc(), p);
	if (!cuboids.contains(point))
	{
		return false;
	}

	Vector3 v0 = point - getSrc();
	Vector3 v1 = getDest() - getSrc();

	if (Vector3::cosAngle(v0, v1) != 0)
	{
		return false;
	}

	return false;
}

bool LineSegment3d::contains(const LineSegment3d& line)
{
	return this->contains(line.getSrc()) && this->contains(line.getDest());
}

bool LineSegment3d::intersects(const LineSegment3d& line, Vector3& point)
{
	Vector3 v0 = getSrc() - line.getSrc();
	Vector3 v1 = getDest() - getSrc();
	Vector3 v2 = line.getDest() - getSrc();

	float d0 = Vector3::dot(v0, v1);
	float d1 = Vector3::dot(v1, v2);

	bool result = d0 * d1 >= 0;
	if (!result)
	{
		return false;
	}

	return true;
}

Vector3 LineSegment3d::closestPoint(const Vector3& point)
{
	Vector3 src = getSrc();
	Vector3 dest = getDest();
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

float LineSegment3d::distance(const LineSegment3d& line, const Vector3& point)
{
	Vector3 v0 = line.getDest() - line.getSrc();
	Vector3 v1 = point - line.getSrc();

	float top = Vector3::dot(v0, v1);
	float bottom = v0.getMagnitude();

	if (bottom == 0) return 0;

	return top / bottom;
}
