#include "Cuboids3d.h"

using namespace math;


Cuboids3d::Cuboids3d()
{

}

Cuboids3d::Cuboids3d(const Vector3& origin, const Volume& size)
{
	this->_origin = origin;
	this->_size = size;
}

Cuboids3d::Cuboids3d(const Cuboids3d& cuboids)
{
	this->_origin = cuboids._origin;
	this->_size = cuboids._size;
}

Cuboids3d::~Cuboids3d()
{

}

float Cuboids3d::getX() const
{
	return this->_origin.getX();
}

float Cuboids3d::getY() const
{
	return this->_origin.getX();
}

float Cuboids3d::getZ() const
{
	return this->_origin.getZ();
}

float Cuboids3d::getWidth() const
{
	return this->_size.getWidth();
}

float Cuboids3d::getHeight() const
{
	return this->_size.getHeight();
}

float Cuboids3d::getDepth() const
{
	return this->_size.getDepth();
}

float Cuboids3d::getMinX() const
{
	return getX();
}

float Cuboids3d::getMaxX() const
{
	return this->getMinX() + this->getWidth();
}

float Cuboids3d::getMinY() const
{
	return getY();
}

float Cuboids3d::getMaxY() const
{
	return this->getMinY() + this->getHeight();
}

float Cuboids3d::getMinZ() const
{
	return getZ();
}

float Cuboids3d::getMaxZ() const
{
	return getZ() + getDepth();
}

const Vector3& Cuboids3d::getOrigin() const
{
	return _origin;
}

const Volume& Cuboids3d::getSize() const
{
	return _size;
}

void Cuboids3d::set(const Vector3& orgin, const Volume& size)
{
	this->_origin = orgin;
	this->_size = size;
}

bool Cuboids3d::contains(float x, float y, float z)
{
	return (x >= getMinX() && x <= getMaxX())
		&& (y >= getMinY() && y <= getMaxY())
		&& (z >= getMinZ() && z <= getMaxZ());
}

bool Cuboids3d::contains(const Vector3& point)
{
	return contains(point.getX(), point.getY(), point.getZ());
}

bool Cuboids3d::intersect(const Cuboids3d& cuboids)
{
	Vector3 points[8];

	points[0] = cuboids.getOrigin();
	points[1] = points[0] + Vector3(cuboids.getWidth(), 0, 0);
	points[2] = points[0] + Vector3(cuboids.getWidth(), cuboids.getHeight(), 0);
	points[3] = points[0] + Vector3(0, cuboids.getHeight(), 0);
	points[4] = points[0] + Vector3(cuboids.getWidth(), 0, cuboids.getDepth());
	points[5] = points[0] + Vector3(cuboids.getWidth(), cuboids.getHeight(), cuboids.getDepth());
	points[6] = points[0] + Vector3(0, cuboids.getHeight(), cuboids.getDepth());
	points[7] = points[0] + Vector3(cuboids.getWidth(), cuboids.getHeight(), cuboids.getDepth());

	for (int i = 0; i < 8; i++)
	{
		if (this->contains(points[i]))
		{
			return true;
		}
	}

	return false;
}

Cuboids3d& Cuboids3d::operator=(const Cuboids3d& cuboids)
{
	this->_origin = cuboids._origin;
	this->_size = cuboids._size;

	return *this;
}
