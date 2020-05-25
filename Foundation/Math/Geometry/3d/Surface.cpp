#include "Surface.h"
#include "LineSegment.h"
#include "Geometry/2d/Polygon.h"

using namespace math;

Surface::Surface()
:_points(nullptr)
, _count(0)
{

}

Surface::Surface(const Surface& surface)
:Surface(surface._points, surface._count)
{

}

Surface::Surface(Vector3* points, int32_t count)
:Surface()
{
	if (points == nullptr || count < 3)
	{
		return;
	}

	this->_points = new Vector3[count];
	this->_count = count;
	for (int32_t i = 0; i < count; i++)
	{
		this->_points[i] = points[i];
	}
}


Surface::~Surface()
{
	if (_points != nullptr)
	{
		delete[] _points;
	}
}

Vector3 Surface::normalVector() const
{
	Vector3 v0 = _points[1] - _points[0];
	Vector3 v1 = _points[2] - _points[1];

	return Vector3::cross(v0, v1);
}

bool Surface::contains(const Vector3& point)
{
	if (!isCoplanar(*this, point))
	{ // 不共面
		return false;
	}

	Vector2 pxy(point.getX(), point.getY());
	Vector2 pyz(point.getY(), point.getZ());
	Vector2 pxz(point.getX(), point.getZ());

	Polygon pxoy = Surface::projectOnXOY(*this);
	Polygon pyoz = Surface::projectOnXOY(*this);
	Polygon pxoz = Surface::projectOnXOY(*this);

	if (pxoy.contains(pxy) || pyoz.contains(pyz) || pyoz.contains(pxz))
	{
		return true;
	}

	return false;
}

Surface& Surface::operator=(const Surface& surface)
{
	if (surface._points == nullptr || surface._count < 3)
	{
		return *this;
	}

	if (this->_points != nullptr)
	{
		delete[] this->_points;
	}

	this->_points = new Vector3[surface._count];
	this->_count = surface._count;
	for (int32_t i = 0; i < surface._count; i++)
	{
		this->_points[i] = surface._points[i];
	}

	return  *this;
}

bool Surface::isStandard(const Surface& surface)
{
	if (surface._points == nullptr || surface._count < 3)
	{
		return false;
	}

	int32_t lineCount = surface._count;
	for (int32_t i = 0; i < lineCount; i++)
	{
		// 邻边的向量
		Vector3 l0 = surface._points[(i + 1) % lineCount] - surface._points[i % lineCount];
		Vector3 l1 = surface._points[(i + 2) % lineCount] - surface._points[(i + 1) % lineCount];
		Vector3 l2 = surface._points[(i + 3) % lineCount] - surface._points[(i + 2) % lineCount];
		// 两向量所在平面的法向量
		Vector3 n0 = Vector3::cross(l0, l1);
		Vector3 n1 = Vector3::cross(l1, l2);
		if (Vector3::dot(n0, n1) != 0)
		{ // 法向量不共线
			return false;
		}
		if (n0.getX() * n1.getX() < 0)
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
	/*
	int32_t lineCount = surface._count - 2;
	int32_t lastDirection = -1;
	for (int32_t i = 0; i < lineCount; i++)
	{
		Vector3 l0 = surface._points[(i + 1) % lineCount] - surface._points[i % lineCount];
		Vector3 l1 = surface._points[(i + 2) % lineCount] - surface._points[(i + 1) % lineCount];

		int32_t direction = Vector3::direction(l1, l0);
		if (lastDirection == -1)
		{
			lastDirection = direction;
		}
		else if (direction != lastDirection)
		{
			return false;
		}
	}

	return true;
	*/
	return false;
}

bool Surface::isCoplanar(const Surface& surface, const Vector3& point)
{
	if (!isStandard(surface))
	{
		return false;
	}
	int32_t lineCount = surface._count;
	// 邻边的向量
	Vector3 l0 = surface._points[1] - surface._points[0];
	Vector3 l1 = surface._points[2] - surface._points[1];
	Vector3 l2 = point - surface._points[2];
	// 法向量
	Vector3 n0 = Vector3::cross(l0, l1);
	Vector3 n1 = Vector3::cross(l1, l2);
	if (Vector3::dot(n0, n1) != 0)
	{ // 法向量不共线
		return false;
	}
	if (n0.getX() * n1.getX() < 0)
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

	if (Vector3::isThreePointsOnSameLine(point0, point1, point2))
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
	if (n0.getX() * n1.getX() < 0)
	{// 法向量不同向
		return false;
	}

	return true;

}

Polygon Surface::projectOnXOY(const Surface& surface)
{
	int32_t count = surface._count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int32_t i = 0; i < count; i++)
	{
		float x = surface._points[i].getX();
		float y = surface._points[i].getY();
		ps[i].setX(x);
		ps[i].setY(y);
	}

	// 投影
	Polygon polygon(count, ps);
	delete[] ps;

	return polygon;
}

Polygon Surface::projectOnYOZ(const Surface& surface)
{
	int32_t count = surface._count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int32_t i = 0; i < count; i++)
	{
		float x = surface._points[i].getX();
		float y = surface._points[i].getY();
		ps[i].setX(x);
		ps[i].setY(y);
	}

	// 投影
	Polygon polygon(count, ps);
	delete[] ps;

	return polygon;
}

Polygon Surface::projectOnXOZ(const Surface& surface)
{
	int32_t count = surface._count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int32_t i = 0; i < count; i++)
	{
		float x = surface._points[i].getX();
		float y = surface._points[i].getZ();

		ps[i].setX(x);
		ps[i].setY(y);
	}

	// 投影
	Polygon polygon(count, ps);
	delete[] ps;

	return polygon;
}
