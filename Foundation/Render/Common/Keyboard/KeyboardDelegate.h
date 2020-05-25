#pragma once

#include "system.h"
#include <map>
#include <functional>

namespace render
{
	class Node;

	typedef void(sys::Object::* KEYBOARD_DELEGATE_HANDLER)(Node* object, sys::BoardKey key, sys::ButtonStatus type);

	#define KEYBOARD_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_DELEGATE_HANDLER>(&HANDLER_SEL)

	typedef std::pair<Node*, KEYBOARD_DELEGATE_HANDLER> KeyboardDelegate;

	typedef std::function<void(Node* object, sys::BoardKey key, sys::ButtonStatus type)> KeyboardFunc;
}