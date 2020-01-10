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
	for (auto item : _nodes)
	{
		delete item;
	}
	_nodes.clear();
}
