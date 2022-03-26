#pragma once

#include <functional>
#include "system.h"

namespace alg
{
	/**
	*	���ݶ�����Ҷ�ӽڵ���
	*/
	template<typename Condtion, typename Key, typename Element>
	class OcTree
	{
	public:
		typedef std::function<bool(const Condtion& a, const Key& b)> CondtionIncludeFunc;
		typedef std::function<bool(const Condtion& a, std::vector<Condtion>& b)> CondtionDivideFunc;

#define QUAD_TREE_NODE_COUNT 8

		// �ڵ�
		struct TreeNode
		{
		public:
			// ��������
			Condtion cond;
			// ������
			std::map<Key, Element> items;
			// �ӽڵ�
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
		*	Ҷ�ӽڵ��ϵ���Ʒ����
		*/
		int getLeafItemCount() const
		{
			return _leafItemCount;
		}
		/**
		*	Ҷ�ӽڵ��ϵ���Ʒ����
		*/
		void setLeafItemCount(int count)
		{
			_leafItemCount = count;
		}
		/**
		*	������������
		*/
		void setCondtionIncludeFunc(const CondtionIncludeFunc& func)
		{
			_condtionIncludeFunc = func;
		}
		/**
		*	�������Ѻ���
		*/
		void setCondtionDivideFunc(const CondtionDivideFunc& func)
		{
			_condtionDivideFunc = func;
		}
	public:
		/**
		*	��ʼ��
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
		*	���
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
		*	�Ƴ�
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
		*	����
		*/
		bool findNode(const Key& id, std::map<Key, Element>& target)
		{
			return findNode(_root, id, target);
		}
		/**
		*	���
		*/
		void clear()
		{
			cleanNode(_root);
			_root = nullptr;
		}
	protected:
		/**
		*	�����ڵ�
		*/
		TreeNode* createNode(const Condtion& cond)
		{
			auto node = new TreeNode();
			node->cond = cond;
			return node;
		}
		/**
		*	��ӽڵ�
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
				{// �����ٷָ�
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
		*	�Ƴ��ڵ�, �Ƿ��Ƴ���ǰ�ڵ�
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
		*	��սڵ�
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
		*	��սڵ�
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
		*	����
		*/
		bool isInclude(const Condtion& a, const Key& b)
		{
			if (_condtionIncludeFunc != nullptr)
				return _condtionIncludeFunc(a, b);
			return false;
		}
		/**
		*	����
		*/
		bool getDivideItems(const Condtion& a, std::vector<Condtion>& b)
		{
			if (_condtionDivideFunc != nullptr)
				return _condtionDivideFunc(a, b);
			return false;
		}
	private:
		// ���ڵ�
		TreeNode* _root = nullptr;
		// ��������
		CondtionIncludeFunc _condtionIncludeFunc = nullptr;
		// ���Ѻ���
		CondtionDivideFunc _condtionDivideFunc = nullptr;
		// Ҷ�ӽڵ����Ʒ��������
		int _leafItemCount = 4;
	};
}