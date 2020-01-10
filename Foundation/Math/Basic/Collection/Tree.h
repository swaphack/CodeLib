#pragma once

#include "Basic/base.h"
#include "TreeNode.h"
#include "NodeCache.h"

namespace math
{
	/**
	*	树
	*/
	class Tree 
	{
	public:
		Tree();
		virtual ~Tree();
	public:
		/**
		*	设置根节点
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(TreeNode*, Root, nullptr);
	public:
		/**
		*	创建节点
		*/
		TreeNode* createNode();
	public:
	private:
		/**
		*	节点缓存池
		*/
		NodeCache _nodeCache;
	};
}