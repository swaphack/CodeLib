#include "shape_common.h"

using namespace render;

static float getArea(const sys::Vector3& p1, const sys::Vector3& p2, const sys::Vector3& p3)
{
	float s = 0.5f * (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.x*p3.y - p2.x*p1.y - p3.x*p2.y);
	return abs(s);
}

//////////////////////////////////////////////////////////////////////////
RectangeVertex::RectangeVertex()
{

}

bool RectangeVertex::containPoint(float x, float y)
{
	bool bRet = false;
	
	sys::Vector3 p = sys::Vector3(x, y);

	float s1 = getArea(p, leftUp, leftDown);
	float s2 = getArea(p, leftUp, rightUp);
	float s3 = getArea(p, leftDown, rightDown);
	float s4 = getArea(p, rightDown, rightUp);

	float s5 = getArea(rightUp, leftUp, leftDown) + getArea(rightUp, leftDown, rightDown);

	if (s1 + s2 + s3 + s4 <= s5)
	{
		bRet = true;
	}

	return bRet;
}

sys::Vector3 RectangeVertex::getAnchorByPoint(float x, float y)
{
	sys::Vector3 p;

	p.x = (x - leftUp.x) / (rightUp.x - leftUp.x);
	p.y = (y - leftUp.y) / (leftUp.y - leftDown.y);

	return p;
}
