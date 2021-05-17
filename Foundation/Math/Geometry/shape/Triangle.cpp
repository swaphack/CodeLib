#include "Triangle.h"
#include <algorithm>

using namespace math;

math::Triangle::Triangle()
{
}

math::Triangle::Triangle(const Vector3& p0, const Vector3& p1, const Vector3& p2)
{
	this->setPoint0(p0);
	this->setPoint1(p1);
	this->setPoint2(p2);
}

math::Triangle::Triangle(const Vector3* points)
{
	if (points == nullptr)
	{
		return;
	}
	this->assign(points);
}

math::Triangle::~Triangle()
{
}

bool math::Triangle::hasSameEdge(const Triangle& target, Line& side)
{
	std::vector<Vector3> points;

	int index0 = -1;
	int index1 = -1;

	for (int i = 0; i < getLength(); i++)
	{
		for (int j = 0; j < getLength(); j++)
		{
			if (this->getValue(i) == target.getValue(j))
			{
				index0 = i;
				index1 = j;
				break;
			}
		}
	}

	if (index0 == -1 ||  index1 == -1)
	{
		return false;
	}

	side.setPoint0(this->getValue(index0));

	const Vector3& left0 = this->getValue((index0 - 1 + getLength()) % getLength());
	const Vector3& right0 = this->getValue((index0 + 1 + getLength()) % getLength());

	const Vector3& left1 = this->getValue((index1 - 1 + getLength()) % getLength());			 
	const Vector3& right1 = this->getValue((index1 + 1 + getLength()) % getLength());

	if (left0 == left1 || left0 == right1)
	{
		side.setPoint1(left0);
		return true;
	}
	else if (right0 == left1 || right0 == right1)
	{
		side.setPoint1(right0);
		return true;
	}

	return false;
}
