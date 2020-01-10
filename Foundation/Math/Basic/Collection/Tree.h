#pragma once

#include "Basic/base.h"
#include "TreeNode.h"
#include "NodeCache.h"

namespace math
{
	/**
	*	��
	*/
	class Tree 
	{
	public:
		Tree();
		virtual ~Tree();
	public:
		/**
		*	���ø��ڵ�
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(TreeNode*, Root, nullptr);
	public:
		/**
		*	�����ڵ�
		*/
		TreeNode* createNode();
	public:
	private:
		/**
		*	�ڵ㻺���
		*/
		NodeCache _nodeCache;
	};
}