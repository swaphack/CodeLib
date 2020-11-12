#pragma once

#include "system.h"
#include "KeyboardDelegate.h"

namespace render
{
	class Node;
	class KeyboardManager
	{
	public:
		KeyboardManager();
		~KeyboardManager();
	public:
		// 添加按键派发对象
		void addKeyboardDelegate(sys::Object* target, Node* node, KEYBOARD_DELEGATE_HANDLER handler);
		// 移除按键派发对象
		void removeKeyboardDelegate(sys::Object* target, Node* node);
		// 移除所有按键派发对象
		void removeAllKeyboardDelegates();
	public:
		// 添加按键派发对象
		void addKeyboardFunc(sys::Object* target, Node* node, KeyboardFunc func);
		// 移除按键派发对象
		void removeKeyboardFunc(sys::Object* target, Node* node);
		// 移除所有按键派发对象
		void removeAllKeyboardFuncs();
	public:
		// 移除对象事件
		void removeTargetAllEvents(sys::Object* target);
	public:
		// 派发接收到的按钮事件
		void onDispatchButtonEvent(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// 键盘事件委托集
		std::map<sys::Object*, std::map<Node*, KEYBOARD_DELEGATE_HANDLER>> _keyboardDelegates;
		// 键盘事件委托集
		std::map< sys::Object*, std::map<Node*, KeyboardFunc>> _keyboardFuncs;
	};


	#define G_KEYBOARDMANAGER sys::Instance<render::KeyboardManager>::getInstance()
}