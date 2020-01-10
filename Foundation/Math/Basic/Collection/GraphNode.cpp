#include "GraphNode.h"

using namespace math;

void GraphNode::addLink(GraphNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	_linkNodes.insert(node);
}

void GraphNode::removeLink(GraphNode* node)
{
	this->removeLinkWithCleanup(node, true);
}

void GraphNode::removeLinkWithCleanup(GraphNode* node, bool cleanup)
{
	if (node == nullptr)
	{
		return;
	}
	if (cleanup)
	{
		node->removeAllLinks();
	}

	_linkNodes.erase(node);
}

void GraphNode::removeAllLinks()
{
	this->removeAllLinksWithCleanup(true);
}

void GraphNode::removeAllLinksWithCleanup(bool cleanup)
{
	if (cleanup)
	{
		for (auto item : _linkNodes)
		{
			item->removeAllLinks();
		}
	}
	_linkNodes.clear();
}

int GraphNode::getLinksCount() const
{
	return _linkNodes.size();
}

const std::set<GraphNode*>& GraphNode::getAllLinkNodes() const
{
	return _linkNodes;
}

GraphNode* GraphNode::findLinkNodeByName(const std::string name, bool recursive /*= false*/)
{
	if (this->getName() == name)
	{
		return this;
	}
	std::set<GraphNode*> filter;
	filter.insert(this);
	return this->_findLinkNodeByNameWithRecursive(name, filter);
}

GraphNode* GraphNode::findLinkNodeByTag(int32_t tag, bool recursive /*= false*/)
{
	if (this->getTag() == tag)
	{
		return this;
	}
	std::set<GraphNode*> filter;
	filter.insert(this);
	return this->_findLinkNodeByTagWithRecursive(tag, filter);
}

bool GraphNode::contains(GraphNode* node, bool recursive /*= false*/)
{
	if (this == node)
	{
		return true;
	}
	std::set<GraphNode*> filter;
	filter.insert(this);
	return this->_containsWithRecursive(node, filter);
}

GraphNode* GraphNode::_findLinkNodeByNameWithRecursive(const std::string name, std::set<GraphNode*>& filter)
{
	if (filter.find(this) == filter.end())
	{
		return nullptr;
	}
	for (auto item : _linkNodes)
	{
		if (item->getName() == name)
		{
			return item;
		}

		filter.insert(item);
		auto ret = item->_findLinkNodeByNameWithRecursive(name, filter);
		if (ret != nullptr)
		{
			return ret;
		}
	}

	return nullptr;
}

GraphNode* GraphNode::_findLinkNodeByTagWithRecursive(int32_t tag, std::set<GraphNode*>& filter)
{
	if (filter.find(this) == filter.end())
	{
		return nullptr;
	}

	for (auto item : _linkNodes)
	{
		if (item->getTag() == tag)
		{
			return item;
		}

		filter.insert(item);
		auto ret = item->_findLinkNodeByTagWithRecursive(tag, filter);
		if (ret != nullptr)
		{
			return ret;
		}
	}

	return nullptr;
}

bool GraphNode::_containsWithRecursive(GraphNode* node, std::set<GraphNode*>& filter)
{
	if (filter.find(this) == filter.end())
	{
		return nullptr;
	}

	for (auto item : _linkNodes)
	{
		if (item == node)
		{
			return true;
		}
		filter.insert(item);
		auto ret = item->_containsWithRecursive(node, filter);
		if (ret != false)
		{
			return ret;
		}
	}

	return nullptr;
}
