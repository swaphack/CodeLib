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

bool math::Triangle::hasSameEdge(const Triangle& target, LineSegment3d& side)
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

	side.setSrc(this->getValue(index0));

	const Vector3& left0 = this->getValue((index0 - 1 + getLength()) % getLength());
	const Vector3& right0 = this->getValue((index0 + 1 + getLength()) % getLength());

	const Vector3& left1 = this->getValue((index1 - 1 + getLength()) % getLength());			 
	const Vector3& right1 = this->getValue((index1 + 1 + getLength()) % getLength());

	if (left0 == left1 || left0 == right1)
	{
		side.setDest(left0);
		return true;
	}
	else if (right0 == left1 || right0 == right1)
	{
		side.setDest(right0);
		return true;
	}

	return false;
}

Vector3 math::Triangle::getCentreOfGravity() const
{
	return 1.0f / 3.0f * (getPoint0() + getPoint1() + getPoint2());
}

Vector3 math::Triangle::getInCenter() const
{
	float a = Vector3::distance(getPoint1(), getPoint2());
	float b = Vector3::distance(getPoint0(), getPoint2());
	float c = Vector3::distance(getPoint0(), getPoint1());

	float d = a + b + c;
	if (d == 0) return Vector3();

	float x = getPoint0().getX() * a + getPoint1().getX() * b + getPoint2().getX() * c;
	float y = getPoint0().getY() * a + getPoint1().getY() * b + getPoint2().getY() * c;
	float z = getPoint0().getZ() * a + getPoint1().getZ() * b + getPoint2().getZ() * c;

	return Vector3(x / d, y / d, z / d);
}

Vector3 math::Triangle::getCircumcenter() const
{
	float a = Vector3::distance(getPoint1(), getPoint2());
	float b = Vector3::distance(getPoint0(), getPoint2());
	float c = Vector3::distance(getPoint0(), getPoint1());

	Vector3 v12 = getPoint0() - getPoint1();
	Vector3 v21 = getPoint1() - getPoint0();
	
	Vector3 v23 = getPoint1() - getPoint2();
	Vector3 v32 = getPoint2() - getPoint1();

	Vector3 v13 = getPoint0() - getPoint2();
	Vector3 v31 = getPoint2() - getPoint1();

	float d = 2 * Vector3::cross(v12, v23).getMagnitudeSqr();
	if (d == 0) return Vector3();

	float alpha = v23.getMagnitudeSqr() * Vector3::dot(v12, v13) / d;
	float beta = v13.getMagnitudeSqr() * Vector3::dot(v21, v23) / d;
	float gamma = v12.getMagnitudeSqr() * Vector3::dot(v31, v32) / d;

	return alpha * getPoint0() + beta * getPoint1() + gamma * getPoint2();
}

Vector3 math::Triangle::getCircumcenter2d() const
{
	float dA, dB, dC, aux1, aux2, div;

	dA = getPoint0().getMagnitudeSqr();
	dB = getPoint1().getMagnitudeSqr();
	dC = getPoint2().getMagnitudeSqr();

	aux1 = (dA * (getPoint2().getY() - getPoint1().getY()) + dB * (getPoint0().getY() - getPoint2().getY()) + dC * (getPoint1().getY() - getPoint0().getY()));
	aux2 = -(dA * (getPoint2().getX() - getPoint1().getX()) + dB * (getPoint0().getX() - getPoint2().getX()) + dC * (getPoint1().getX() - getPoint0().getX()));
	div = (2 * (getPoint0().getX() * (getPoint2().getY() - getPoint1().getY()) + getPoint1().getX() * (getPoint0().getY() - getPoint2().getY()) + getPoint2().getX() * (getPoint1().getY() - getPoint0().getY())));

	if (div == 0) return Vector3();

	return Vector3(aux1 / div, aux2 / div);
}

math::Vector3 math::Triangle::getNormal()
{
	Vector3 v0 = this->getPoint1() - this->getPoint0();
	Vector3 v1 = this->getPoint2() - this->getPoint0();

	return Vector3::cross(v0, v1);
}
