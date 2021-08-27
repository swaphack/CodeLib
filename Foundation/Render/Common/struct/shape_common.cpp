#include "shape_common.h"
#include "mathlib.h"
using namespace render;

RectPoints::RectPoints()
{

}

bool RectPoints::containPointByArea(float x, float y)
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

math::Vector3 RectPoints::getAnchorPointByPosition(float x, float y)
{
	float xx = (x - leftDown.getX()) / (rightUp.getX() - leftDown.getX());
	float yy = (y - leftDown.getY()) / (rightUp.getY() - leftDown.getY());

	return math::Vector3(xx, yy);
}

bool render::RectPoints::isAllInRangeOfRect(float x, float y, float w, float h)
{
	return leftDown.getX() >= x && leftDown.getY() >= y
		&& rightUp.getX() <= (x + w) && rightUp.getY() <= (y + h);
}

bool RectPoints::containPointByPolygon(float x, float y)
{
	math::Vector2 nvec[4];
	nvec[0] = math::Vector2(leftDown.getX(), leftDown.getY());
	nvec[1] = math::Vector2(rightDown.getX(), rightDown.getY());
	nvec[2] = math::Vector2(rightUp.getX(), rightUp.getY());
	nvec[3] = math::Vector2(leftUp.getX(), leftUp.getY());

	math::PolygonPoints<4> p(nvec);
	return p.contains(math::Vector2(x, y));
}

float RectPoints::getArea(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3)
{
	math::Vector3 v1 = p2 - p1;
	math::Vector3 v2 = p3 - p1;

	return 0.5f * math::Vector3::dot(v1, v2);
}

bool render::RectPoints::isPartInRangeOfRect(float x, float y, float w, float h)
{
	float width = x + w;
	float height = y + h;
	return (leftDown.getX() >= x && leftDown.getX() >= width)
		|| (leftDown.getY() >= y && leftDown.getY() >= height)
		|| (rightUp.getX() >= x && rightUp.getX() >= width)
		|| (rightUp.getY() >= y && rightUp.getY() >= height);
}

float render::RectPoints::getX()
{
	return leftDown.getX();
}

float render::RectPoints::getY()
{
	return leftDown.getY();
}

float render::RectPoints::getWidth()
{
	return rightDown.getX() - leftDown.getX();
}

float render::RectPoints::getHeight()
{
	return rightUp.getY() - rightDown.getY();
}

//////////////////////////////////////////////////////////////////////////
void render::CubePoints::setFrontLeftDownPosition(const math::Vector3& point)
{
	front.leftDown = point;
	left.rightDown = point;
	bottom.leftUp = point;
}

void render::CubePoints::setFrontRightDownPosition(const math::Vector3& point)
{
	front.rightDown = point;
	right.leftDown = point;
	bottom.rightUp = point;
}

void render::CubePoints::setFrontRightUpPosition(const math::Vector3& point)
{
	front.rightUp = point;
	right.leftUp = point;
	top.rightDown = point;
}

void render::CubePoints::setFrontLeftUpPosition(const math::Vector3& point)
{
	front.leftUp = point;
	left.rightUp = point;
	top.leftDown = point;
}

void render::CubePoints::setBackLeftDownPosition(const math::Vector3& point)
{
	back.rightDown = point;
	left.leftDown = point;
	bottom.leftDown = point;
}

void render::CubePoints::setBackRightDownPosition(const math::Vector3& point)
{
	back.leftDown = point;
	right.rightDown = point;
	bottom.rightDown = point;
}

void render::CubePoints::setBackRightUpPosition(const math::Vector3& point)
{
	back.leftUp = point;
	top.rightUp = point;
	right.rightUp = point;
}

void render::CubePoints::setBackLeftUpPosition(const math::Vector3& point)
{
	back.rightUp = point;
	left.leftUp = point;
	top.leftUp = point;
}

bool render::CubePoints::containPointByPolygon(float x, float y)
{
	// ͶӰ
	return front.containPointByPolygon(x, y)
		|| back.containPointByPolygon(x, y)
		|| left.containPointByPolygon(x, y)
		|| right.containPointByPolygon(x, y)
		|| top.containPointByPolygon(x, y)
		|| bottom.containPointByPolygon(x, y);
}
