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

bool math::LineSegment2d::intersects(const LineSegment2d& line, Vector2& point)
{
	Vector2 srcVec = this->getVector();
	Vector2 destVec = line.getVector();

	math::Determinant2 det(srcVec.getX(), srcVec.getY(), destVec.getX(), destVec.getY());
	float value = getDeterminantMagnitude(det);
	if (value == 0)
	{
		return false;
	}

	math::Determinant2 det1(
		line.getSrc().getX() - this->getSrc().getX(),
		line.getSrc().getY() - this->getSrc().getX(),
		destVec.getX(),
		destVec.getY());

	math::Determinant2 det2(
		srcVec.getX(), 
		srcVec.getY(),
		line.getSrc().getX() - this->getSrc().getX(),
		line.getSrc().getY() - this->getSrc().getY());

	float sp = getDeterminantMagnitude(det1) / value;
	float sq = getDeterminantMagnitude(det2) / value;

	if (sp >= 0 && sp <= 1 && sq >= 0 && sq < 1)
	{
		point.setX(getSrc().getX() + sp * srcVec.getX());
		point.setY(getSrc().getY() + sp * srcVec.getY());
		return true;
	}

	return false;
}

math::LineSegment2d::LineSegment2d(Vector2 src, Vector2 dest)
{
	this->setSrc(src);
	this->setDest(dest);
}


