#include "Cuboids.h"

using namespace math;


Cuboids::Cuboids()
{

}

Cuboids::Cuboids(const Vector3& origin, const Volume& size)
{
	this->_origin = origin;
	this->_size = size;
}

Cuboids::Cuboids(const Cuboids& cuboids)
{
	this->_origin = cuboids._origin;
	this->_size = cuboids._size;
}

Cuboids::~Cuboids()
{

}

float Cuboids::getX() const
{
	return this->_origin.getX();
}

float Cuboids::getY() const
{
	return this->_origin.getX();
}

float Cuboids::getZ() const
{
	return this->_origin.getZ();
}

float Cuboids::getWidth() const
{
	return this->_size.getWidth();
}

float Cuboids::getHeight() const
{
	return this->_size.getHeight();
}

float Cuboids::getDepth() const
{
	return this->_size.getDepth();
}

float Cuboids::getMinX() const
{
	return getX();
}

float Cuboids::getMaxX() const
{
	return this->getMinX() + this->getWidth();
}

float Cuboids::getMinY() const
{
	return getY();
}

float Cuboids::getMaxY() const
{
	return this->getMinY() + this->getHeight();
}

float Cuboids::getMinZ() const
{
	return getZ();
}

float Cuboids::getMaxZ() const
{
	return getZ() + getDepth();
}

const Vector3& Cuboids::getOrigin() const
{
	return _origin;
}

const Volume& Cuboids::getSize() const
{
	return _size;
}

void Cuboids::set(const Vector3& orgin, const Volume& size)
{
	this->_origin = orgin;
	this->_size = size;
}

bool Cuboids::contains(float x, float y, float z)
{
	return (x >= getMinX() && x <= getMaxX())
		&& (y >= getMinY() && y <= getMaxY())
		&& (z >= getMinZ() && z <= getMaxZ());
}

bool Cuboids::contains(const Vector3& point)
{
	return contains(point.getX(), point.getY(), point.getZ());
}

bool Cuboids::intersect(const Cuboids& cuboids)
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

Cuboids& Cuboids::operator=(const Cuboids& cuboids)
{
	this->_origin = cuboids._origin;
	this->_size = cuboids._size;

	return *this;
}
