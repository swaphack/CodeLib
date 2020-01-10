#pragma once

#include <list>
#include <set>

namespace alg
{
	/**
	*	·����
	*/
	struct Node
	{
	public:
		/**
		*	���ڵ�
		*/
		std::list<Node*> adjacents;
	public:
		Node();
		virtual ~Node();
	public:
		/**
		*	������ڵ�
		*/
		void addAdjacent(Node* node);
		/**
		*	�Ƴ����ڵ�
		*/
		void removeAdjancent(Node* node);
		/**
		*	������ڵ�
		*/
		void clearAdjancents();
	};
}