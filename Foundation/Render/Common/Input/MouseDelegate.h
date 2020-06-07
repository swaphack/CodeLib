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
}
