#include "Tree.h"

using namespace math;

Tree::Tree()
{
}

Tree::~Tree()
{
	if (getRoot())
	{
		getRoot()->removeAllChildren();
		setRoot(nullptr);
	}
}

TreeNode* Tree::createNode()
{
	return _nodeCache.createNode<TreeNode>();
}

