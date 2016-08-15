#pragma once

#include "macros.h"

namespace sys
{
	// ���̰�ť�¼�
	typedef void (Object::*KEYBOARD_BUTTON_HANDLER)(BoardKey key, ButtonStatus status);

	#define KEYBOARD_BUTTON_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_BUTTON_HANDLER>(&HANDLER_SEL)

	typedef std::pair<Object*, KEYBOARD_BUTTON_HANDLER> KeyBoardButtonEvent;

	// ��갴ť�¼�
	typedef void (Object::*MOUSE_BUTTON_HANDLER)(MouseKey Key, ButtonStatus type, float x, float y);
	// �������¼�
	typedef void (Object::*MOUSE_SCROLL_HANDLER)(ScrollEvent type, float param);
	// ��껬��
	typedef void (Object::*MOUSE_MOVE_HANDLER)(float x, float y);

	#define MOUSE_BUTTON_SELECTOR(HANDLER_SEL) static_cast<MOUSE_BUTTON_HANDLER>(&HANDLER_SEL)
	#define MOUSE_SCROLL_SELECTOR(HANDLER_SEL) static_cast<MOUSE_SCROLL_HANDLER>(&HANDLER_SEL)
	#define MOUSE_MOVE_SELECTOR(HANDLER_SEL) static_cast<MOUSE_MOVE_HANDLER>(&HANDLER_SEL)

	typedef std::pair<Object*, MOUSE_BUTTON_HANDLER> MouseButtonEvent;

	typedef std::pair<Object*, MOUSE_SCROLL_HANDLER> MouseScrollEvent;

	typedef std::pair<Object*, MOUSE_MOVE_HANDLER> MouseMoveEvent;
}