#include "RectPoints.h"

using namespace math;

math::RectPoints::RectPoints()
{
}

math::RectPoints::RectPoints(const Rect& rect)
{
	this->setLeftBottom(math::Vector3(rect.getMinX(), rect.getMinY()));
	this->setRightBottom(math::Vector3(rect.getMaxX(), rect.getMinY()));
	this->setRightTop(math::Vector3(rect.getMaxX(), rect.getMaxY()));
	this->setLeftTop(math::Vector3(rect.getMinX(), rect.getMaxY()));
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

void math::RectPoints::setVertices(const float* vertices)
{
	if (vertices == nullptr) return;

	std::vector<Vector3> points;
	for (size_t i = 0; i < getLength(); i++)
	{
		Vector3 vertice;
		vertice.assign(vertices + i * 3);
		points.push_back(vertice);
	}
	this->assign(&points[0]);
}

math::RectPoints::operator math::Rect() const
{
	Vector2 origin(this->getLeftBottom());
	Size size(
		this->getRightTop().getX() - this->getLeftBottom().getX(),
		this->getRightTop().getY() - this->getLeftBottom().getY());

	return Rect(origin, size);
}