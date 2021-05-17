#include "Rectangle.h"

using namespace math;

math::Rectangle::Rectangle()
{
}

math::Rectangle::Rectangle(const Vector3& leftBottom, const Vector3& rightBottom, const Vector3& rightTop, const Vector3& leftTop)
{
	this->setLeftBottom(leftBottom);
	this->setRightBottom(rightBottom);
	this->setRightTop(rightTop);
	this->setLeftTop(leftTop);
}

math::Rectangle::Rectangle(const Vector3* points)
{
	if (points == nullptr)
	{
		return;
	}

	this->assign(points);
}

math::Rectangle::~Rectangle()
{
}