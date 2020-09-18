#include "RayMap.h"

alg::RayMapRelation::RayMapRelation()
{

}

alg::RayMapRelation::~RayMapRelation()
{

}

bool alg::RayMapRelation::findNeighbor(std::vector<uint32_t>& neighbors) const
{
	neighbors = _relations;

	return neighbors.size() > 0;
}

bool alg::RayMapRelation::findWay(uint32_t toIndex) const
{
	return getRelationIndex(toIndex) >= 0;
}
//////////////////////////////////////////////////////////////////////////

alg::RayMap::RayMap()
{

}

alg::RayMap::~RayMap()
{
}

bool alg::RayMap::findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const
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

	std::vector<uint32_t> vecIndex;
	if (!rayRelation->findNeighbor(vecIndex))
	{
		return false;
	}
	
	for (auto item : vecIndex)
	{
		neighboors.push_back(item);
	}

	return neighboors.size() > 0;
}

