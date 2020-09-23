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

alg::map::RayMap::RayMap()
{

}

alg::map::RayMap::~RayMap()
{
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

