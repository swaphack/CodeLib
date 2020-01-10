#pragma once

#include "GraphNode.h"
#include "NodeCache.h"

namespace math
{
	/**
	*	图节点
	*/
	class Graph
	{
	public:
		Graph();
		virtual ~Graph();
	public:
		/**
		*	创建节点
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<GraphNode, T>::value, T>::type>
		T* createNode()
		{
			return _nodeCache.createNode<T>();
		}
	public:
		/**
		*	添加关联
		*/
		void createLink(GraphNode* src, GraphNode* dest);
		/**
		*	移除关联
		*/
		void breakLink(GraphNode* src, GraphNode* dest);
	public:
		/**
		*	有向方向
		*/
		virtual bool isDirected();
		/**
		*	环结构
		*/
		virtual bool isCycle();
		/**
		*	多重边
		*/
		virtual bool isMultipleEdges();
	private:
		/**
		*	节点缓存池
		*/
		NodeCache _nodeCache;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	简单图，不包含自身
	*/
	class SimpleGraph : public Graph
	{
	public:
		/**
		*	有向方向
		*/
		virtual bool isDirected();
		/**
		*	环结构
		*/
		virtual bool isCycle();
	};


	//////////////////////////////////////////////////////////////////////////
	/**
	*	有向图
	*/
	class DirectedGraph : public Graph
	{
	public:
		/**
		*	有向方向
		*/
		virtual bool isDirected();
		/**
		*	环结构
		*/
		virtual bool isCycle();
	};
}