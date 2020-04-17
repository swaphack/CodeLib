#pragma once

#include <list>
#include <set>
#include "system.h"

namespace alg
{
	/**
	*	·����
	*/
	class PathNode : public sys::Object
	{
	public:
		PathNode();
		virtual ~PathNode();
	public:
		/**
		*	���ñ��
		*/
		void setTag(int tag);
		/**
		*	��ȡ���
		*/
		int getTag() const;
		/**
		*	������ڵ�
		*/
		void addNode(PathNode* node);
		/**
		*	�Ƴ����ڵ�
		*/
		void removeNode(PathNode* node);
		/**
		*	������ڵ�
		*/
		void clearAllNodes();
		/**
		*	���ҽڵ�
		*/
		PathNode* findNodeByTag(int tag);
		/**
		*	���ҽڵ�
		*/
		PathNode* findNodeWithRecurseByTag(int tag);
	private:
		// ���ڵ�
		std::set<PathNode*> _adjacents;
		// ���
		int _tag = 0;
	};
}