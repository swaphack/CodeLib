#pragma once
#include "TreeNode.h"

namespace math
{
	/**
	*	�б�ڵ�
	*/
	class ListNode : public TreeNode
	{
	public:
		ListNode();
		/**
		*	�ӽڵ�
		*/
		CREATE_CLASS_VECTOR_MEMBER(ListNode*, Child, _children, 0);
	private:
	};
}