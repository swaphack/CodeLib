#include "shape_common.h"

using namespace render;

static float getArea(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3)
{
	float s = 0.5f * (p1.getX()*p2.getY() + p2.getX()*p3.getY() + p3.getX()*p1.getY() - p1.getX()*p3.getY() - p2.getX()*p1.getY() - p3.getX()*p2.getY());
	return abs(s);
}

//////////////////////////////////////////////////////////////////////////
RectVectices::RectVectices()
{

}

bool RectVectices::containPoint(float x, float y)
{
	bool bRet = false;
	
	math::Vector3 p = math::Vector3(x, y);

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

math::Vector3 RectVectices::getAnchorByPoint(float x, float y)
{
	float xx = (x - leftUp.getX()) / (rightUp.getX() - leftUp.getX());
	float yy = (y - leftUp.getY()) / (leftUp.getY() - leftDown.getY());

	return math::Vector3(xx, yy);
}
