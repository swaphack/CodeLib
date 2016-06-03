#include "LocationProtocol.h"

using namespace slg;


LocationProtocol::LocationProtocol()
{

}

LocationProtocol::~LocationProtocol()
{

}

int LocationProtocol::getPositionX()
{
	return _position.x;
}

void LocationProtocol::setPositionX(int x)
{
	_position.x = x;
}

int LocationProtocol::getPositionY()
{
	return _position.y;
}

void LocationProtocol::setPositionY(int y)
{
	_position.y = y;
}

int LocationProtocol::getPositionZ()
{
	return _position.z;
}


void LocationProtocol::setPositionZ(int z)
{
	_position.z = z;
}
