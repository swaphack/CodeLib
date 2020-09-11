#include "MapObject.h"

alg::MapObject::MapObject()
{

}

alg::MapObject::~MapObject()
{

}

void alg::MapObject::setObjectIndex(uint32_t nIndex)
{
	_objectIndex = nIndex;
}

uint32_t alg::MapObject::getObjectIndex() const
{
	return _objectIndex;
}
