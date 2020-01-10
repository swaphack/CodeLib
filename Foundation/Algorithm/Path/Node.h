#pragma once

#include <list>
#include <set>

namespace alg
{
	/**
	*	路径点
	*/
	struct Node
	{
	public:
		/**
		*	相邻点
		*/
		std::list<Node*> adjacents;
	public:
		Node();
		virtual ~Node();
	public:
		/**
		*	添加相邻点
		*/
		void addAdjacent(Node* node);
		/**
		*	移除相邻点
		*/
		void removeAdjancent(Node* node);
		/**
		*	清空相邻点
		*/
		void clearAdjancents();
	};
}