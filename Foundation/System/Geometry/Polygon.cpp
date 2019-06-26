#include "Polygon.h"
#include "Line2.h"
#include "Collider/import.h"

using namespace sys;

Polygon::Polygon(Vector2* point32s, int32 count) 
:Polygon()
{
	if (point32s == nullptr || count < 3)
	{
		return;
	}

	this->point32s = new Vector2[count];
	this->count = count;
	for (int32 i = 0; i < count; i++)
	{
		this->point32s[i] = point32s[i];
	}
}

Polygon::Polygon()
:point32s(nullptr)
,count(0)
{

}

Polygon::Polygon(const Polygon & polygon)
:Polygon(polygon.point32s, polygon.count)
{

}

Polygon::~Polygon()
{
	if (point32s != nullptr)
	{
		delete point32s;
	}
}

AABB Polygon::getBounds()
{
	Vector2 minPoint32 = point32s[0];
	Vector2 maxPoint32 = point32s[0];

	for (int32 i = 0; i < count; i++)
	{
		if (minPoint32.x > point32s[i].x) minPoint32.x = point32s[i].x;
		if (minPoint32.y > point32s[i].y) minPoint32.y = point32s[i].y;
		if (maxPoint32.x < point32s[i].x) maxPoint32.x = point32s[i].x;
		if (maxPoint32.y < point32s[i].x) maxPoint32.y = point32s[i].x;
	}

	Vector2 center = (minPoint32 + maxPoint32) * 0.5f;
	Vector2 size = (maxPoint32 - minPoint32);

	return AABB(center, size);
}

AABB Polygon::getBounds() const
{
	Vector2 minPoint32 = point32s[0];
	Vector2 maxPoint32 = point32s[0];

	for (int32 i = 0; i < count; i++)
	{
		if (minPoint32.x > point32s[i].x) minPoint32.x = point32s[i].x;
		if (minPoint32.y > point32s[i].y) minPoint32.y = point32s[i].y;
		if (maxPoint32.x < point32s[i].x) maxPoint32.x = point32s[i].x;
		if (maxPoint32.y < point32s[i].x) maxPoint32.y = point32s[i].x;
	}

	Vector2 center = (minPoint32 + maxPoint32) * 0.5f;
	Vector2 size = (maxPoint32 - minPoint32);

	return AABB(center, size);
}

bool Polygon::contains(const Vector2& point32)
{
	int32 sum = 0;
	Vector2 p0;
	Vector2 p1;

	for (int32 i = 0; i < count; i++)
	{		
		p0 = point32s[i];
		p1 = point32s[(i + 1) % count];

		// 水平
		if (p0.y == p1.y) continue;

		// 在其延长线上
		if (point32.y < MIN(p0.y, p1.y)) continue;
		if (point32.y >= MAX(p0.y, p1.y)) continue;

		// 求解 y=point32.y 与 p0p1 的交点
		float x = (point32.y - p0.y) * (p1.x - p0.x) / (p1.y - p0.y) + p0.x;
		if (x > point32.x) sum++;
	}

	return sum % 2 == 1;
}

bool Polygon::contains(const Line2& line)
{
	if (!contains(line.src) || !contains(line.dest))
	{
		return false;
	}
	Vector2 p0;
	Vector2 p1;
	Line2 segment;
	for (int32 i = 0; i < count; i++)
	{
		segment.src = point32s[i];
		segment.dest = point32s[(i + 1) % count];

		if (segment.int32ersects(line))
		{
			return false;
		}
	}

	return true;
}

bool Polygon::int32ersects(const Line2& line)
{
	Vector2 p0;
	Vector2 p1;
	Line2 segment;
	for (int32 i = 0; i < count; i++)
	{
		segment.src = point32s[i];
		segment.dest = point32s[(i + 1) % count];

		if (segment.int32ersects(line))
		{
			return true;
		}
	}

	return false;
}

bool Polygon::int32ersects(const Polygon& polygon)
{
	for (int32 i = 0; i < polygon.count; i++)
	{
		Line2 line(polygon.point32s[i], polygon.point32s[(i + 1) % polygon.count]);
		if (this->int32ersects(line) || this->contains(line))
		{
			return true;
		}
	}

	return false;
}

Polygon& Polygon::operator=(const Polygon& polygon)
{
	if (polygon.point32s == nullptr || polygon.count < 3)
	{
		return *this;
	}

	if (this->point32s != nullptr)
	{
		delete[] this->point32s;
	}

	this->point32s = new Vector2[count];
	this->count = count;
	for (int32 i = 0; i < count; i++)
	{
		this->point32s[i] = point32s[i];
	}

	return *this;
}

bool Polygon::isStandard(const Polygon& polygon)
{
	if (polygon.point32s == nullptr || polygon.count < 3)
	{
		return false;
	}

	int32 lineCount = polygon.count;
	int32 lastDirection = -1;
	for (int32 i = 0; i < lineCount; i++)
	{
		Vector2 l0 = polygon.point32s[(i + 1) % lineCount] - polygon.point32s[i % lineCount];
		Vector2 l1 = polygon.point32s[(i + 2) % lineCount] - polygon.point32s[(i + 1) % lineCount];

		int32 direction = Vector2::direction(l1, l0);
		if (direction == 0)
		{
			return false;
		}
	}

	return true;
}

bool Polygon::isConvex(const Polygon& polygon)
{
	if (!isStandard(polygon))
	{
		return false;
	}

	int32 lineCount = polygon.count;
	int32 lastDirection = -1;
	for (int32 i = 0; i < lineCount; i++)
	{
		Vector2 l0 = polygon.point32s[(i + 1) % lineCount] - polygon.point32s[i % lineCount];
		Vector2 l1 = polygon.point32s[(i + 2) % lineCount] - polygon.point32s[(i + 1) % lineCount];

		int32 direction = Vector2::direction(l1, l0);
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