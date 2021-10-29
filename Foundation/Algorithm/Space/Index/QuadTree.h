#pragma once

#include <functional>
#include "system.h"

namespace alg
{
	/**
	*	���ݶ�����Ҷ�ӽڵ���
	*/
	template<typename Condtion, typename Key, typename Element>
	class QuadTree
	{
	public:
		typedef std::function<bool(const Condtion& a, const Key& b)> CondtionIncludeFunc;
		typedef std::function<bool(const Condtion& a, std::vector<Condtion>& b)> CondtionDivideFunc;

		// �ڵ�
		struct TreeNode
		{
		public:
			// ��������
			Condtion cond;
			// ������
			std::map<Key, Element> items;
			// ����
			TreeNode* NW = nullptr;
			// ����
			TreeNode* NE = nullptr;
			// ����
			TreeNode* SW = nullptr;
			// ����
			TreeNode* SE = nullptr;
		};
	public:
		QuadTree()
		{

		}
		~QuadTree()
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
		bool addNode(TreeNode* & node, const Key& id, const Element& item)
		{
			if (node == nullptr) return false;

			if (!isInclude(node->cond, id)) return false;
			bool bAdd = false;
			if (addNode(node->NW, id, item)) bAdd = true;
			if (addNode(node->NE, id, item)) bAdd = true;
			if (addNode(node->SW, id, item)) bAdd = true;
			if (addNode(node->SE, id, item)) bAdd = true;
			if (bAdd)
			{
				if (node->NW != nullptr || node->NE != nullptr || node->SW != nullptr || node->SE != nullptr)
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
				{// �����ٷָ�
					return true;
				}
				if (b.size() != 4) return false;

				node->NW = createNode(b[0]);
				node->NE = createNode(b[1]);
				node->SW = createNode(b[2]);
				node->SE = createNode(b[3]);

				auto items = node->items;
				node->items.clear();
				for (const auto& item : items)
				{
					addNode(node->NW, item.first, item.second);
					addNode(node->NE, item.first, item.second);
					addNode(node->SW, item.first, item.second);
					addNode(node->SE, item.first, item.second);
				}
			}

			return true;
		}
		/**
		*	�Ƴ��ڵ�, �Ƿ��Ƴ���ǰ�ڵ�
		*/
		bool removeNode(TreeNode* & node, const Key& id)
		{
			if (node == nullptr) return false;
			if (!isInclude(node->cond, id))
			{
				return false;
			}

			removeNode(node->NW, id);
			removeNode(node->NE, id);
			removeNode(node->SW, id);
			removeNode(node->SE, id);

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
		void cleanNode(TreeNode* & node)
		{
			if (node == nullptr) return;

			cleanNode(node->NW);
			cleanNode(node->NE);
			cleanNode(node->SW);
			cleanNode(node->SE);

			delete node;
		}
		/**
		*	��սڵ�
		*/
		bool findNode(TreeNode* node, const Key& id, std::map<int, Element>& target)
		{
			if (node == nullptr) return nullptr;
			if (!isInclude(node->cond, id)) return false;

			findNode(node->NW, id, target);
			findNode(node->NE, id, target);
			findNode(node->SW, id, target);
			findNode(node->SE, id, target);

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