#include "NodeCache.h"

using namespace math;

NodeCache::NodeCache()
{

}

NodeCache::~NodeCache()
{
	this->clear();
}

void NodeCache::addNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	_nodes.insert(node);
}

void NodeCache::removeNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	_nodes.erase(node);
}

void NodeCache::clear()
{
	for (auto it = _nodes.begin(); it != _nodes.end(); )
	{
		auto pItem = *it;
		it++;
		delete pItem;
	}
	_nodes.clear();
}
