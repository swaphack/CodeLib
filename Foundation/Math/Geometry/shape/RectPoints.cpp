#include "RectPoints.h"

using namespace math;

math::RectPoints::RectPoints()
{
}

math::RectPoints::RectPoints(const Vector3& leftBottom, const Vector3& rightBottom, const Vector3& rightTop, const Vector3& leftTop)
{
	this->setLeftBottom(leftBottom);
	this->setRightBottom(rightBottom);
	this->setRightTop(rightTop);
	this->setLeftTop(leftTop);
}

math::RectPoints::RectPoints(const Vector3* points)
{
	if (points == nullptr)
	{
		return;
	}

	this->assign(points);
}

math::RectPoints::~RectPoints()
{
}

math::RectPoints::operator math::Rect()
{
	Vector2 origin(this->getLeftBottom());
	Size size(
		this->getRightTop().getX() - this->getLeftBottom().getX(),
		this->getRightTop().getY() - this->getLeftBottom().getY());

	return Rect(origin, size);
}