#pragma once

#include "system.h"
#include <map>
#include <functional>

namespace render
{
	class Node;

	typedef void(sys::Object::*MOUSE_SCROLL_DELEGATE_HANDLER)(Node* object, sys::ScrollEvent evt, float param);

	#define MOUSE_SCROLL_DELEGATE_SELECTOR(HANDLER_SEL) static_cast<MOUSE_SCROLL_DELEGATE_HANDLER>(&HANDLER_SEL)

	typedef std::pair<Node*, MOUSE_SCROLL_DELEGATE_HANDLER> MouseScrollDelegate;

	typedef std::function<void(Node* object, sys::ScrollEvent evt, float param)> MouseScrollFunc;


	typedef void(sys::Object::* MOUSE_BUTTON_DELEGATE_HANDLER)(Node* object, sys::MouseKey key, sys::ButtonStatus status, float x, float y);

	#define MOUSE_BUTTON_DELEGATE_SELECTOR(HANDLER_SEL) static_cast<MOUSE_BUTTON_DELEGATE_HANDLER>(&HANDLER_SEL)

	typedef std::pair<Node*, MOUSE_BUTTON_DELEGATE_HANDLER> MouseButtonDelegate;

	typedef std::function<void(Node* object, sys::MouseKey key, sys::ButtonStatus status, float x, float y)> MouseButtonFunc;
}
