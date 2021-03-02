#pragma once


#include "system.h"
#include <functional>

namespace render
{
	class Node;

	// ��������
	enum class TouchType
	{
		NONE,		// δ����
		BEGAN,		// ����	
		MOVED,		// ��ס����
		ENDED,		// ����
		CANCELED,	// ȡ��
	};

	typedef void (sys::Object::*TOUCH_DELEGATE_HANDLER)(render::Node* node, const math::Vector2& touchPoint);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// ����ί��
	typedef std::pair<sys::Object*, TOUCH_DELEGATE_HANDLER> TouchDelegate;

	// ����������
	typedef std::function<void(const math::Vector2& touchPoint)> TouchFunc;
}