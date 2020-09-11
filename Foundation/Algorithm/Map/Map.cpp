#include "Map.h"
#include <algorithm>
#include <cstdarg>

alg::MapPoint::MapPoint()
{

}

alg::MapPoint::~MapPoint()
{

}

void alg::MapPoint::setPosition(const math::Vector3& pos)
{
	_position = pos;
}

const math::Vector3& alg::MapPoint::getPosition() const
{
	return _position;
}

//////////////////////////////////////////////////////////////////////////
alg::MapRelation::MapRelation()
{

}

alg::MapRelation::~MapRelation()
{

}

alg::MapRelation::~MapRelation()
{
	this->removeAllMapIndices();
}

void alg::MapRelation::addMapIndex(uint32_t mapIndex)
{
	_mapIndices.push_back(mapIndex);
}

void alg::MapRelation::addMapIndex(uint32_t nLength, uint32_t startIndex, va_list ap)
{
	uint32_t* value = math::GET_PARAMETERS(nLength, startIndex, ap);

	_mapIndices.resize(nLength);
	memcpy(&_mapIndices[0], value, nLength * sizeof(uint32_t));
	free(value);
}

void alg::MapRelation::addMapIndex(uint32_t nLength, uint32_t startIndex, ...)
{
	uint32_t* value = math::GET_PARAMETERS(nLength, startIndex);
	_mapIndices.resize(nLength);
	memcpy(&_mapIndices[0], value, nLength * sizeof(uint32_t));
	free(value);
}

void alg::MapRelation::removeMapIndex(uint32_t mapIndex)
{
	auto it = std::find(_mapIndices.begin(), _mapIndices.end(), mapIndex);
	if (it != _mapIndices.end())
	{
		_mapIndices.erase(it);
	}
}

void alg::MapRelation::removeAllMapIndices()
{
	_mapIndices.clear();
}

bool alg::MapRelation::containMapIndex(uint32_t mapIndex) const
{
	auto it = std::find(_mapIndices.begin(), _mapIndices.end(), mapIndex);
	return it != _mapIndices.end();
}

const std::vector<uint32_t>& alg::MapRelation::getMapIndices() const
{
	return _mapIndices;
}

uint32_t alg::MapRelation::getMapIndexCount() const
{
	return _mapIndices.size();
}

uint32_t alg::MapRelation::getMapIndex(uint32_t index) const
{
	assert(index < _mapIndices.size());

	return _mapIndices[index];
}

int32_t alg::MapRelation::getIndex(uint32_t mapIndex) const
{
	int count = getMapIndexCount();
	for (int i = 0; i < count; i++)
	{
		if (_mapIndices[i] == mapIndex)
		{
			return i;
		}
	}
	return -1;
}


//////////////////////////////////////////////////////////////////////////

alg::Map::Map()
{

}

alg::Map::~Map()
{

}

int32_t alg::Map::addPoint(const math::Vector3& point)
{
	MapPoint* mp = _mapPoints.create();
	if (mp)
	{
		mp->setPosition(point);
		return mp->getObjectIndex();
	}
	return -1;
}

void alg::Map::removeAllPoints()
{
	_mapPoints.removeAllObjects();
}

uint32_t alg::Map::getPointCount() const
{
	return _mapPoints.getObjectCount();
}

const math::Vector3* alg::Map::getPoint(uint32_t nIndex) const
{
	auto mp = _mapPoints.getObject(nIndex);
	if (mp)
	{
		return &mp->getPosition();
	}

	return nullptr;
}

void alg::Map::removeAllRelations()
{
	_mapRelations.removeAllObjects();
}

uint32_t alg::Map::getRelationCount() const
{
	return _mapRelations.getObjectCount();
}

bool alg::Map::getRelation(uint32_t nIndex, std::vector<uint32_t>& indices) const
{
	indices.clear();

	auto mp = _mapRelations.getObject(nIndex);
	if (mp == nullptr)
	{
		return false;
	}

	indices = mp->getMapIndices();

	return indices.size() > 0;
}

