#pragma once

#include <functional>
#include "system.h"

namespace alg
{
	namespace space
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

			// �ڵ�
			struct TreeNode
			{
			public:
				// ��������
				Condtion cond;
				// ������
				std::map<Key, Element> items;
				// ǰ����
				TreeNode* FNW = nullptr;
				// ǰ����
				TreeNode* FNE = nullptr;
				// ǰ����
				TreeNode* FSW = nullptr;
				// ǰ����
				TreeNode* FSE = nullptr;
				// ������
				TreeNode* BNW = nullptr;
				// ������
				TreeNode* BNE = nullptr;
				// ������
				TreeNode* BSW = nullptr;
				// ������
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
					{// �����ٷָ�
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
			*	�Ƴ��ڵ�, �Ƿ��Ƴ���ǰ�ڵ�
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
			*	��սڵ�
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
			*	��սڵ�
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
}