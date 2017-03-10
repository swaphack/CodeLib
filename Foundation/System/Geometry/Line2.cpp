#include "Line2.h"
#include "../Collider/import.h"

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

bool Line2::contains(const Vector2& point)
{
	Vector2 v0 = point - src;
	Vector2 v1 = dest - src;

	if (Vector2::dot(v0, v1) != 0)
	{
		return false;
	}

	AABB bounds = getBounds();
	return bounds.contains(point);
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

bool Line2::intersects(const Line2& line)
{
	AABB bounds0 = getBounds();
	AABB bounds1 = line.getBounds();
	// 先简单判断包围盒是否相交
	if (!bounds0.intersects(bounds1))
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
*	如果该线段平行于X轴（Y轴），则过点point作该线段所在直线的垂线，垂足很容易求得，然后计算出垂足，如果垂足在线段上则返回垂足，否则返回离垂足近的端点；
*	如果该线段不平行于X轴也不平行于Y轴，则斜率存在且不为0。
*	设线段的两端点为pt1和pt2，斜率为：k = ( pt2.y - pt1. y ) / (pt2.x - pt1.x );该直线方程为：y = k* ( x - pt1.x) + pt1.y。
*	其垂线的斜率为 - 1 / k，垂线方程为：y = (-1/k) * (x - point.x) + point.y 。
*
*　 联立两直线方程解得：x = ( k^2 * pt1.x + k * (point.y - pt1.y ) + point.x ) / ( k^2 + 1) ，y = k * ( x - pt1.x) + pt1.y;
*	然后再判断垂足是否在线段上，如果在线段上则返回垂足；如果不在则计算两端点到垂足的距离，选择距离垂足较近的端点返回
*/
Vector2 Line2::closestPoint(const Vector2& point)
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
		result.y = point.y > MAX(src.y, dest.y) ? MAX(src.y, dest.y) : point.y;
		result.y = point.y < MIN(src.y, dest.y) ? MIN(src.y, dest.y) : point.y;
		result.x = src.x;
	}
	else if (y0 == 0)
	{// 平行于x轴
		result.x = point.x > MAX(src.x, dest.x) ? MAX(src.x, dest.x) : point.x;
		result.x = point.x < MIN(src.x, dest.x) ? MIN(src.x, dest.x) : point.x;
		result.y = src.y;
	}
	else 
	{
		float k = -((src.x - point.x) * x0 + (src.y - point.y) * y0)
			/ (pow(x0, 2) + pow(y0, 2));

		result.x = k * x0 + src.x;
		result.y = k * y0 + src.y;

// 		float k = y0 / x0;
// 		result.x = (pow(k, 2) * src.x + k * (point.y - src.y) + point.x) / (pow(k, 2) + 1);
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

float Line2::distance(const Line2& line, const Vector2& point)
{
// 	float x0 = line.dest.x - line.src.x;
// 	float y0 = line.dest.y - line.src.y;
// 
// 	float a = y0;
// 	float b = -x0;
// 	float c = line.src.y * x0 - line.src.x * y0;
// 	float top = abs(a * point.x + b * point.y  + c);
// 	float bottom = sqrt(pow(a, 2) + pow(b, 2));
// 
// 	if (bottom == 0) return 0;
// 
// 	return top / bottom;


	Vector2 v0 = line.dest - line.src;
	Vector2 v1 = point - line.src;

	float top = Vector2::cross(v0, v1).getLength();
	float bottom = v0.getLength();

	if (bottom == 0) return 0;

	return top / bottom;
}
