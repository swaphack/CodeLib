#include "shape_common.h"
#include "mathlib.h"
using namespace render;

RectVectices::RectVectices()
{

}

bool RectVectices::containPointByArea(float x, float y)
{
	bool bRet = false;
	
	math::Vector3 p = math::Vector3(x, y);

	double s1 = getArea(p, leftUp, leftDown);
	double s2 = getArea(p, leftUp, rightUp);
	double s3 = getArea(p, leftDown, rightDown);
	double s4 = getArea(p, rightDown, rightUp);

	double s5 = getArea(rightUp, leftUp, leftDown) + getArea(rightUp, leftDown, rightDown);

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

bool RectVectices::containPointByPolygon(float x, float y)
{
	math::Vector2 nvec[4];
	nvec[0] = math::Vector2(leftDown.getX(), leftDown.getY());
	nvec[1] = math::Vector2(rightDown.getX(), rightDown.getY());
	nvec[2] = math::Vector2(rightUp.getX(), rightUp.getY());
	nvec[3] = math::Vector2(leftUp.getX(), leftUp.getY());

	math::Polygon p(4, nvec);
	return p.contains(math::Vector2(x, y));
}

double RectVectices::getArea(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3)
{
	double s = 0.5 * (p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY() - p1.getX() * p3.getY() - p2.getX() * p1.getY() - p3.getX() * p2.getY());
	return abs(s);
}

float render::RectVectices::getX()
{
	return leftDown.getX();
}

float render::RectVectices::getY()
{
	return leftDown.getY();
}

float render::RectVectices::getWidth()
{
	return rightDown.getX() - leftDown.getX();
}

float render::RectVectices::getHeight()
{
	return rightUp.getY() - rightDown.getY();
}

//////////////////////////////////////////////////////////////////////////
void render::CubeVectices::setFrontLeftDownPosition(const math::Vector3& point)
{
	front.leftDown = point;
	left.rightDown = point;
	bottom.leftUp = point;
}

void render::CubeVectices::setFrontRightDownPosition(const math::Vector3& point)
{
	front.rightDown = point;
	right.leftDown = point;
	bottom.rightUp = point;
}

void render::CubeVectices::setFrontRightUpPosition(const math::Vector3& point)
{
	front.rightUp = point;
	right.leftUp = point;
	top.rightDown = point;
}

void render::CubeVectices::setFrontLeftUpPosition(const math::Vector3& point)
{
	front.leftUp = point;
	left.rightUp = point;
	top.leftDown = point;
}

void render::CubeVectices::setBackLeftDownPosition(const math::Vector3& point)
{
	back.rightDown = point;
	left.leftDown = point;
	bottom.leftDown = point;
}

void render::CubeVectices::setBackRightDownPosition(const math::Vector3& point)
{
	back.leftDown = point;
	right.rightDown = point;
	bottom.rightDown = point;
}

void render::CubeVectices::setBackRightUpPosition(const math::Vector3& point)
{
	back.leftUp = point;
	top.rightUp = point;
	right.rightUp = point;
}

void render::CubeVectices::setBackLeftUpPosition(const math::Vector3& point)
{
	back.rightUp = point;
	left.leftUp = point;
	top.leftUp = point;
}

bool render::CubeVectices::containPointByPolygon(float x, float y)
{
	// ͶӰ
	return front.containPointByPolygon(x, y)
		|| back.containPointByPolygon(x, y)
		|| left.containPointByPolygon(x, y)
		|| right.containPointByPolygon(x, y)
		|| top.containPointByPolygon(x, y)
		|| bottom.containPointByPolygon(x, y);
}
