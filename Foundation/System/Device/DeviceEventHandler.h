#pragma once

#include "macros.h"

namespace sys
{
	// 键盘按钮事件
	typedef void (Object::*KEYBOARD_BUTTON_HANDLER)(BoardKey key, ButtonStatus status);

	#define KEYBOARD_BUTTON_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_BUTTON_HANDLER>(&HANDLER_SEL)

	struct KeyBoardButtonEvent
	{
		Object* target;
		KEYBOARD_BUTTON_HANDLER handler;

		KeyBoardButtonEvent()
			:target(nullptr)
			, handler(nullptr)
		{}

		void hand(BoardKey key, ButtonStatus status)
		{
			if (target && handler)
			{
				(target->*handler)(key, status);
			}
		}
	};

	// 鼠标按钮事件
	typedef void (Object::*MOUSE_BUTTON_HANDLER)(MouseKey Key, ButtonStatus type, float x, float y);
	// 鼠标滚轮事件
	typedef void (Object::*MOUSE_SCROLL_HANDLER)(ScrollEvent type, float param);
	// 鼠标滑动
	typedef void (Object::*MOUSE_MOVE_HANDLER)(float x, float y);

	#define MOUSE_BUTTON_SELECTOR(HANDLER_SEL) static_cast<MOUSE_BUTTON_HANDLER>(&HANDLER_SEL)
	#define MOUSE_SCROLL_SELECTOR(HANDLER_SEL) static_cast<MOUSE_SCROLL_HANDLER>(&HANDLER_SEL)
	#define MOUSE_MOVE_SELECTOR(HANDLER_SEL) static_cast<MOUSE_MOVE_HANDLER>(&HANDLER_SEL)

	struct MouseButtonEvent
	{
		Object* target;
		MOUSE_BUTTON_HANDLER handler;

		MouseButtonEvent()
			:target(nullptr)
			, handler(nullptr)
		{

		}

		void hand(MouseKey key, ButtonStatus type, float x, float y)
		{
			if (target && handler)
			{
				(target->*handler)(key, type, x, y);
			}
		}
	};

	struct MouseScrollEvent
	{
		Object* target;
		MOUSE_SCROLL_HANDLER handler;

		MouseScrollEvent()
			:target(nullptr)
			, handler(nullptr)
		{

		}

		void hand(ScrollEvent type, float param)
		{
			if (target && handler)
			{
				(target->*handler)(type, param);
			}
		}
	};

	struct MouseMoveEvent
	{
		Object* target;
		MOUSE_MOVE_HANDLER handler;

		MouseMoveEvent()
			:target(nullptr)
			, handler(nullptr)
		{

		}

		void hand(float x, float y)
		{
			if (target && handler)
			{
				(target->*handler)(x, y);
			}
		}
	};
}