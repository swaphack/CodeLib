#include "MeshMap.h"
#include "system.h"

alg::map::MeshMapRelation::MeshMapRelation()
{

}

alg::map::MeshMapRelation::~MeshMapRelation()
{

}

bool alg::map::MeshMapRelation::findNeighbor(uint32_t srcIndex, std::vector<uint32_t>& neighbors) const
{
	int32_t index = getRelationIndex(srcIndex);
	if (index == -1)
	{
		return false;
	}

	uint32_t count = getRelationCount();

	uint32_t preIndex = getRelation(index - 1 < 0 ? count - 1 : index - 1);
	uint32_t nexIndex = getRelation(index + 1 >= count ? 0 : index + 1);
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

bool alg::map::MeshMapRelation::findWay(uint32_t fromIndex, uint32_t toIndex, std::vector<uint32_t>& indices) const
{
	indices.clear();

	int32_t srcIndex = getRelationIndex(fromIndex);
	int32_t destIndex = getRelationIndex(toIndex);
	if (srcIndex == -1 || destIndex == -1)
	{
		return false;
	}

	uint32_t count = getRelationCount();

	if (fabs(srcIndex - destIndex) < (count / 2))
	{
		for (int i = srcIndex; i != destIndex;)
		{
			indices.push_back(getRelation(i));
			srcIndex < destIndex ? i++ : i--;
		}
		indices.push_back(toIndex);
	}
	else
	{
		for (int i = srcIndex; i != destIndex;)
		{
			indices.push_back(getRelation(i));
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



alg::map::MeshMapRelationCreate::~MeshMapRelationCreate() {}

alg::map::MapObject* alg::map::MeshMapRelationCreate::create()
{
	return new MeshMapRelation();
}

//////////////////////////////////////////////////////////////////////////
alg::map::MeshMap::MeshMap()
{
	_mapRelations.setCreateFunc(new MeshMapRelationCreate());
}

alg::map::MeshMap::~MeshMap()
{
	
}

inline void alg::map::MeshMap::addMeshRelation(int length, uint32_t start, ...)
{
	va_list ap;
	va_start(ap, start);
	int32_t relationIndex = this->addRelation(length, start, ap);
	va_end(ap);
}

bool alg::map::MeshMap::findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const
{
	std::set<uint32_t> setData;
	for (const auto& mesh : _mapRelations.getAllObjects())
	{
		MeshMapRelation* pRelation = mesh.second->as<MeshMapRelation>();
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
