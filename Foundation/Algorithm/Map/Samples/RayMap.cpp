#include "RayMap.h"

alg::map::RayMapRelation::RayMapRelation()
{

}

alg::map::RayMapRelation::~RayMapRelation()
{

}

bool alg::map::RayMapRelation::findNeighbor(std::vector<uint32_t>& neighbors) const
{
	neighbors = _relations;

	return neighbors.size() > 0;
}

bool alg::map::RayMapRelation::findWay(uint32_t toIndex) const
{
	return getRelationIndex(toIndex) >= 0;
}

//////////////////////////////////////////////////////////////////////////
alg::map::RayMapRelationCreate::~RayMapRelationCreate()
{
}

alg::map::MapObject* alg::map::RayMapRelationCreate::create()
{
	return new RayMapRelation();
}
//////////////////////////////////////////////////////////////////////////

alg::map::RayMap::RayMap()
{

}

alg::map::RayMap::~RayMap()
{
}


void alg::map::RayMap::addRayRelation(uint32_t center, int length, uint32_t start, ...)
{
	va_list ap;
	va_start(ap, start);
	int32_t relationIndex = this->addRelation(length, start, ap);
	va_end(ap);
	if (relationIndex < 0) return;
	_centerRayRelation[center] = relationIndex;
}

void alg::map::RayMap::addRayRelation(uint32_t Center, const std::vector<uint32_t>& relation)
{
	int32_t relationIndex = this->addRelation(relation);
	if (relationIndex < 0)
	{
		return;
	}
	_centerRayRelation[Center] = relationIndex;
}

bool alg::map::RayMap::findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const
{
	auto it = _centerRayRelation.find(srcIndex);
	if (it == _centerRayRelation.end())
	{
		return false;
	}

	MapRelation* pRelation = (MapRelation*)_mapRelations.getObject(it->second);
	if (pRelation == nullptr)
	{
		return false;
	}

	auto rayRelation = pRelation->as<RayMapRelation>();
	if (rayRelation == nullptr)
	{
		return false;
	}

	if (!rayRelation->findNeighbor(neighboors))
	{
		return false;
	}

	return neighboors.size() > 0;
}
