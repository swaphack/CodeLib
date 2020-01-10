#pragma once
#include "TreeNode.h"

namespace math
{
	/**
	*	列表节点
	*/
	class ListNode : public TreeNode
	{
	public:
		ListNode();
		/**
		*	子节点
		*/
		CREATE_CLASS_VECTOR_MEMBER(ListNode*, Child, _children, 0);
	private:
	};
}