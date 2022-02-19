#pragma once

#include <functional>
#include "system.h"

namespace alg
{
	namespace space
	{
		template<typename T>
		class BinaryTree
		{
		public:
			typedef std::function<int(const T& a, const T& b)> CompareFunc;

			// 节点
			struct TreeNode
			{
				T data;
				TreeNode* left = nullptr;
				TreeNode* right = nullptr;
			};
		public:
			BinaryTree()
			{

			}
			BinaryTree(const CompareFunc& func)
			{
				_compareFunc = func;
			}
			~BinaryTree()
			{
				this->clear();
			}
		public:
			/**
			*	比较函数
			*/
			void setIncludeFunc(const CompareFunc& func)
			{
				_compareFunc = func;
			}
		public:
			/**
			*	添加
			*/
			void add(const T& data)
			{
				if (_root == nullptr)
				{
					_root = createNode(data);
				}
				else
				{
					addNode(_root, data);
				}
			}
			/**
			*	移除
			*/
			void remove(const T& data)
			{
				if (_root == nullptr) return;
				if (removeNode(_root, data))
				{
					_root = nullptr;
				}
			}
			/**
			*	包含
			*/
			bool contains(const T& data)
			{
				return findNode(_root, data) != nullptr;
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
			TreeNode* createNode(const T& data)
			{
				auto node = new TreeNode();
				node->data = data;
				return node;
			}
			/**
			*	添加节点
			*/
			void addNode(TreeNode*& node, const T& data)
			{
				if (node == nullptr) return;

				if (isLessThan(node->data, data))
				{
					if (node->left == nullptr)
					{
						node->left = createNode(data);
					}
					else
					{
						addNode(node->left, data);
					}
				}
				else
				{
					if (node->Right == nullptr)
					{
						node->Right = createNode(data);
					}
					else
					{
						addNode(node->Right, data);
					}
				}
			}
			/**
			*	移除节点, 是否移除当前节点
			*/
			bool removeNode(TreeNode*& node, const T& data)
			{
				if (node == nullptr) return false;
				if (isEqual(node->data, data))
				{
					this->cleanNode(node);
					return true;
				}
				if (removeNode(node->left, data))
				{
					node->left = nullptr;
					return true;
				}
				if (removeNode(node->right, data))
				{
					node->right = nullptr;
					return true;
				}

				return false;
			}
			/**
			*	清空节点
			*/
			void cleanNode(TreeNode*& node)
			{
				if (node == nullptr) return;
				cleanNode(node->left);
				cleanNode(node->right);
				delete node;
			}
			/**
			*	清空节点
			*/
			TreeNode* findNode(TreeNode* node, const T& data)
			{
				if (node == nullptr) return nullptr;
				if (isEqual(node->data, data)) return node;
				if (node->left != nullptr)
				{
					if (findNode(node->left, data))
					{
						return node->left;
					}
				}
				if (node->right != nullptr)
				{
					if (findNode(node->right, data))
					{
						return node->right;
					}
				}
				return nullptr;
			}
		protected:
			/**
			*	小于
			*/
			bool isLessThan(const T& a, const T& b)
			{
				if (_compareFunc != nullptr)
					return _compareFunc(a, b) == -1;
				return false;
			}
			/**
			*	等于
			*/
			bool isEqual(const T& a, const T& b)
			{
				if (_compareFunc != nullptr)
					return _compareFunc(a, b) == 0;
				return false;
			}
			/**
			*	大于
			*/
			bool isMoreThan(const T& a, const T& b)
			{
				if (_compareFunc != nullptr)
					return _compareFunc(a, b) == 1;
				return false;
			}
		private:
			// 根节点
			TreeNode* _root = nullptr;
			// 比较函数
			CompareFunc _compareFunc = nullptr;
		};
	}
}