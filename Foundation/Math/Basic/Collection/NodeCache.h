#pragma once

#include "Node.h"
#include <set>

namespace math
{
	/**
	*	�ڵ㻺���
	*/
	class NodeCache
	{
	public:
		NodeCache();
		~NodeCache();
	public:
		/**
		*	�����ڵ�
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
		*	��ӽڵ�
		*/
		void addNode(Node* node);
		/**
		*	�Ƴ��ڵ�
		*/
		void removeNode(Node* node);
		/**
		*	���
		*/
		void clear();
	private:
		/**
		*	�ڵ㻺��
		*/
		std::set<Node*> _nodes;
	};
}