#include "shape_commond.h"

using namespace render;

float getArea(const sys::Vector& p1, const sys::Vector& p2, const sys::Vector& p3)
{
	float s = 0.5f * (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.x*p3.y - p2.x*p1.y - p3.x*p2.y);
	return abs(s);
}

RectangeVertex::RectangeVertex()
{

}

bool RectangeVertex::containPoint(float x, float y)
{
	bool bRet = false;

// 	if (x >= leftDown.x && x <= rightDown.x
// 		&& y >= leftDown.y && y <= leftUp.y)
// 	{
// 		bRet = true;
// 	}
	
	sys::Vector p = sys::Vector(x, y);

	float s1 = getArea(p, leftUp, leftDown);
	float s2 = getArea(p, leftUp, rightUp);
	float s3 = getArea(p, leftDown, rightDown);
	float s4 = getArea(p, rightDown, rightUp);

	float s5 = getArea(rightUp, leftUp, leftDown) + getArea(rightUp, leftDown, rightDown);

	// 转化为opengl（0，1）会有误差
	if (s1 + s2 + s3 + s4 <= s5)
	{
		bRet = true;
	}

	return bRet;
}

bool RectangeVertex::containPoint(float x, float y, float z)
{
	return false;
}