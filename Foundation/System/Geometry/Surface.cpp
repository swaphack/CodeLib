#include "Surface.h"
#include "Line3.h"
#include "Polygon.h"

using namespace sys;

Surface::Surface()
:point32s(nullptr)
, count(0)
{

}

Surface::Surface(const Surface& surface)
:Surface(surface.point32s, surface.count)
{

}

Surface::Surface(Vector3* point32s, int32 count)
:Surface()
{
	if (point32s == nullptr || count < 3)
	{
		return;
	}

	this->point32s = new Vector3[count];
	this->count = count;
	for (int32 i = 0; i < count; i++)
	{
		this->point32s[i] = point32s[i];
	}
}


Surface::~Surface()
{
	if (point32s != nullptr)
	{
		delete[] point32s;
	}
}

Vector3 Surface::normalVector()
{
	Vector3 v0 = point32s[1] - point32s[0];
	Vector3 v1 = point32s[2] - point32s[1];

	return Vector3::cross(v0, v1);
}

Vector3 Surface::normalVector() const
{
	Vector3 v0 = point32s[1] - point32s[0];
	Vector3 v1 = point32s[2] - point32s[1];

	return Vector3::cross(v0, v1);
}

bool Surface::contain(const Vector3& point32)
{
	if (!isCoplanar(*this, point32))
	{ // 不共面
		return false;
	}

	Vector3 nv = normalVector();

	Vector2 target;
	if (nv.x == 0)
	{// 平行yoz面
		target.x = point32.y;
		target.y = point32.z;
	}
	else if (nv.y == 0)
	{// 平行xoz面
		target.x = point32.x;
		target.y = point32.z;
	}
	else/* if (nv.z == 0)*/
	{// 平行xoy面
		target.x = point32.x;
		target.y = point32.y;
	}

	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int32 i = 0; i < count; i++)
	{
		if (nv.x == 0)
		{// 平行yoz面
			ps[i].x = point32s[i].y;
			ps[i].y = point32s[i].z;
		}
		else if (nv.y == 0)
		{// 平行xoz面
			ps[i].x = point32s[i].x;
			ps[i].y = point32s[i].z;
		}
		else/* if (nv.z == 0)*/
		{// 平行xoy面
			ps[i].x = point32s[i].x;
			ps[i].y = point32s[i].y;
		}
	}

	// 投影
	Polygon polygon(ps, count);
	bool result = polygon.contains(target);
	delete ps;
	return result;
}

Surface& Surface::operator=(const Surface& surface)
{
	if (surface.point32s == nullptr || surface.count < 3)
	{
		return *this;
	}

	if (this->point32s != nullptr)
	{
		delete[] this->point32s;
	}

	this->point32s = new Vector3[surface.count];
	this->count = surface.count;
	for (int32 i = 0; i < surface.count; i++)
	{
		this->point32s[i] = surface.point32s[i];
	}

	return  *this;
}

bool Surface::isStandard(const Surface& surface)
{
	if (surface.point32s == nullptr || surface.count < 3)
	{
		return false;
	}

	int32 lineCount = surface.count;
	for (int32 i = 0; i < lineCount; i++)
	{
		// 邻边的向量
		Vector3 l0 = surface.point32s[(i + 1) % lineCount] - surface.point32s[i % lineCount];
		Vector3 l1 = surface.point32s[(i + 2) % lineCount] - surface.point32s[(i + 1) % lineCount];
		Vector3 l2 = surface.point32s[(i + 3) % lineCount] - surface.point32s[(i + 2) % lineCount];
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

	int32 lineCount = surface.count - 2;
	int32 lastDirection = -1;
	for (int32 i = 0; i < lineCount; i++)
	{
		Vector3 l0 = surface.point32s[(i + 1) % lineCount] - surface.point32s[i % lineCount];
		Vector3 l1 = surface.point32s[(i + 2) % lineCount] - surface.point32s[(i + 1) % lineCount];

		int32 direction = Vector3::direction(l1, l0);
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
}

bool Surface::isCoplanar(const Surface& surface, const Vector3& point32)
{
	if (!isStandard(surface))
	{
		return false;
	}
	int32 lineCount = surface.count;
	// 邻边的向量
	Vector3 l0 = surface.point32s[1] - surface.point32s[0];
	Vector3 l1 = surface.point32s[2] - surface.point32s[1];
	Vector3 l2 = point32 - surface.point32s[2];
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

bool Surface::isCoplanar(const Vector3& point320, const Vector3& point321, const Vector3& point322, 
	const Vector3& point323)
{
	// 邻边的向量
	Vector3 l0 = point321 - point320;
	Vector3 l1 = point322 - point321;
	Vector3 l2 = point323 - point322;

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
	int32 count = surface.count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int32 i = 0; i < count; i++)
	{
		ps[i].x = surface.point32s[i].x;
		ps[i].y = surface.point32s[i].y;
	}

	// 投影
	Polygon polygon(ps, count);
	delete ps;

	return polygon;
}

Polygon Surface::projectOnYOZ(const Surface& surface)
{
	int32 count = surface.count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int32 i = 0; i < count; i++)
	{
		ps[i].x = surface.point32s[i].y;
		ps[i].y = surface.point32s[i].z;
	}

	// 投影
	Polygon polygon(ps, count);
	delete ps;

	return polygon;
}

Polygon Surface::projectOnXOZ(const Surface& surface)
{
	int32 count = surface.count;
	// 投影坐标计算
	Vector2* ps = new Vector2[count];
	for (int32 i = 0; i < count; i++)
	{
		ps[i].x = surface.point32s[i].x;
		ps[i].y = surface.point32s[i].z;
	}

	// 投影
	Polygon polygon(ps, count);
	delete ps;

	return polygon;
}
