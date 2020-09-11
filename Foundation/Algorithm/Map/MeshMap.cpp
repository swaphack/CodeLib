#include "MeshMap.h"
#include "system.h"

alg::MeshRelation::MeshRelation()
{

}

alg::MeshRelation::~MeshRelation()
{

}

bool alg::MeshRelation::findNeighbor(uint32_t srcIndex, std::vector<uint32_t>& neighbors) const
{
	neighbors.clear();

	int32_t index = getIndex(srcIndex);
	if (index == -1)
	{
		return false;
	}

	uint32_t count = getMapIndexCount();

	uint32_t preIndex = getMapIndex(index - 1 < 0 ? count - 1 : index - 1);
	uint32_t nexIndex = getMapIndex(index + 1 > count ? 0 : index + 1);
	if (preIndex != srcIndex)
	{
		neighbors.push_back(preIndex);
	}
	if (nexIndex != srcIndex)
	{
		neighbors.push_back(nexIndex);
	}

	return neighbors.size() > 0;
}

bool alg::MeshRelation::findWay(uint32_t fromIndex, uint32_t toIndex, std::vector<uint32_t>& indices) const
{
	indices.clear();

	int32_t srcIndex = getIndex(fromIndex);
	int32_t destIndex = getIndex(toIndex);
	if (srcIndex == -1 || destIndex == -1)
	{
		return false;
	}

	uint32_t count = getMapIndexCount();

	if (fabs(srcIndex - destIndex) < (count / 2))
	{
		for (int i = srcIndex; i != destIndex;)
		{
			indices.push_back(getMapIndex(i));
			srcIndex < destIndex ? i++ : i--;
		}
		indices.push_back(toIndex);
	}
	else
	{
		for (int i = srcIndex; i != destIndex;)
		{
			indices.push_back(getMapIndex(i));
			srcIndex < destIndex ? i-- : i++;
			if (i == -1)
			{
				i = count - 1;
			}
		}
		indices.push_back(toIndex);
	}

	return indices.size() > 0;
}

//////////////////////////////////////////////////////////////////////////
alg::MeshMap::MeshMap()
{

}

alg::MeshMap::~MeshMap()
{
	
}

bool alg::MeshMap::findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const
{
	neighboors.clear();

	std::set<uint32_t> setData;
	for (const auto& mesh : _mapRelations.getAllObjects())
	{
		MeshRelation* pRelation = mesh.second->as<MeshRelation>();
		std::vector<uint32_t> vecData;
		if (pRelation->findNeighbor(srcIndex, vecData))
		{
			for (auto item : vecData)
			{
				setData.insert(item);
			}
		}
	}

	for (const auto& item : setData)
	{
		neighboors.push_back(item);
	}

	return true;
}
