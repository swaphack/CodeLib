#pragma once


#include "system.h"
#include <functional>

namespace render
{
	// 触摸类型
	enum TouchType
	{
		ETT_NONE,	// 未触摸
		ETT_DOWN,	// 按下	
		ETT_ON,		// 按住不放
		ETT_UP,		// 放手
	};

	typedef void (sys::Object::*TOUCH_DELEGATE_HANDLER)(sys::Object* object, float x, float y);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// 触摸委托
	typedef std::pair<sys::Object*, TOUCH_DELEGATE_HANDLER> TouchDelegate;

	// 触摸协议
	class TouchProtocol
	{
	public:
		virtual ~TouchProtocol() {}
	public:
		// 点击屏幕
		virtual bool onTouchBegan(float x, float y) = 0;
		// 在屏幕上滑动
		virtual void onTouchMoved(float x, float y) = 0;
		// 离开屏幕
		virtual void onTouchEnded(float x, float y) = 0;
	};
}