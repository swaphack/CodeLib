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
	Vector2 destVec = line.getVector();

	float val0[] = { srcVec.getX(), srcVec.getY(), destVec.getX(), destVec.getY() };
	math::Determinant2 det(val0);
	float value = getDetMagnitude(det);
	if (value == 0)
	{
		return false;
	}

	Vector2 diffVec = line.getSrc() - this->getSrc();

	float val1[] = 
	{
		diffVec.getX(),
		diffVec.getY(),
		destVec.getX(),
		destVec.getY() 
	};

	float val2[] =
	{
		srcVec.getX(),
		srcVec.getY(),
		diffVec.getX(),
		diffVec.getY()
	};

	math::Determinant2 det1(val1);
	math::Determinant2 det2(val2);
	
	float sp = getDetMagnitude(det1) / value;
	float sq = getDetMagnitude(det2) / value;

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

math::LineSegment2d::LineSegment2d(Vector3 src, Vector3 dest)
{
	this->setSrc(src);
	this->setDest(dest);
}


