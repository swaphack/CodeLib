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
		*	����
		*/
		NodeNotify* alloct(Node* node);
		/**
		*	�ͷ�
		*/
		void release(Node* node);
		/**
		*	�ɷ�
		*/
		void dispatch(NodeNotifyType type);
	public:
		/**
		*	��Ӵ����µĽڵ�
		*/
		void addDirtyNode(Node* node);
		/**
		*	�������д����µĽڵ�
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