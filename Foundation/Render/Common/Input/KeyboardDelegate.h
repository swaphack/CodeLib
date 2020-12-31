#pragma once

#include "system.h"
#include <map>
#include <functional>

namespace render
{
	class Node;
}

typedef void(sys::Object::* KEYBOARD_DELEGATE_HANDLER)(render::Node* node, sys::BoardKey key, sys::ButtonStatus status);

#define KEYBOARD_DELEGATE_SELECTOR(HANDLER_SEL) static_cast<KEYBOARD_DELEGATE_HANDLER>(&HANDLER_SEL)

typedef std::pair<render::Node*, KEYBOARD_DELEGATE_HANDLER> KeyboardDelegate;

typedef std::function<void(sys::BoardKey key, sys::ButtonStatus status)> KeyboardFunc;