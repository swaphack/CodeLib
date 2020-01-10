#include "VolumeProtocol.h"

using namespace slg;

VolumeProtocol::VolumeProtocol()
:_volume(math::Volume::One)
{

}

VolumeProtocol::~VolumeProtocol()
{

}

void VolumeProtocol::setWidth(int width)
{
	_volume.width = width;
}

int VolumeProtocol::getWidth()
{
	return _volume.width;
}

void VolumeProtocol::setHeight(int height)
{
	_volume.height = height;
}

int VolumeProtocol::getHeight()
{
	return _volume.height;
}

void VolumeProtocol::setDeep(int deep)
{
	_volume.deep = deep;
}

int VolumeProtocol::getDeep()
{
	return _volume.deep;
}
