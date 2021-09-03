#include "CubePoints.h"

math::CubePoints::CubePoints()
{

}

math::CubePoints::CubePoints(const Vector3& frontLeftBottom, const Vector3& frontRightBottom, const Vector3& frontRightTop, const Vector3& frontLeftTop,
	const Vector3& backLeftBottom, const Vector3& backRightBottom, const Vector3& backRightTop, const Vector3& backLeftTop)
{
	this->setPoints(frontLeftBottom, frontRightBottom, frontRightTop, frontLeftTop,
		backLeftBottom, backRightBottom, backRightTop, backLeftTop);
}

math::CubePoints::CubePoints(const Vector3& frontLeftBottom, const Vector3& backRightTop)
{
	this->setPoints(frontLeftBottom, backRightTop);
}

math::CubePoints::CubePoints(const RectPoints& front, const RectPoints& back)
{
	this->setPoints(front, back);
}

math::CubePoints::CubePoints(const Vector3* points)
{
	if (points == nullptr) return;
	this->assign(points);
}

math::CubePoints::CubePoints(const std::vector<Vector3>& points)
{
	this->setPoints(points);
}

math::CubePoints::~CubePoints()
{
}

void math::CubePoints::setPoints(const Vector3& frontLeftBottom, const Vector3& frontRightBottom, const Vector3& frontRightTop, const Vector3& frontLeftTop, const Vector3& backLeftBottom, const Vector3& backRightBottom, const Vector3& backRightTop, const Vector3& backLeftTop)
{
	this->setFrontLeftBottom(frontLeftBottom);
	this->setFrontRightBottom(frontRightBottom);
	this->setFrontRightTop(frontRightTop);
	this->setFrontLeftTop(frontLeftTop);

	this->setBackLeftBottom(backLeftBottom);
	this->setBackRightBottom(backRightBottom);
	this->setBackRightTop(backRightTop);
	this->setBackLeftTop(backLeftTop);
}

void math::CubePoints::setPoints(const Vector3& frontLeftBottom, const Vector3& backRightTop)
{
	Vector3 frontRightBottom(backRightTop.getX(), frontLeftBottom.getY(), frontLeftBottom.getZ());
	Vector3 frontRightTop(backRightTop.getX(), backRightTop.getY(), frontLeftBottom.getZ());
	Vector3 frontLeftTop(frontLeftBottom.getX(), backRightTop.getY(), frontLeftBottom.getZ());

	Vector3 backLeftBottom(backRightTop.getX(), frontLeftBottom.getY(), backRightTop.getZ());
	Vector3 backRightBottom(frontLeftBottom.getX(), frontLeftBottom.getY(), backRightTop.getZ());
	Vector3 backLeftTop(frontLeftBottom.getX(), backRightTop.getY(), backRightTop.getZ());

	this->setFrontLeftBottom(frontLeftBottom);
	this->setFrontRightBottom(frontRightBottom);
	this->setFrontRightTop(frontRightTop);
	this->setFrontLeftTop(frontLeftTop);

	this->setBackLeftBottom(backLeftBottom);
	this->setBackRightBottom(backRightBottom);
	this->setBackRightTop(backRightTop);
	this->setBackLeftTop(backLeftTop);
}

void math::CubePoints::setPoints(const RectPoints& front, const RectPoints& back)
{
	this->setFrontLeftBottom(front.getLeftBottom());
	this->setFrontRightBottom(front.getRightBottom());
	this->setFrontRightTop(front.getRightTop());
	this->setFrontLeftTop(front.getLeftTop());

	this->setBackLeftBottom(back.getLeftBottom());
	this->setBackRightBottom(back.getRightBottom());
	this->setBackRightTop(back.getRightTop());
	this->setBackLeftTop(back.getLeftTop());
}

void math::CubePoints::setPoints(const std::vector<Vector3>& points)
{
	if (points.size() != this->getLength()) return;

	this->assign(&points[0]);
}

math::CubePoints::operator math::Cuboids() const
{
	Cuboids cuboids;
	cuboids.set(this->getFrontLeftBottom(), this->getBackRightTop() - this->getFrontLeftBottom());
	return cuboids;
}
