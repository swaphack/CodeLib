#include "Map.h"

#include "MapNode.h"

alg::Map::Map()
{

}

alg::Map::~Map()
{
	this->removeAllNodes();
}

void alg::Map::addNode(const math::Vector2& point)
{
	MapNode* node = new MapNode(point);
	SAFE_RETAIN(node);
	std::string name = getCString("%s", node->getPosition().toString());
	_nodes[name] = node;
}

void alg::Map::addNode(const math::Vector3& point)
{
	MapNode* node = new MapNode(point);
	SAFE_RETAIN(node);
	std::string name = getCString("%s", node->getPosition().toString());
	_nodes[name] = node;
}

const math::Vector3* alg::Map::getNode(const std::string& name)
{
	auto it = _nodes.find(name);
	if (it == _nodes.end())
	{
		return nullptr;
	}

	return &it->second;
}

const math::Vector3* alg::Map::getNode(const math::Vector3& point)
{
	std::string name = getCString("%s", point.toString());
	return getNode(name);
}

const math::Vector3* alg::Map::getNode(const math::Vector2& point)
{
	return this->getNode(math::Vector3(point));
}

void alg::Map::removeAllNodes()
{
	for (auto& item : _nodes)
	{
		SAFE_RELEASE(item.second);
	}

	_nodes.clear();
}