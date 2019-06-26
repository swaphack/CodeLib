#include "Line2.h"
#include "Collider/import.h"

using namespace sys;

Line2::Line2()
{
}

Line2::Line2(const Vector2& src, const Vector2& dest)
:src(src),
dest(dest)
{

}

float Line2::getLength()
{
	return Vector2::distance(src, dest);
}

Vector2 Line2::getVector()
{
	return dest - src;
}

Vector2 Line2::getVector() const
{
	return dest - src;
}

AABB Line2::getBounds()
{
	Vector2 size = (dest - src) * 0.5f;
	Vector2 center = src + size;
	return AABB(center, size);
}

AABB Line2::getBounds() const
{
	Vector2 size = (dest - src) * 0.5f;
	Vector2 center = src + size;
	return AABB(center, size);
}

bool Line2::contains(const Vector2& point32)
{
	Vector2 v0 = point32 - src;
	Vector2 v1 = dest - src;

	if (Vector2::dot(v0, v1) != 0)
	{
		return false;
	}

	AABB bounds = getBounds();
	return bounds.contains(point32);
}

bool Line2::contains(const Line2& line)
{
	Vector2 v0 = src - line.src;
	Vector2 v1 = dest - src;
	Vector2 v2 = line.dest - src;

	float d0 = Vector2::dot(v0, v1);
	float d1 = Vector2::dot(v1, v2);
	// 共线，或相交
	if (d0 * d1 != 0)
	{
		return false;
	}

	return this->contains(line.src) && this->contains(line.dest);
}

bool Line2::int32ersects(const Line2& line)
{
	AABB bounds0 = getBounds();
	AABB bounds1 = line.getBounds();
	// 先简单判断包围盒是否相交
	if (!bounds0.int32ersects(bounds1))
	{
		return false;
	}

	Vector2 v0 = src - line.src;
	Vector2 v1 = dest - src;
	Vector2 v2 = line.dest - src;

	float d0 = Vector2::dot(v0, v1);
	float d1 = Vector2::dot(v1, v2);
	// 共线，或相交
	return d0 * d1 >= 0;
}
/**
*	如果该线段平行于X轴（Y轴），则过点point32作该线段所在直线的垂线，垂足很容易求得，然后计算出垂足，如果垂足在线段上则返回垂足，否则返回离垂足近的端点；
*	如果该线段不平行于X轴也不平行于Y轴，则斜率存在且不为0。
*	设线段的两端点为pt1和pt2，斜率为：k = ( pt2.y - pt1. y ) / (pt2.x - pt1.x );该直线方程为：y = k* ( x - pt1.x) + pt1.y。
*	其垂线的斜率为 - 1 / k，垂线方程为：y = (-1/k) * (x - point32.x) + point32.y 。
*
*　 联立两直线方程解得：x = ( k^2 * pt1.x + k * (point32.y - pt1.y ) + point32.x ) / ( k^2 + 1) ，y = k * ( x - pt1.x) + pt1.y;
*	然后再判断垂足是否在线段上，如果在线段上则返回垂足；如果不在则计算两端点到垂足的距离，选择距离垂足较近的端点返回
*/
Vector2 Line2::closestPoint32(const Vector2& point32)
{
	Vector2 result;

	float x0 = dest.x - src.x;
	float y0 = dest.y - src.y;

	if (y0 == 0 && x0 == 0)
	{// 线段为点
		return src;
	}
	else if (x0 == 0)
	{ // 平行于y轴
		result.y = point32.y > MAX(src.y, dest.y) ? MAX(src.y, dest.y) : point32.y;
		result.y = point32.y < MIN(src.y, dest.y) ? MIN(src.y, dest.y) : point32.y;
		result.x = src.x;
	}
	else if (y0 == 0)
	{// 平行于x轴
		result.x = point32.x > MAX(src.x, dest.x) ? MAX(src.x, dest.x) : point32.x;
		result.x = point32.x < MIN(src.x, dest.x) ? MIN(src.x, dest.x) : point32.x;
		result.y = src.y;
	}
	else 
	{
		float k = -((src.x - point32.x) * x0 + (src.y - point32.y) * y0)
			/ (pow(x0, 2) + pow(y0, 2));

		result.x = k * x0 + src.x;
		result.y = k * y0 + src.y;

// 		float k = y0 / x0;
// 		result.x = (pow(k, 2) * src.x + k * (point32.y - src.y) + point32.x) / (pow(k, 2) + 1);
// 		result.y = k * (result.x - src.x) + src.y;

		if (!this->contains(result))
		{
			if (Vector2::distance(src, result) < Vector2::distance(dest, result))
			{
				result = src;
			}
			else
			{
				result = dest;
			}
		}
	}

	return result;
}

float Line2::distance(const Line2& line, const Vector2& point32)
{
	Vector2 v0 = line.dest - line.src;
	Vector2 v1 = point32 - line.src;  

	float top = Vector2::dot(v0, v1);
	float bottom = v0.getLength();

	if (bottom == 0) return 0;

	return top / bottom;
}
