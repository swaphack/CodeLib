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
	// ���ߣ����ཻ
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
	// �ȼ��жϰ�Χ���Ƿ��ཻ
	if (!bounds0.intersects(bounds1))
	{
		return false;
	}

	Vector2 v0 = src - line.src;
	Vector2 v1 = dest - src;
	Vector2 v2 = line.dest - src;

	float d0 = Vector2::dot(v0, v1);
	float d1 = Vector2::dot(v1, v2);
	// ���ߣ����ཻ
	return d0 * d1 >= 0;
}
/**
*	������߶�ƽ����X�ᣨY�ᣩ�������point�����߶�����ֱ�ߵĴ��ߣ������������ã�Ȼ���������㣬����������߶����򷵻ش��㣬���򷵻��봹����Ķ˵㣻
*	������߶β�ƽ����X��Ҳ��ƽ����Y�ᣬ��б�ʴ����Ҳ�Ϊ0��
*	���߶ε����˵�Ϊpt1��pt2��б��Ϊ��k = ( pt2.y - pt1. y ) / (pt2.x - pt1.x );��ֱ�߷���Ϊ��y = k* ( x - pt1.x) + pt1.y��
*	�䴹�ߵ�б��Ϊ - 1 / k�����߷���Ϊ��y = (-1/k) * (x - point.x) + point.y ��
*
*�� ������ֱ�߷��̽�ã�x = ( k^2 * pt1.x + k * (point.y - pt1.y ) + point.x ) / ( k^2 + 1) ��y = k * ( x - pt1.x) + pt1.y;
*	Ȼ�����жϴ����Ƿ����߶��ϣ�������߶����򷵻ش��㣻���������������˵㵽����ľ��룬ѡ����봹��Ͻ��Ķ˵㷵��
*/
Vector2 Line2::closestPoint(const Vector2& point)
{
	Vector2 result;

	float x0 = dest.x - src.x;
	float y0 = dest.y - src.y;

	if (y0 == 0 && x0 == 0)
	{// �߶�Ϊ��
		return src;
	}
	else if (x0 == 0)
	{ // ƽ����y��
		result.y = point.y > MAX(src.y, dest.y) ? MAX(src.y, dest.y) : point.y;
		result.y = point.y < MIN(src.y, dest.y) ? MIN(src.y, dest.y) : point.y;
		result.x = src.x;
	}
	else if (y0 == 0)
	{// ƽ����x��
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
