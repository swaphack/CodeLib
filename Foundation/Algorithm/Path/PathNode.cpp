#include "PathNode.h"

using namespace alg;

PathNode::PathNode()
{

}

PathNode::~PathNode()
{
	this->clearAllNodes();
}

void PathNode::setTag(int tag)
{
	_tag = tag;
}

int PathNode::getTag()
{
	return _tag;
}

void PathNode::addNode(PathNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	SAFE_RETAIN(node);

	_adjacents.insert(node);
}

void PathNode::removeNode(PathNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	auto it = _adjacents.find(node);
	if (it == _adjacents.end())
	{
		return;
	}

	SAFE_RELEASE(node);
	_adjacents.erase(it);
}

void PathNode::clearAllNodes()
{
	for (auto item : _adjacents)
	{
		SAFE_RELEASE(item);
	}

	_adjacents.clear();
}

PathNode* PathNode::findNodeByTag(int tag)
{
	for (auto item : _adjacents)
	{
		if (item->getTag() == tag)
		{
			return item;
		}
	}

	return nullptr;
}

PathNode* PathNode::findNodeWithRecurseByTag(int tag)
{
	for (auto item : _adjacents)
	{
		if (item->getTag() == tag)
		{
			return item;
		}
		else
		{
			auto ret = item->findNodeWithRecurseByTag(tag);
			if (ret)
			{
				return ret;
			}
		}
	}

	return nullptr;
}
