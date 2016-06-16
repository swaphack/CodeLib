#pragma once

#include "system.h"

namespace render
{
	typedef void(*KEYBOARD_DELEGATE_HANDLER)(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);

	#define KEYBOARD_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_DELEGATE_HANDLER>(&HANDLER_SEL)

	// 触摸委托
	struct KeyBoardDelegate
	{
		sys::Object* target;
		KEYBOARD_DELEGATE_HANDLER handler;

		KeyBoardDelegate() :target(nullptr), handler(nullptr){}

		void hand(sys::BoardKey key, sys::ButtonStatus type)
		{
			if (!empty())
				(*handler)(target, key, type);
		}

		bool empty()
		{
			return handler == nullptr;
		}

		bool isEquals(sys::Object* t, KEYBOARD_DELEGATE_HANDLER h)
		{
			return target == t && handler == h;
		}

		void clean()
		{
			target = nullptr;
			handler = nullptr;
		}
	};

	class KeyboardManager
	{
	public:
		KeyboardManager();
		~KeyboardManager();
	public:
		// 添加按键派发对象
		void addDispatcher(sys::Object* node, KEYBOARD_DELEGATE_HANDLER handler);
		// 移除按键派发对象
		void removeDispatcher(sys::Object* node);
		// 移除所有按键派发对象
		void removeAllDispatchers();
		// 派发接受到的按钮事件
		void onDispatcher(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// 键盘事件委托集
		std::vector<KeyBoardDelegate*> _keyboardDispatchers;
	};


	#define G_KEYBOARDMANAGER sys::Instance<KeyboardManager>::getInstance()
}