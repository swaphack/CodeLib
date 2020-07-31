#include "LineSegment2.h"
#include "Algebra/Determinant/Determinant.h"

math::LineSegment2::LineSegment2()
{

}

float math::LineSegment2::getMagnitude() const
{
	return math::Vector2::distance(getSrc(), getDest());
}

math::Vector2 math::LineSegment2::getVector() const
{
	return getDest() - getSrc();
}

bool math::LineSegment2::intersects(const LineSegment2& line, Vector2& point)
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

math::LineSegment2::LineSegment2(Vector2 src, Vector2 dest)
{
	this->setSrc(src);
	this->setDest(dest);
}


