#pragma once

#include "Node.h"
#include <set>

namespace math
{
	/**
	*	图的节点
	*/
	class GraphNode : public Node
	{
	public:
		/**
		*	添加连接节点
		*/
		void addLink(GraphNode* node);
		/**
		*	移除连接节点并清除
		*/
		void removeLink(GraphNode* node);
		/**
		*	移除连接节点
		*/
		void removeLinkWithCleanup(GraphNode* node, bool cleanup);
		/**
		*	移除所有连接节点
		*/
		void removeAllLinks();
		/**
		*	移除所有连接节点并清除
		*/
		void removeAllLinksWithCleanup(bool cleanup);
		/**
		*	获取子节点个数
		*/
		int getLinksCount() const;
		/**
		*	获取所有子节点
		*/
		const std::set<GraphNode*>& getAllLinkNodes() const;
	public:
		/**
		*	根据名字查找节点
		*/
		GraphNode* findLinkNodeByName(const std::string name, bool recursive = false);
		/**
		*	根据标签查找节点
		*/
		GraphNode* findLinkNodeByTag(int32_t tag, bool recursive = false);
		/**
		*	根据标签查找节点
		*/
		bool contains(GraphNode* node, bool recursive = false);
	protected:
		/**
		*	根据名字查找节点
		*/
		GraphNode* _findLinkNodeByNameWithRecursive(const std::string name, std::set<GraphNode*>& filter);
		/**
		*	根据标签查找节点
		*/
		GraphNode* _findLinkNodeByTagWithRecursive(int32_t tag, std::set<GraphNode*>& filter);
		/**
		*	根据标签查找节点
		*/
		bool _containsWithRecursive(GraphNode* node, std::set<GraphNode*>& filter);
	protected:
		/**
		*	子节点
		*/
		std::set<GraphNode*> _linkNodes;
	};
}