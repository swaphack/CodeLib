#pragma once

#include "system.h"
#include <vector>

namespace render
{
	class Node;

	// ��������
	class TouchManager 
	{
	public:
		TouchManager();
		virtual ~TouchManager();
	public:
		// ��Ӵ�������
		void setRoot(Node* protocol);

		void onTouchBegan(const math::Vector2& touchPoint);
		void onTouchMoved(const math::Vector2& touchPoint);
		void onTouchEnded(const math::Vector2& touchPoint);
	private:
		Node* _root = nullptr;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}