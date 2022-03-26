#pragma once

#include <functional>
#include "system.h"

namespace alg
{
	/**
	*	数据都存在叶子节点上
	*/
	template<typename Condtion, typename Key, typename Element>
	class OcTree
	{
	public:
		typedef std::function<bool(const Condtion& a, const Key& b)> CondtionIncludeFunc;
		typedef std::function<bool(const Condtion& a, std::vector<Condtion>& b)> CondtionDivideFunc;

#define QUAD_TREE_NODE_COUNT 8

		// 节点
		struct TreeNode
		{
		public:
			// 限制条件
			Condtion cond;
			// 包含项
			std::map<Key, Element> items;
			// 子节点
			TreeNode* Children[QUAD_TREE_NODE_COUNT] = nullptr;
		};
	public:
		OcTree()
		{

		}
		~OcTree()
		{
			this->clear();
		}
	public:
		/**
		*	叶子节点上的物品个数
		*/
		int getLeafItemCount() const
		{
			return _leafItemCount;
		}
		/**
		*	叶子节点上的物品个数
		*/
		void setLeafItemCount(int count)
		{
			_leafItemCount = count;
		}
		/**
		*	条件包含函数
		*/
		void setCondtionIncludeFunc(const CondtionIncludeFunc& func)
		{
			_condtionIncludeFunc = func;
		}
		/**
		*	条件分裂函数
		*/
		void setCondtionDivideFunc(const CondtionDivideFunc& func)
		{
			_condtionDivideFunc = func;
		}
	public:
		/**
		*	初始化
		*/
		void initRoot(const Condtion& cond)
		{
			if (_root != nullptr)
			{
				cleanNode(_root);
				_root = nullptr;
			}
			else
			{
				_root = createNode(cond);
			}
		}
		/**
		*	添加
		*/
		void add(const Key& id, const Element& item)
		{
			if (_root == nullptr)
			{
				return;
			}

			addNode(_root, id, item);
		}
		/**
		*	移除
		*/
		void remove(const Key& id)
		{
			if (_root == nullptr) return;
			if (removeNode(_root, id))
			{
				_root = nullptr;
			}
		}
		/**
		*	查找
		*/
		bool findNode(const Key& id, std::map<Key, Element>& target)
		{
			return findNode(_root, id, target);
		}
		/**
		*	清空
		*/
		void clear()
		{
			cleanNode(_root);
			_root = nullptr;
		}
	protected:
		/**
		*	创建节点
		*/
		TreeNode* createNode(const Condtion& cond)
		{
			auto node = new TreeNode();
			node->cond = cond;
			return node;
		}
		/**
		*	添加节点
		*/
		bool addNode(TreeNode*& node, const Key& id, const Element& item)
		{
			if (node == nullptr) return false;

			if (!isInclude(node->cond, id)) return false;
			bool bAdd = false;
			for (int i = 0; i < QUAD_TREE_NODE_COUNT; i++)
			{
				if (addNode(node->Children, id, item)) bAdd = true;
			}
			if (bAdd)
			{
				return true;
			}

			node->items[id] = item;
			if (node->items.size() > getLeafItemCount())
			{
				std::vector<Condtion> b;
				if (!getDivideItems(node->cond, b))
				{// 不可再分割
					return true;
				}
				if (b.size() != QUAD_TREE_NODE_COUNT) return false;

				for (int i = 0; i < QUAD_TREE_NODE_COUNT; i++)
				{
					node->Children[i] = createNode(b[i]);
				}

				auto items = node->items;
				node->items.clear();
				for (const auto& item : items)
				{
					for (int i = 0; i < QUAD_TREE_NODE_COUNT; i++)
					{
						addNode(node->Children, item.first, item.second);
					}
				}
			}

			return true;
		}
		/**
		*	移除节点, 是否移除当前节点
		*/
		bool removeNode(TreeNode*& node, const Key& id)
		{
			if (node == nullptr) return false;
			if (!isInclude(node->cond, id))
			{
				return false;
			}

			for (int i = 0; i < QUAD_TREE_NODE_COUNT; i++)
			{
				removeNode(node->Children, id);
			}

			if (node->items.size() == 0)
			{
				return false;
			}

			auto it = node->items.find(id);
			if (it != node->items.end())
			{
				node->items.erase(id);
			}

			return false;
		}
		/**
		*	清空节点
		*/
		void cleanNode(TreeNode*& node)
		{
			if (node == nullptr) return;

			for (int i = 0; i < QUAD_TREE_NODE_COUNT; i++)
			{
				cleanNode(node->Children[i]);
			}

			delete node;
		}
		/**
		*	清空节点
		*/
		bool findNode(TreeNode* node, const Key& id, std::map<int, Element>& target)
		{
			if (node == nullptr) return nullptr;
			if (!isInclude(node->cond, id)) return false;

			for (int i = 0; i < QUAD_TREE_NODE_COUNT; i++)
			{
				findNode(node->Children[i], id, target);
			}

			if (node->items.size() != 0)
			{
				for (const auto& data : node->items)
				{
					target[data.first] = data.second;
				}
			}

			return target.size() > 0;
		}
	protected:
		/**
		*	包含
		*/
		bool isInclude(const Condtion& a, const Key& b)
		{
			if (_condtionIncludeFunc != nullptr)
				return _condtionIncludeFunc(a, b);
			return false;
		}
		/**
		*	分裂
		*/
		bool getDivideItems(const Condtion& a, std::vector<Condtion>& b)
		{
			if (_condtionDivideFunc != nullptr)
				return _condtionDivideFunc(a, b);
			return false;
		}
	private:
		// 根节点
		TreeNode* _root = nullptr;
		// 包含函数
		CondtionIncludeFunc _condtionIncludeFunc = nullptr;
		// 分裂函数
		CondtionDivideFunc _condtionDivideFunc = nullptr;
		// 叶子节点的物品数量限制
		int _leafItemCount = 4;
	};
}