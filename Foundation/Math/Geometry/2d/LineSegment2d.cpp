#include "LineSegment2d.h"
#include "Algebra/Determinant/Determinant.h"

math::LineSegment2d::LineSegment2d()
{

}

float math::LineSegment2d::getMagnitude() const
{
	return math::Vector2::distance(getSrc(), getDest());
}

math::Vector2 math::LineSegment2d::getVector() const
{
	return getDest() - getSrc();
}

bool math::LineSegment2d::intersects(const LineSegment2d& line, Vector2& point) const
{
	Vector2 srcVec = this->getVector();
	Vector2 srcVec0 = line.getSrc() - this->getSrc();
	Vector2 srcVec1 = line.getDest() - this->getSrc();

	float d0 = Vector2::cross(srcVec, srcVec0);
	float d1 = Vector2::cross(srcVec, srcVec1);

	if (d0 * d1 >= 0) return false;

	Vector2 destVec = line.getVector();
	Vector2 destVec0 = this->getSrc() - line.getSrc();
	Vector2 destVec1 = this->getDest() - line.getSrc();

	float d2 = Vector2::cross(destVec, destVec0);
	float d3 = Vector2::cross(destVec, destVec1);

	if (d2 * d3 >= 0) return false;

	float t = Vector2::cross(destVec0, destVec) / Vector2::cross(destVec, srcVec);

	float dx = t * (this->getDest().getX() - this->getSrc().getX());
	float dy = t * (this->getDest().getY() - this->getSrc().getY());

	point = this->getSrc() + Vector2(dx, dy);

	return true;
}

math::LineSegment2d::LineSegment2d(const Vector2& src, const Vector2& dest)
{
	this->setSrc(src);
	this->setDest(dest);
}

math::LineSegment2d::LineSegment2d(const Vector3& src, const Vector3& dest)
{
	this->setSrc(src);
	this->setDest(dest);
}


