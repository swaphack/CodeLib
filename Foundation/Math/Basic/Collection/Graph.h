#pragma once

#include "GraphNode.h"
#include "NodeCache.h"

namespace math
{
	/**
	*	ͼ�ڵ�
	*/
	class Graph
	{
	public:
		Graph();
		virtual ~Graph();
	public:
		/**
		*	�����ڵ�
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<GraphNode, T>::value, T>::type>
		T* createNode()
		{
			return _nodeCache.createNode<T>();
		}
	public:
		/**
		*	��ӹ���
		*/
		void createLink(GraphNode* src, GraphNode* dest);
		/**
		*	�Ƴ�����
		*/
		void breakLink(GraphNode* src, GraphNode* dest);
	public:
		/**
		*	������
		*/
		virtual bool isDirected();
		/**
		*	���ṹ
		*/
		virtual bool isCycle();
		/**
		*	���ر�
		*/
		virtual bool isMultipleEdges();
	private:
		/**
		*	�ڵ㻺���
		*/
		NodeCache _nodeCache;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	��ͼ������������
	*/
	class SimpleGraph : public Graph
	{
	public:
		/**
		*	������
		*/
		virtual bool isDirected();
		/**
		*	���ṹ
		*/
		virtual bool isCycle();
	};


	//////////////////////////////////////////////////////////////////////////
	/**
	*	����ͼ
	*/
	class DirectedGraph : public Graph
	{
	public:
		/**
		*	������
		*/
		virtual bool isDirected();
		/**
		*	���ṹ
		*/
		virtual bool isCycle();
	};
}