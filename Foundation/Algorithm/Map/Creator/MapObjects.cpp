#include "..\Base\MapObjects.h"

alg::map::MapObjects::MapObjects()
{

}

alg::map::MapObjects::~MapObjects()
{
	if (_createObjectFunc != nullptr) 
		delete _createObjectFunc;
	this->removeAllObjects();
}

void alg::map::MapObjects::setCreateFunc(IMapObjectCreate* func)
{
	if (_createObjectFunc != nullptr) 
		delete _createObjectFunc;
	_createObjectFunc = func;
}

void alg::map::MapObjects::removeAllObjects()
{
	for (auto& item : _mapObjects)
	{
		SAFE_RELEASE(item.second);
	}

	_mapObjects.clear();
}

uint32_t alg::map::MapObjects::getObjectCount() const
{
	return _mapObjects.size();
}

bool alg::map::MapObjects::isEmpty() const
{
	return _mapObjects.empty();
}

const alg::map::MapObject* alg::map::MapObjects::getObject(uint32_t nIndex) const
{
	auto it = _mapObjects.find(nIndex);
	if (it == _mapObjects.end())
	{
		return nullptr;
	}

	return it->second;
}

alg::map::MapObject* alg::map::MapObjects::getObject(uint32_t nIndex)
{
	auto it = _mapObjects.find(nIndex);
	if (it == _mapObjects.end())
	{
		return nullptr;
	}

	return it->second;
}

alg::map::MapObject* alg::map::MapObjects::create()
{
	if (_createObjectFunc == nullptr) return nullptr;
	auto object = _createObjectFunc->create();
	if (object == nullptr) return nullptr;
	SAFE_RETAIN(object);
	object->setMapObjectID(_mapObjectID);
	_mapObjects[_mapObjectID] = object;
	_mapObjectID++;
	return object;
}

void alg::map::MapObjects::increaseID()
{
	_mapObjectID++;
}

const std::map<uint32_t, alg::map::MapObject*>& alg::map::MapObjects::getAllObjects() const
{
	return _mapObjects;
}
