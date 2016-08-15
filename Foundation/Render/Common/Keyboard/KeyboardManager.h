#pragma once

#include "system.h"

namespace render
{
	typedef void(sys::Object::*KEYBOARD_DELEGATE_HANDLER)(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);

	#define KEYBOARD_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_DELEGATE_HANDLER>(&HANDLER_SEL)

	class KeyboardManager
	{
	public:
		KeyboardManager();
		~KeyboardManager();
	public:
		// 添加按键派发对象
		void addDispatcher(sys::Object* node, sys::Object* target, KEYBOARD_DELEGATE_HANDLER handler);
		// 移除按键派发对象
		void removeDispatcher(sys::Object* target);
		// 移除所有按键派发对象
		void removeAllDispatchers();
		// 派发接受到的按钮事件
		void onDispatcher(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// 回调对象，回调接口，回调传入参数
		typedef sys::Tuple3<sys::Object*, KEYBOARD_DELEGATE_HANDLER, sys::Object*> KeyBoardDelegate;
		// 键盘事件委托集
		std::vector<KeyBoardDelegate> _keyboardDispatchers;
	};


	#define G_KEYBOARDMANAGER sys::Instance<KeyboardManager>::getInstance()
}