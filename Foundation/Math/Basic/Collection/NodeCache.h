#pragma once

#include "Node.h"
#include <set>

namespace math
{
	/**
	*	节点缓存池
	*/
	class NodeCache
	{
	public:
		NodeCache();
		~NodeCache();
	public:
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Node, T>::value, T>::type>
		T* createNode()
		{
			T* t = new T();
			this->addNode(t);
			return t;
		}
	public:
		/**
		*	添加节点
		*/
		void addNode(Node* node);
		/**
		*	移除节点
		*/
		void removeNode(Node* node);
		/**
		*	清空
		*/
		void clear();
	private:
		/**
		*	节点缓存
		*/
		std::set<Node*> _nodes;
	};
}