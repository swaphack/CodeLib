#pragma once

#include <list>
#include <set>
#include "system.h"

namespace alg
{
	/**
	*	路径点
	*/
	class PathNode : public sys::Object
	{
	public:
		PathNode();
		virtual ~PathNode();
	public:
		/**
		*	设置标记
		*/
		void setTag(int tag);
		/**
		*	获取标记
		*/
		int getTag() const;
		/**
		*	添加相邻点
		*/
		void addNode(PathNode* node);
		/**
		*	移除相邻点
		*/
		void removeNode(PathNode* node);
		/**
		*	清空相邻点
		*/
		void clearAllNodes();
		/**
		*	查找节点
		*/
		PathNode* findNodeByTag(int tag);
		/**
		*	查找节点
		*/
		PathNode* findNodeWithRecurseByTag(int tag);
	private:
		// 相邻点
		std::set<PathNode*> _adjacents;
		// 标记
		int _tag = 0;
	};
}