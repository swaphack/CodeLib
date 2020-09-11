#include "RayMap.h"

alg::RayRelation::RayRelation()
{

}

alg::RayRelation::~RayRelation()
{

}

bool alg::RayRelation::findNeighbor(std::vector<uint32_t>& neighbors) const
{
	neighbors = _mapIndices;

	return neighbors.size() > 0;
}

bool alg::RayRelation::findWay(uint32_t toIndex) const
{
	return getIndex(toIndex) >= 0;
}
//////////////////////////////////////////////////////////////////////////

alg::RayMap::RayMap()
{

}

alg::RayMap::~RayMap()
{

}

void alg::RayMap::addRayRelation(uint32_t centerIndex, uint32_t nLength, uint32_t start, ...)
{
	va_list ap;
	va_start(ap, start);
	int32_t relationIndex = this->addRelation<RayRelation>(nLength, start, ap);
	va_end(ap);
	if (relationIndex < 0)
	{
		return;
	}

	_centerRayRelation[centerIndex] = relationIndex;
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

	auto rayRelation = pRelation->as<RayRelation>();
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

		this->findNeighborPoint(item, neighboors);
	}

	return true;
}

