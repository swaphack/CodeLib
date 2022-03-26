#include "Map.h"

alg::map::MapCellCreate::~MapCellCreate() 
{
}

alg::map::MapObject* alg::map::MapCellCreate::create()
{
	return new MapCell();
}

alg::map::MapRelationCreate::~MapRelationCreate() 
{
}

alg::map::MapObject* alg::map::MapRelationCreate::create()
{
	return new MapRelation();
}

alg::map::Map::Map()
{
	_mapCell.setCreateFunc(new MapCellCreate());
	_mapRelations.setCreateFunc(new MapRelationCreate());
}

alg::map::Map::~Map() {}


alg::map::MapCell* alg::map::Map::createCell()
{
	return (MapCell*)_mapCell.create();
}

void alg::map::Map::removeAllCells()
{
	_mapCell.removeAllObjects();
}

uint32_t alg::map::Map::getCellCount() const
{
	return _mapCell.getObjectCount();
}

const alg::map::MapCell* alg::map::Map::getCell(uint32_t nIndex) const
{
	return (MapCell*)_mapCell.getObject(nIndex);
}

alg::map::MapCell* alg::map::Map::getCell(uint32_t nIndex)
{
	return (MapCell*)_mapCell.getObject(nIndex);
}

alg::map::MapRelation* alg::map::Map::createRelation()
{
	return (MapRelation*)_mapRelations.create();

}

int32_t alg::map::Map::addRelation(uint32_t length, uint32_t start, ...)
{
	MapRelation* mr = createRelation();
	if (mr)
	{
		va_list ap;
		va_start(ap, start);
		mr->addRelation(length, start, ap);
		va_end(ap);
		return mr->getMapObjectID();
	}
	return -1;
}

int32_t alg::map::Map::addRelation(uint32_t length, uint32_t start, va_list ap)
{
	MapRelation* mr = createRelation();
	if (mr)
	{
		mr->addRelation(length, start, ap);
		return mr->getMapObjectID();
	}
	return -1;
}

int32_t alg::map::Map::addRelation(uint32_t length, uint32_t index[])
{
	MapRelation* mr = createRelation();
	if (mr)
	{
		mr->addRelation(length, index);
		return mr->getMapObjectID();
	}
	return -1;
}

int32_t alg::map::Map::addRelation(const std::vector<uint32_t>& relation)
{
	MapRelation* mr = createRelation();
	if (mr)
	{
		mr->addRelation(relation);
		return mr->getMapObjectID();
	}
	return -1;
}

void alg::map::Map::removeAllRelations()
{
	_mapRelations.removeAllObjects();
}

uint32_t alg::map::Map::getRelationCount() const
{
	return _mapRelations.getObjectCount();
}

alg::map::MapRelation* alg::map::Map::getRelation(uint32_t nIndex) const
{
	return (MapRelation*)_mapRelations.getObject(nIndex);
}

bool alg::map::Map::getRelation(uint32_t nIndex, std::vector<uint32_t>& indices) const
{
	auto mp = getRelation(nIndex);
	if (mp == nullptr)
	{
		return false;
	}

	indices = mp->getAllRelations();

	return indices.size() > 0;
}
