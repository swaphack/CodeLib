#pragma once

#include "system.h"
#include "MouseDelegate.h"

namespace render
{
	class Node;
	class MouseManager
	{
	public:
		MouseManager();
		~MouseManager();
	public:
		// 添加鼠标滚轮滑动派发对象
		void addMouseScrollDelegate(sys::Object* target, Node* node, MOUSE_SCROLL_DELEGATE_HANDLER handler);
		// 移除鼠标滚轮滑动派发对象
		void removeMouseScrollDelegate(sys::Object* target, Node* node);
		// 移除所有鼠标滚轮滑动派发对象
		void removeAllMouseScrollDelegates();
	public:
		// 添加鼠标滚轮滑动派发对象
		void addMouseScrollFunc(sys::Object* target, Node* node, MouseScrollFunc func);
		// 移除鼠标滚轮滑动派发对象
		void removeMouseScrollFunc(sys::Object* target, Node* node);
		// 移除所有鼠标滚轮滑动派发对象
		void removeAllMouseScrollFuncs();
	public:
		// 派发接受到的按钮事件
		void onDispatcher(sys::ScrollEvent evt, float param);
	private:
		// 键盘事件委托集
		std::map<sys::Object*, std::map<Node*, MOUSE_SCROLL_DELEGATE_HANDLER>> _mouseScrollDelegates;
		// 键盘事件委托集
		std::map< sys::Object*, std::map<Node*, MouseScrollFunc>> _mouseScrollFuncs;
	};


#define G_MOUSEMANAGER sys::Instance<MouseManager>::getInstance()
}