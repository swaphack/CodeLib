#pragma once

#include "Node.h"
#include <vector>
#include <set>

namespace math
{
	/**
	*	�ڵ�
	*/
	class TreeNode : public Node
	{
	public:
		TreeNode();
		virtual ~TreeNode();
	public:
		/**
		*	���ڵ�
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(TreeNode*, Parent, nullptr);
	public:
		/** 
		*	����ӽڵ�	
		*/
		void addChild(TreeNode* child);
		/**
		*	�Ƴ��ӽڵ�
		*/
		void removeChild(TreeNode* child);
		/**
		*	�Ƴ��ӽڵ�
		*/
		void removeChild(TreeNode* child, bool cleanup);
		/**
		*	�Ƴ������ӽڵ㲢���
		*/
		void removeAllChildren();
		/**
		*	�Ƴ������ӽڵ�
		*/
		void removeAllChildren(bool cleanup);
		/**
		*	��ȡ�ӽڵ����
		*/
		int getChildrenCount() const;
		/**
		*	��ȡ�����ӽڵ�
		*/
		const std::vector<TreeNode*>& getAllChildren() const;
		/**
		*	�ڵ����ڵ�˳��
		*/
		int indexOf(TreeNode* child) const;
		/**
		*	�Ƴ�ָ��λ�õĽڵ㲢���
		*/
		void removeChildAt(int index);
		/**
		*	�Ƴ�ָ��λ�õĽڵ�
		*/
		void removeChildAt(int index, bool cleanup);
		/**
		*	��˳����ҽ��
		*/
		TreeNode* getChildAt(int index) const;
		/**
		*	��ǰ��Ľڵ�
		*/
		TreeNode* getHead() const;
		/**
		*	������Ľڵ�
		*/
		TreeNode* getTail() const;
	public:
		/**
		*	�������ֲ��ҽڵ�
		*/
		TreeNode* findChildByName(const std::string name, bool recursive = false);
		/**
		*	���ݱ�ǩ���ҽڵ�
		*/
		TreeNode* findChildByTag(int32_t tag, bool recursive = false);
		/**
		*	���ݱ�ǩ���ҽڵ�
		*/
		bool contains(TreeNode* node, bool recursive = false);
	public:
		/**
		*	��ȡ����Ҷ�ӽڵ�
		*/
		std::vector<TreeNode*> getAllLeafChildren();
	protected:
		/**
		*	�ӽڵ�
		*/
		std::vector<TreeNode*> _children;
	};

}