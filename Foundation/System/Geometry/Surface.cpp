#include "Surface.h"
#include "Line3.h"
#include "Polygon.h"

using namespace sys;

Surface::Surface(Vector3* points, int count)
{
	if (points == nullptr || count < 3)
	{
		return;
	}

	this->points = new Vector3[count];
	this->count = count;
	for (int i = 0; i < count; i++)
	{
		this->points[i] = points[i];
	}
}

Surface::~Surface()
{
	if (points != nullptr)
	{
		delete points;
	}
}

Vector3 Surface::normalVector()
{
	Vector3 v0 = points[1] - points[0];
	Vector3 v1 = points[2] - points[1];

	return Vector3::cross(v0, v1);
}

Vector3 Surface::normalVector() const
{
	Vector3 v0 = points[1] - points[0];
	Vector3 v1 = points[2] - points[1];

	return Vector3::cross(v0, v1);
}

bool Surface::contain(const Vector3& point)
{
	if (!isCoplanar(*this, point))
	{ // 不共面
		return false;
	}

	Vector3 nv = normalVector();

	Vector2 target;
	if (nv.x == 0)
	{// 平行yoz面
		target.x = point.y;
		target.y = point.z;
	}
	else if (nv.y == 0)
	{// 平行xoz面
		target.x = point.x;
		target.y = point.z;
	}
	else/* if (nv.z == 0)*/
	{// 平行xoy面
		target.x = point.x;
		target.y = point.y;
	}

	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int i = 0; i < count; i++)
	{
		if (nv.x == 0)
		{// 平行yoz面
			ps[i].x = points[i].y;
			ps[i].y = points[i].z;
		}
		else if (nv.y == 0)
		{// 平行xoz面
			ps[i].x = points[i].x;
			ps[i].y = points[i].z;
		}
		else/* if (nv.z == 0)*/
		{// 平行xoy面
			ps[i].x = points[i].x;
			ps[i].y = points[i].y;
		}
	}

	// 投影
	Polygon polygon(ps, count);
	bool result = polygon.contains(target);
	delete ps;
	return result;
}

bool Surface::isStandard(const Surface& surface)
{
	if (surface.points == nullptr || surface.count < 3)
	{
		return false;
	}

	int lineCount = surface.count;
	for (int i = 0; i < lineCount; i++)
	{
		// 邻边的向量
		Vector3 l0 = surface.points[(i + 1) % lineCount] - surface.points[i % lineCount];
		Vector3 l1 = surface.points[(i + 2) % lineCount] - surface.points[(i + 1) % lineCount];
		Vector3 l2 = surface.points[(i + 3) % lineCount] - surface.points[(i + 2) % lineCount];
		// 两向量所在平面的法向量
		Vector3 n0 = Vector3::cross(l0, l1);
		Vector3 n1 = Vector3::cross(l1, l2);
		if (Vector3::dot(n0, n1) != 0)
		{ // 法向量不共线
			return false;
		}
		if (n0.x * n1.x < 0)
		{// 法向量不同向
			return false;
		}
	}

	return true;
}

bool Surface::isConvex(const Surface& surface)
{
	if (!isStandard(surface))
	{
		return false;
	}

	int lineCount = surface.count - 2;
	int lastDirection = -1;
	for (int i = 0; i < lineCount; i++)
	{
		Vector3 l0 = surface.points[(i + 1) % lineCount] - surface.points[i % lineCount];
		Vector3 l1 = surface.points[(i + 2) % lineCount] - surface.points[(i + 1) % lineCount];

		int direction = Vector3::direction(l1, l0);
		if (lastDirection == -1)
		{
			lastDirection = direction;
		}
		else
		{
			if (direction != lastDirection)
			{
				return false;
			}
		}
	}

	return true;
}

bool Surface::isCoplanar(const Surface& surface, const Vector3& point)
{
	if (!isStandard(surface))
	{
		return false;
	}
	int lineCount = surface.count;
	// 邻边的向量
	Vector3 l0 = surface.points[1] - surface.points[0];
	Vector3 l1 = surface.points[2] - surface.points[1];
	Vector3 l2 = point - surface.points[2];
	// 法向量
	Vector3 n0 = Vector3::cross(l0, l1);
	Vector3 n1 = Vector3::cross(l1, l2);
	if (Vector3::dot(n0, n1) != 0)
	{ // 法向量不共线
		return false;
	}
	if (n0.x * n1.x < 0)
	{// 法向量不同向
		return false;
	}

	return true;
}

bool Surface::isCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2, 
	const Vector3& point3)
{
	// 邻边的向量
	Vector3 l0 = point1 - point0;
	Vector3 l1 = point2 - point1;
	Vector3 l2 = point3 - point2;

	if (Vector3::direction(l0, l1) == 0 
		|| Vector3::direction(l1, l2) == 0
		|| Vector3::direction(l2, l0) == 0)
	{ // 相邻共线，构成不了平面
		return false;
	}

	// 法向量
	Vector3 n0 = Vector3::cross(l0, l1);
	Vector3 n1 = Vector3::cross(l1, l2);
	if (Vector3::dot(n0, n1) != 0)
	{ // 法向量不共线
		return false;
	}
	if (n0.x * n1.x < 0)
	{// 法向量不同向
		return false;
	}

	return true;

}

Polygon Surface::projectOnXOY(const Surface& surface)
{
	int count = surface.count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int i = 0; i < count; i++)
	{
		ps[i].x = surface.points[i].x;
		ps[i].y = surface.points[i].y;
	}

	// 投影
	Polygon polygon(ps, count);
	delete ps;

	return polygon;
}

Polygon Surface::projectOnYOZ(const Surface& surface)
{
	int count = surface.count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int i = 0; i < count; i++)
	{
		ps[i].x = surface.points[i].y;
		ps[i].y = surface.points[i].z;
	}

	// 投影
	Polygon polygon(ps, count);
	delete ps;

	return polygon;
}

Polygon Surface::projectOnXOZ(const Surface& surface)
{
	int count = surface.count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int i = 0; i < count; i++)
	{
		ps[i].x = surface.points[i].x;
		ps[i].y = surface.points[i].z;
	}

	// 投影
	Polygon polygon(ps, count);
	delete ps;

	return polygon;
}
