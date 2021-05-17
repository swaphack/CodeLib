#include "Line.h"

using namespace math;

math::Line::Line()
{
}

math::Line::Line(const Vector3& p0, const Vector3& p1)
{
	this->setPoint0(p0);
	this->setPoint1(p1);
}

math::Line::Line(const Vector3* points)
{
	if (points == nullptr)
	{
		return;
	}
	this->assign(points);
}

math::Line::~Line()
{
}

bool math::Line::operator==(const Line& line) const
{
	return (getPoint0() == line.getPoint0() && getPoint1() == line.getPoint1())
		|| (getPoint1() == line.getPoint0() && getPoint0() == line.getPoint1());
}

bool math::Line::operator!=(const Line& line) const
{
	return ! (*this == line);
}
