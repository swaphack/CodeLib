#include "AStar.h"
#include "Map/Map.h"

alg::AStar::AStar()
{

}

alg::AStar::~AStar()
{

}

bool alg::AStar::findWay(const Map* map, uint32_t srcIndex, uint32_t destIndex)
{
	if (map == nullptr)
	{
		return false;
	}

	if (srcIndex >= map->getPointCount() || destIndex >= map->getPointCount())
	{
		return false;
	}

	this->initNodes(map);

	if (!findNeareastNode(map, srcIndex, destIndex))
	{
		return false;
	}

	return true;
}

void alg::AStar::initNodes(const Map* map)
{
	if (map == nullptr)
	{
		return;
	}

	_waitCheckNode.clear();
	_checkedNode.clear();

	_pathNode = std::stack<uint32_t>();
	_pathDistance = std::stack<float>();
}

bool alg::AStar::findNeareastNode(const Map* map, uint32_t srcIndex, uint32_t destIndex)
{
	if (map == nullptr)
	{
		return false;
	}

	_waitCheckNode.insert(srcIndex);

	this->pushCurrent(map, srcIndex, destIndex);

	// �ҵ�Ŀ��
	if (srcIndex == destIndex)
	{
		return true;
	}

	// ���ҽ����ڵ�
	std::vector<uint32_t> neighbors;
	if (!map->findNeighborPoint(srcIndex, neighbors))
	{
		this->popCurrent(srcIndex);

		return false;
	}

	// �����Ѳ��ҹ��ĵ�
	std::vector<uint32_t> uncheckNeighbors;
	for (auto item : neighbors)
	{
		auto it = _checkedNode.find(item);
		if (it != _checkedNode.end())
		{
			continue;
		}
		uncheckNeighbors.push_back(item);
	}

	// ����û�иı�
	if (uncheckNeighbors.size() == 0)
	{
		this->popCurrent(srcIndex);

		return false;
	}

	// ������ݵ�����ѯ�Ľڵ�
	for (auto item : uncheckNeighbors)
	{
		_waitCheckNode.insert(item);
	}

	// ��ѯ���·����
	int32_t nShortestIndex = -1;
	float fTempDistance = -1;
	for (auto item : _waitCheckNode)
	{
		float fDistance = this->getDistance(map, item, destIndex);
		if (fDistance < 0)
		{// ·����ͨ
			continue;
		}
		if (nShortestIndex == -1 || fDistance < fTempDistance)
		{
			nShortestIndex = item;
			fTempDistance = fDistance;
		}
	}

	if (nShortestIndex == -1)
	{
		this->popCurrent(srcIndex);
		return false;
	}

	return this->findNeareastNode(map, nShortestIndex, destIndex);
}

void alg::AStar::pushCurrent(const Map* map, uint32_t srcIndex, uint32_t destIndex)
{
	if (map == nullptr)
	{
		return;
	}
	// �������
	if (_pathNode.size() > 0)
	{
		uint32_t nLastIndex = _pathNode.top();

		float fDistance = this->getDistance(map, nLastIndex, srcIndex);
		float fLastDistance = _pathDistance.top();

		_pathDistance.push(fDistance + fLastDistance);
	}
	else
	{
		_pathNode.push(srcIndex);
		_pathDistance.push(0);
	}
}

void alg::AStar::popCurrent(uint32_t srcIndex)
{
	float fDistance = _pathDistance.top();
	_pathDistance.pop();

	_waitCheckNode.erase(srcIndex);
	_checkedNode.insert(srcIndex);

	_pathNode.pop();
}

