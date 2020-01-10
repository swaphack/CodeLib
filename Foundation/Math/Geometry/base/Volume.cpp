#include "Volume.h"

using namespace math;

Volume::Volume()
	:Vector(3)
{

}

Volume::Volume(float w, float h, float d)
	: Volume()
{
	this->setWidth(w);
	this->setHeight(h);
	this->setDeep(d);
}

Volume::Volume(const Volume& volumn)
	: Volume(volumn.getWidth(), volumn.getHeight(), volumn.getDeep())
{
}

Volume::Volume(float w, float h)
	: Volume(w,h, 0)
{
}

void Volume::set(float w, float h, float d)
{
	this->setWidth(w);
	this->setHeight(h);
	this->setDeep(h);
}

void Volume::set(float w, float h)
{
	this->setWidth(w);
	this->setHeight(h);
}

Volume Volume::operator*(const Vector3& vec) const
{
	return Volume(getWidth() * vec.getX(), getHeight() * vec.getY(), getDeep() * vec.getZ());
}

Volume& Volume::operator*=(const Vector3& vec)
{
	setWidth(getWidth() * vec.getX());
	setHeight(getHeight() * vec.getY());
	setDeep(getDeep() * vec.getZ());

	return *this;
}
