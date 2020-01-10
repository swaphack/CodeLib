#pragma once

#include "Node.h"
#include <set>

namespace math
{
	/**
	*	ͼ�Ľڵ�
	*/
	class GraphNode : public Node
	{
	public:
		/**
		*	������ӽڵ�
		*/
		void addLink(GraphNode* node);
		/**
		*	�Ƴ����ӽڵ㲢���
		*/
		void removeLink(GraphNode* node);
		/**
		*	�Ƴ����ӽڵ�
		*/
		void removeLinkWithCleanup(GraphNode* node, bool cleanup);
		/**
		*	�Ƴ��������ӽڵ�
		*/
		void removeAllLinks();
		/**
		*	�Ƴ��������ӽڵ㲢���
		*/
		void removeAllLinksWithCleanup(bool cleanup);
		/**
		*	��ȡ�ӽڵ����
		*/
		int getLinksCount() const;
		/**
		*	��ȡ�����ӽڵ�
		*/
		const std::set<GraphNode*>& getAllLinkNodes() const;
	public:
		/**
		*	�������ֲ��ҽڵ�
		*/
		GraphNode* findLinkNodeByName(const std::string name, bool recursive = false);
		/**
		*	���ݱ�ǩ���ҽڵ�
		*/
		GraphNode* findLinkNodeByTag(int32_t tag, bool recursive = false);
		/**
		*	���ݱ�ǩ���ҽڵ�
		*/
		bool contains(GraphNode* node, bool recursive = false);
	protected:
		/**
		*	�������ֲ��ҽڵ�
		*/
		GraphNode* _findLinkNodeByNameWithRecursive(const std::string name, std::set<GraphNode*>& filter);
		/**
		*	���ݱ�ǩ���ҽڵ�
		*/
		GraphNode* _findLinkNodeByTagWithRecursive(int32_t tag, std::set<GraphNode*>& filter);
		/**
		*	���ݱ�ǩ���ҽڵ�
		*/
		bool _containsWithRecursive(GraphNode* node, std::set<GraphNode*>& filter);
	protected:
		/**
		*	�ӽڵ�
		*/
		std::set<GraphNode*> _linkNodes;
	};
}