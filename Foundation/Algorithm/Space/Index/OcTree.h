#pragma once

#include <functional>
#include "system.h"

namespace alg
{
	namespace space
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

			// 节点
			struct TreeNode
			{
			public:
				// 限制条件
				Condtion cond;
				// 包含项
				std::map<Key, Element> items;
				// 前西北
				TreeNode* FNW = nullptr;
				// 前东北
				TreeNode* FNE = nullptr;
				// 前西南
				TreeNode* FSW = nullptr;
				// 前东南
				TreeNode* FSE = nullptr;
				// 背西北
				TreeNode* BNW = nullptr;
				// 背东北
				TreeNode* BNE = nullptr;
				// 背西南
				TreeNode* BSW = nullptr;
				// 背东南
				TreeNode* BSE = nullptr;
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
				if (addNode(node->FNW, id, item)) bAdd = true;
				if (addNode(node->FNE, id, item)) bAdd = true;
				if (addNode(node->FSW, id, item)) bAdd = true;
				if (addNode(node->FSE, id, item)) bAdd = true;
				if (addNode(node->BNW, id, item)) bAdd = true;
				if (addNode(node->BNE, id, item)) bAdd = true;
				if (addNode(node->BSW, id, item)) bAdd = true;
				if (addNode(node->BSE, id, item)) bAdd = true;
				if (bAdd)
				{
					if (node->FNW != nullptr || node->FNE != nullptr || node->FSW != nullptr || node->FSE != nullptr
						|| node->BNW != nullptr || node->BNE != nullptr || node->BSW != nullptr || node->BSE != nullptr)
					{
						if (node->items.size() > 0)
						{
							int a = 1;
						}
					}
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
					if (b.size() != 8) return false;

					node->FNW = createNode(b[0]);
					node->FNE = createNode(b[1]);
					node->FSW = createNode(b[2]);
					node->FSE = createNode(b[3]);
					node->BNW = createNode(b[4]);
					node->BNE = createNode(b[5]);
					node->BSW = createNode(b[6]);
					node->BSE = createNode(b[7]);

					auto items = node->items;
					node->items.clear();
					for (const auto& item : items)
					{
						addNode(node->FNW, item.first, item.second);
						addNode(node->FNE, item.first, item.second);
						addNode(node->FSW, item.first, item.second);
						addNode(node->FSE, item.first, item.second);
						addNode(node->BNW, item.first, item.second);
						addNode(node->BNE, item.first, item.second);
						addNode(node->BSW, item.first, item.second);
						addNode(node->BSE, item.first, item.second);
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

				removeNode(node->FNW, id);
				removeNode(node->FNE, id);
				removeNode(node->FSW, id);
				removeNode(node->FSE, id);
				removeNode(node->BNW, id);
				removeNode(node->BNE, id);
				removeNode(node->BSW, id);
				removeNode(node->BSE, id);

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

				cleanNode(node->FNW);
				cleanNode(node->FNE);
				cleanNode(node->FSW);
				cleanNode(node->FSE);

				cleanNode(node->BNW);
				cleanNode(node->BNE);
				cleanNode(node->BSW);
				cleanNode(node->BSE);

				delete node;
			}
			/**
			*	清空节点
			*/
			bool findNode(TreeNode* node, const Key& id, std::map<int, Element>& target)
			{
				if (node == nullptr) return nullptr;
				if (!isInclude(node->cond, id)) return false;

				findNode(node->FNW, id, target);
				findNode(node->FNE, id, target);
				findNode(node->FSW, id, target);
				findNode(node->FSE, id, target);
				findNode(node->BNW, id, target);
				findNode(node->BNE, id, target);
				findNode(node->BSW, id, target);
				findNode(node->BSE, id, target);

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
}