#pragma once
#include "TreeNode.h"

namespace math
{
	/**
	*	二叉树节点
	*/
	class BinaryNode : public TreeNode
	{
	public:
		BinaryNode();
		/**
		*	左孩子节点
		*/
		CREATE_CLASS_VECTOR_MEMBER(BinaryNode*, LeftChild, _children, 0);
		/**
		*	右孩子节点
		*/
		CREATE_CLASS_VECTOR_MEMBER(BinaryNode*, RightChild, _children, 1);
	private:
	};
}