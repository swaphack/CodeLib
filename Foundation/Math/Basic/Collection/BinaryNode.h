#pragma once
#include "TreeNode.h"

namespace math
{
	/**
	*	�������ڵ�
	*/
	class BinaryNode : public TreeNode
	{
	public:
		BinaryNode();
		/**
		*	���ӽڵ�
		*/
		CREATE_CLASS_VECTOR_MEMBER(BinaryNode*, LeftChild, _children, 0);
		/**
		*	�Һ��ӽڵ�
		*/
		CREATE_CLASS_VECTOR_MEMBER(BinaryNode*, RightChild, _children, 1);
	private:
	};
}