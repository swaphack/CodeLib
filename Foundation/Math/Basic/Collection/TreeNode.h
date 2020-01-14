#pragma once

#include "Node.h"
#include <vector>
#include <set>

namespace math
{
	/**
	*	节点
	*/
	class TreeNode : public Node
	{
	public:
		TreeNode();
		virtual ~TreeNode();
	public:
		/**
		*	父节点
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(TreeNode*, Parent, nullptr);
	public:
		/** 
		*	添加子节点	
		*/
		void addChild(TreeNode* child);
		/**
		*	移除子节点
		*/
		void removeChild(TreeNode* child);
		/**
		*	移除子节点
		*/
		void removeChild(TreeNode* child, bool cleanup);
		/**
		*	移除所有子节点并清除
		*/
		void removeAllChildren();
		/**
		*	移除所有子节点
		*/
		void removeAllChildren(bool cleanup);
		/**
		*	获取子节点个数
		*/
		int getChildrenCount() const;
		/**
		*	获取所有子节点
		*/
		const std::vector<TreeNode*>& getAllChildren() const;
		/**
		*	节点所在的顺序
		*/
		int indexOf(TreeNode* child) const;
		/**
		*	移除指定位置的节点并清除
		*/
		void removeChildAt(int index);
		/**
		*	移除指定位置的节点
		*/
		void removeChildAt(int index, bool cleanup);
		/**
		*	按顺序查找结点
		*/
		TreeNode* getChildAt(int index) const;
		/**
		*	最前面的节点
		*/
		TreeNode* getHead() const;
		/**
		*	最后边面的节点
		*/
		TreeNode* getTail() const;
	public:
		/**
		*	根据名字查找节点
		*/
		TreeNode* findChildByName(const std::string name, bool recursive = false);
		/**
		*	根据标签查找节点
		*/
		TreeNode* findChildByTag(int32_t tag, bool recursive = false);
		/**
		*	根据标签查找节点
		*/
		bool contains(TreeNode* node, bool recursive = false);
	public:
		/**
		*	获取所有叶子节点
		*/
		std::vector<TreeNode*> getAllLeafChildren();
	protected:
		/**
		*	子节点
		*/
		std::vector<TreeNode*> _children;
	};

}