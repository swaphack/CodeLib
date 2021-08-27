#include "TrianglePoints.h"
#include <algorithm>

using namespace math;

math::TrianglePoints::TrianglePoints()
{
}

math::TrianglePoints::TrianglePoints(const Vector3& p0, const Vector3& p1, const Vector3& p2)
{
	this->setPoint0(p0);
	this->setPoint1(p1);
	this->setPoint2(p2);
}

math::TrianglePoints::TrianglePoints(const Vector3* points)
{
	if (points == nullptr)
	{
		return;
	}
	this->assign(points);
}

math::TrianglePoints::~TrianglePoints()
{
}

bool math::TrianglePoints::hasSameEdge(const TrianglePoints& target, LineSegment3d& side)
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

Vector3 math::TrianglePoints::getCentreOfGravity(const Vector3& p0, const Vector3& p1, const Vector3& p2)
{
	return 1.0f / 3.0f * (p0 + p1 + p2);
}

Vector3 math::TrianglePoints::getInCenter(const Vector3& p0, const Vector3& p1, const Vector3& p2)
{
	float a = Vector3::distance(p1, p2);
	float b = Vector3::distance(p0, p2);
	float c = Vector3::distance(p0, p1);

	float d = a + b + c;
	if (d == 0) return Vector3();

	float x = p0.getX() * a + p1.getX() * b + p2.getX() * c;
	float y = p0.getY() * a + p1.getY() * b + p2.getY() * c;
	float z = p0.getZ() * a + p1.getZ() * b + p2.getZ() * c;

	return Vector3(x / d, y / d, z / d);
}

Vector3 math::TrianglePoints::getCircumcenter(const Vector3& p0, const Vector3& p1, const Vector3& p2)
{
	float a = Vector3::distance(p1, p2);
	float b = Vector3::distance(p0, p2);
	float c = Vector3::distance(p0, p1);

	Vector3 v12 = p0 - p1;
	Vector3 v21 = p1 - p0;
	
	Vector3 v23 = p1 - p2;
	Vector3 v32 = p2 - p1;

	Vector3 v13 = p0 - p2;
	Vector3 v31 = p2 - p1;

	float d = 2 * Vector3::cross(v12, v23).getSqrMagnitude();
	if (d == 0) return Vector3();

	float alpha = v23.getSqrMagnitude() * Vector3::dot(v12, v13) / d;
	float beta = v13.getSqrMagnitude() * Vector3::dot(v21, v23) / d;
	float gamma = v12.getSqrMagnitude() * Vector3::dot(v31, v32) / d;

	return alpha * p0 + beta * p1 + gamma * p2;
}

Vector3 math::TrianglePoints::getCircumcenter2d(const Vector3& p0, const Vector3& p1, const Vector3& p2)
{
	float dA, dB, dC, aux1, aux2, div;

	dA = p0.getSqrMagnitude();
	dB = p1.getSqrMagnitude();
	dC = p2.getSqrMagnitude();

	aux1 = (dA * (p2.getY() - p1.getY()) + dB * (p0.getY() - p2.getY()) + dC * (p1.getY() - p0.getY()));
	aux2 = -(dA * (p2.getX() - p1.getX()) + dB * (p0.getX() - p2.getX()) + dC * (p1.getX() - p0.getX()));
	div = (2 * (p0.getX() * (p2.getY() - p1.getY()) + p1.getX() * (p0.getY() - p2.getY()) + p2.getX() * (p1.getY() - p0.getY())));

	if (div == 0) return Vector3();

	return Vector3(aux1 / div, aux2 / div);
}

math::Vector3 math::TrianglePoints::getNormal(const Vector3& p0, const Vector3& p1, const Vector3& p2)
{
	Vector3 v0 = p1 - p0;
	Vector3 v1 = p2 - p0;

	Vector3 value = Vector3::cross(v0, v1);
	value.normalize();
	return value;
}
