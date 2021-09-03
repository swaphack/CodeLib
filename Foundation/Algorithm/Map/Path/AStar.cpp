#include "AStar.h"
#include "Map/Base/MapProtocol.h"

alg::map::AStar::AStartNode::AStartNode(uint32_t index)
{
	_index = index;
}

alg::map::AStar::AStartNode::AStartNode()
{

}

uint32_t alg::map::AStar::AStartNode::getIndex() const
{
	return _index;
}

void alg::map::AStar::AStartNode::setParent(int32_t parent)
{
	_parent = parent;
}

int32_t alg::map::AStar::AStartNode::getParent() const
{
	return _parent;
}

void alg::map::AStar::AStartNode::setG(float value)
{
	_g = value;
}

float alg::map::AStar::AStartNode::getG() const
{
	return _g;
}

void alg::map::AStar::AStartNode::setH(float value)
{
	_h = value;
}

float alg::map::AStar::AStartNode::getH() const
{
	return _h;
}

float alg::map::AStar::AStartNode::getF() const
{
	return getG() + getH();
}

//////////////////////////////////////////////////////////////////////////

alg::map::AStar::AStar()
{

}

alg::map::AStar::~AStar()
{

}

bool alg::map::AStar::findWay(const MapProtocol* map, uint32_t srcIndex, uint32_t destIndex, std::vector<uint32_t>& path)
{
	if (map == nullptr)
	{
		return false;
	}

	if (srcIndex >= map->getCellCount() || destIndex >= map->getCellCount())
	{
		return false;
	}

	this->initNodes();

	_openSet.insert(srcIndex);

	while (!_openSet.empty())
	{
		int32_t nParentIndex = -1;
		float fLeastF = 0;
		for (auto item : _openSet)
		{
			auto node = getAStartNode(item);
			if (nParentIndex == -1 || node->getF() < fLeastF)
			{
				nParentIndex = item;
				fLeastF = node->getF();
			}
		}

		if (nParentIndex == -1)
		{
			return false;
		}

		_openSet.erase(nParentIndex);

		// 查找接壤节点
		std::vector<uint32_t> neighbors;
		if (!map->findNeighborCells(nParentIndex, neighbors))
		{
			return false;
		}

		auto parent = getAStartNode(nParentIndex);
		if (parent == nullptr)
		{
			return false;
		}
		// 填充数据到待查询的节点
		for (auto item : neighbors)
		{
			auto node = AStartNode(item);
			node.setParent(nParentIndex);
			node.setG(parent->getG() + this->getDistance(map, nParentIndex, item));
			node.setH(this->getDistance(map, item, destIndex));

			if (item == destIndex)
			{
				_mapNode[item] = node;

				return getPath(srcIndex, destIndex, path);
			}

			auto it = _openSet.find(item);
			if (it != _openSet.end())
			{
				auto data = getAStartNode(item);
				if (data->getH() < node.getF())
				{
					continue;
				}
			}

			it = _closeSet.find(item);
			if (it != _closeSet.end())
			{
				auto data = getAStartNode(item);
				if (data->getH() < node.getF())
				{
					continue;
				}
			}
			_openSet.insert(item);
			_closeSet.erase(item);

			_mapNode[item] = node;
		}

		_closeSet.insert(nParentIndex);
	}

	return false;
}

void alg::map::AStar::initNodes()
{
	_openSet.clear();
	_closeSet.clear();

	_mapNode.clear();
}

alg::map::AStar::AStartNode* alg::map::AStar::getAStartNode(uint32_t index)
{
	auto it = _mapNode.find(index);
	if (it == _mapNode.end())
	{
		AStartNode node(index);
		_mapNode[index] = node;
	}

	return &_mapNode[index];
}

bool alg::map::AStar::getPath(uint32_t srcIndex, uint32_t endIndex, std::vector<uint32_t>& path)
{
	uint32_t index = endIndex;
	do 
	{
		auto it = _mapNode.find(index);
		if (it == _mapNode.end())
		{
			return false;
		}

		path.insert(path.begin(), index);
		if (index == srcIndex)
		{
			return true;
		}

		index = it->second.getParent();
	} while (true);

	return false;
}

