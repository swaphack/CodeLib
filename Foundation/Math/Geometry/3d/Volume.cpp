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

Volume::Volume(const Volume& volume)
	: Volume(volume.getWidth(), volume.getHeight(), volume.getDepth())
{
}

Volume::Volume(float w, float h)
	: Volume(w, h, 0)
{
}

math::Volume::~Volume()
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

math::Volume math::Volume::operator*(float k) const
{
	return Volume(getWidth() * k, getHeight() * k, getDepth() * k);
}

math::Volume& math::Volume::operator*=(float k)
{
	setWidth(getWidth() * k);
	setHeight(getHeight() * k);
	setDepth(getDepth() * k);

	return *this;
}

bool math::Volume::operator==(const Volume& vec) const
{
	return getWidth() == vec.getWidth() && getHeight() == vec.getHeight() && getDepth() == vec.getDepth();
}

bool math::Volume::operator!=(const Volume& vec) const
{
	return getWidth() != vec.getWidth() || getHeight() != vec.getHeight() || getDepth() != vec.getDepth();
}

math::Volume::operator math::Vector3() const
{
	return math::Vector3(getWidth(), getHeight(), getDepth());
}


