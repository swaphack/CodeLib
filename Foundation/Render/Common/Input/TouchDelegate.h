#pragma once


#include "system.h"
#include <functional>

namespace render
{
	class Node;

	// 触摸类型
	enum class TouchType
	{
		NONE,		// 未触摸
		BEGAN,		// 按下	
		MOVED,		// 按住不放
		ENDED,		// 放手
		CANCELED,	// 取消
	};

	typedef void (sys::Object::*TOUCH_DELEGATE_HANDLER)(render::Node* node, const math::Vector2& touchPoint);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// 触摸委托
	typedef std::pair<sys::Object*, TOUCH_DELEGATE_HANDLER> TouchDelegate;

	// 触摸处理函数
	typedef std::function<void(const math::Vector2& touchPoint)> TouchFunc;
}