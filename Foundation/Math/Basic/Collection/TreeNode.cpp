#include "TreeNode.h"
#include <cassert>

using namespace math;

TreeNode::TreeNode()
{

}

TreeNode::~TreeNode()
{

}

void TreeNode::addChild(TreeNode* child)
{
	if (child == nullptr)
	{
		return;
	}

	if (child->getParent() != nullptr)
	{
		int a = 1;
	}

	assert(child->getParent() == nullptr);
	assert(this->indexOf(child) == -1);

	child->setParent(this);
	_children.push_back(child);
}

void TreeNode::addChildren(const std::vector<TreeNode*>& children)
{
	for (auto item : children)
	{
		this->addChild(item);
	}
}

void TreeNode::setChildren(const std::vector<TreeNode*>& children)
{
	this->removeAllChildren();
	for (auto item : children)
	{
		this->addChild(item);
	}
}

void TreeNode::removeChild(TreeNode* child)
{
	this->removeChild(child, true);
}

void TreeNode::removeChild(TreeNode* child, bool cleanup)
{
	if (child == nullptr)
	{
		return;
	}

	int index = indexOf(child);
	if (index == -1)
	{
		return;
	}

	this->removeChildAt(index, cleanup);
}

void TreeNode::removeAllChildren()
{
	this->removeAllChildren(true);
}

void TreeNode::removeAllChildren(bool cleanup)
{
	int nCount = getChildrenCount();
	for (int i = nCount - 1; i >= 0; i--)
	{
		this->removeChildAt(i, cleanup);
	}
}

int TreeNode::getChildrenCount() const
{
	return _children.size();
}

const std::vector<TreeNode*>& TreeNode::getAllChildren() const
{
	return _children;
}

int TreeNode::indexOf(TreeNode* child) const
{
	if (child == nullptr)
	{
		return -1;
	}

	if (child->getParent() != this)
	{
		return -1;
	}

	int nCount = getChildrenCount();
	for (int i = 0; i < nCount; i++)
	{
		if (_children[i] == child)
		{
			return i;
		}
	}

	return -1;
}

void TreeNode::removeChildAt(int index)
{
	this->removeChildAt(index, true);
}

void TreeNode::removeChildAt(int index, bool cleanup)
{
	if (index >= 0 && index < getChildrenCount())
	{
		auto child = _children[index];
		if (child)
		{
			child->setParent(nullptr);
			if (cleanup)
			{
				child->removeAllChildren();
			}
		}
		_children.erase(_children.begin() + index);
	}
}

TreeNode* TreeNode::getChildAt(int index) const
{
	if (index >= 0 && index < getChildrenCount())
	{
		return _children[index];
	}

	return nullptr;
}

TreeNode* TreeNode::getHead() const
{
	return getChildAt(0);
}

TreeNode* TreeNode::getTail() const
{
	return getChildAt(getChildrenCount() - 1);
}

TreeNode* TreeNode::findChildByName(const std::string name, bool recursive)
{
	for (auto item : _children)
	{
		if (item->getName() == name)
		{
			return item;
		}
		if (recursive)
		{
			return item->findChildByName(name, recursive);
		}
	}

	return nullptr;
}

TreeNode* TreeNode::findChildByTag(int32_t tag, bool recursive)
{
	for (auto item : _children)
	{
		if (item->getTag() == tag)
		{
			return item;
		}
		if (recursive)
		{
			return item->findChildByTag(tag, recursive);
		}
	}

	return nullptr;
}

bool TreeNode::contains(TreeNode* node, bool recursive)
{
	for (auto item : _children)
	{
		if (item == node)
		{
			return true;
		}
		if (recursive)
		{
			return item->contains(node, recursive);
		}
	}

	return false;
}

std::vector<TreeNode*> TreeNode::getAllLeafChildren()
{
	std::vector<TreeNode*> vecLeaf;

	for (auto item : _children)
	{
		if (item->getChildrenCount() == 0)
		{
			vecLeaf.push_back(item);
		}
		else
		{
			auto ret = item->getAllLeafChildren();
			if (ret.size() > 0)
			{
				vecLeaf.insert(vecLeaf.end(), ret.begin(), ret.end());
			}
		}
	}
	return vecLeaf;
}


