#pragma once

#include "Notify.h"
#include "system.h"

namespace render
{
	class Node;

	typedef Notify<NodeNotifyType> NodeNotify;

	class NotifyCenter
	{
	public:
		NotifyCenter();
		virtual ~NotifyCenter();
	public:
		/**
		*	分配
		*/
		NodeNotify* alloct(Node* node);
		/**
		*	释放
		*/
		void release(Node* node);
		/**
		*	派发
		*/
		void dispatch(NodeNotifyType type);
	public:
		/**
		*	添加待更新的节点
		*/
		void addDirtyNode(Node* node);
		/**
		*	更新所有待更新的节点
		*/
		void updateAllDirtyNodes();
	private:
		bool _bHandDirtyEvent = false;
		std::set<Node*> _waitDirtyNodes;
		std::set<Node*> _allDirtyNodes;
	private:
		std::map<Node*, NodeNotify*> _mapNotifies;
	};

#define G_NOTIFYCENTER sys::Instance<render::NotifyCenter>::getInstance()
}