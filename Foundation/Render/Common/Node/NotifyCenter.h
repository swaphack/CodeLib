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
		NodeNotify* alloct(Node* node);

		void release(Node* node);

		void dispatch(NodeNotifyType type);
	private:
		std::map<Node*, NodeNotify*> _mapNotifies;
	};

#define G_NOTIFYCENTER sys::Instance<render::NotifyCenter>::getInstance()
}