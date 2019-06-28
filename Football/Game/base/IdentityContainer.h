#pragma once

#include "Identity.h"
#include <map>
#include <functional>

namespace game
{
	/**
	*	id容器
	*	管理id的释放
	*/
	class IdentityContainer
	{
	private:
		struct IdentityNode
		{
			Identity* value = nullptr;
			IdentityNode* leftChild = nullptr;
			IdentityNode* rightChild = nullptr;
			/**
			*	相等
			*/
			bool equals(uint64_t id);
			/**
			*	大于
			*/
			bool moreThan(uint64_t id);
			/**
			*	小于
			*/
			bool lessThan(uint64_t id);

			IdentityNode(Identity* value);

			~IdentityNode();
		};
	public:
		IdentityContainer();
		virtual ~IdentityContainer();
	public:
		/*
		*	添加项
		*/
		void add(Identity* ptrIdentity);
		/*
		*	移除项
		*/
		void remove(uint64_t id);
		/*
		*	查找项
		*/
		Identity* find(uint64_t id);
		/*
		*	清空
		*/
		void clear();
		/*
		*	数量
		*/
		uint64_t count();
		/*
		*	遍历
		*/
		void foreach(const std::function<void(Identity*)>& func);
	protected:
		/*
		*	遍历
		*/
		void foreach(IdentityNode* pNode, const std::function<void(IdentityNode*)>& func);
	private:
		// 根节点 二叉树
		IdentityNode* m_pRoot = nullptr;
		uint64_t m_nCount = 0;
	};
}