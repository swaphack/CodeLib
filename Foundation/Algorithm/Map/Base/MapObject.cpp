#include "MapObject.h"

alg::map::MapObject::MapObject()
{

}

alg::map::MapObject::~MapObject()
{

}

void alg::map::MapObject::setMapObjectID(uint32_t nIndex)
{
	_mapObjectID = nIndex;
}

uint32_t alg::map::MapObject::getMapObjectID() const
{
	return _mapObjectID;
}
