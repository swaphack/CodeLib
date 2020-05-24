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
		void removeKeyboardDelegate(sys::Object* target);
		// 移除所有按键派发对象
		void removeAllKeyboardDelegates();
		// 添加按键派发对象
		void addKeyboardFunc(Node* node, KeyboardFunc func);
		// 移除按键派发对象
		void removeKeyboardFunc(Node* node);
		// 移除所有按键派发对象
		void removeAllKeyboardFuncs();
		// 派发接受到的按钮事件
		void onDispatcher(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// 键盘事件委托集
		std::map<sys::Object*, KeyboardDelegate> _keyboardDelegates;
		// 键盘事件委托集
		std::map<Node*, KeyboardFunc> _keyboardFuncs;
	};


	#define G_KEYBOARDMANAGER sys::Instance<KeyboardManager>::getInstance()
}