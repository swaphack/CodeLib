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
		// 派发接收到的按钮事件
		void onDispatchScrolleEvent(sys::ScrollEvent evt, float param);
	public:
		// 添加按键派发对象
		void addMouseButtonDelegate(sys::Object* target, Node* node, MOUSE_BUTTON_DELEGATE_HANDLER handler);
		// 移除按键派发对象
		void removeMouseButtonDelegate(sys::Object* target, Node* node);
		// 移除所有按键派发对象
		void removeAllMouseButtonDelegates();
	public:
		// 添加按键派发对象
		void addMouseButtonFunc(sys::Object* target, Node* node, MouseButtonFunc func);
		// 移除按键派发对象
		void removeMouseButtonFunc(sys::Object* target, Node* node);
		// 移除所有按键派发对象
		void removeAllMouseButtonFuncs();
	public:
		// 移除对象事件
		void removeTargetAllEvents(sys::Object* target);
	public:
		// 派发接收到的按钮事件
		void onDispatchButtonEvent(sys::MouseKey key, sys::ButtonStatus status, float x, float y);
	private:
		// 鼠标滚轮事件委托集
		std::map<sys::Object*, std::map<Node*, MOUSE_SCROLL_DELEGATE_HANDLER>> _mouseScrollDelegates;
		// 鼠标滚轮事件委托集
		std::map< sys::Object*, std::map<Node*, MouseScrollFunc>> _mouseScrollFuncs;
	private:
		// 键盘事件委托集
		std::map<sys::Object*, std::map<Node*, MOUSE_BUTTON_DELEGATE_HANDLER>> _mouseButtonDelegates;
		// 键盘事件委托集
		std::map< sys::Object*, std::map<Node*, MouseButtonFunc>> _mouseButtonFuncs;

	};


#define G_MOUSEMANAGER sys::Instance<MouseManager>::getInstance()
}