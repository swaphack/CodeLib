#include "Volume.h"

using namespace math;

Volume::Volume()
{

}

Volume::Volume(float w, float h, float d)
{
	this->setWidth(w);
	this->setHeight(h);
	this->setDepth(d);
}

Volume::Volume(const Volume& volumn)
	: Volume(volumn.getWidth(), volumn.getHeight(), volumn.getDepth())
{
}

Volume::Volume(float w, float h)
	: Volume(w, h, 0)
{
}

void Volume::set(float w, float h, float d)
{
	this->setWidth(w);
	this->setHeight(h);
	this->setDepth(d);
}

void Volume::set(float w, float h)
{
	this->setWidth(w);
	this->setHeight(h);
}

Volume Volume::operator*(const Vector3& vec) const
{
	return Volume(getWidth() * vec.getX(), getHeight() * vec.getY(), getDepth() * vec.getZ());
}

Volume& Volume::operator*=(const Vector3& vec)
{
	setWidth(getWidth() * vec.getX());
	setHeight(getHeight() * vec.getY());
	setDepth(getDepth() * vec.getZ());

	return *this;
}

math::Volume::~Volume()
{

}
