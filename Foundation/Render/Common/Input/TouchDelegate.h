#pragma once


#include "system.h"
#include <functional>

namespace render
{
	class Node;

	// 触摸类型
	enum class TouchType
	{
		NONE,	// 未触摸
		DOWN,	// 按下	
		ON,		// 按住不放
		UP,		// 放手
	};

	typedef void (sys::Object::*TOUCH_DELEGATE_HANDLER)(Node* node, float x, float y, bool include);

	#define TOUCH_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<TOUCH_DELEGATE_HANDLER>(&HANDLER_SEL)

	// 触摸委托
	typedef std::pair<sys::Object*, TOUCH_DELEGATE_HANDLER> TouchDelegate;

	// 触摸处理函数
	typedef std::function<void(Node* node, float x, float y, bool include)> TouchFunc;

	// 触摸协议
	class TouchProtocol
	{
	public:
		virtual ~TouchProtocol() {}
	public:
		/**
		*	点击屏幕
		*/
		virtual bool onTouchBegan(float x, float y, bool include) = 0;
		/**
		*	在屏幕上滑动
		*/
		virtual bool onTouchMoved(float x, float y, bool include) = 0;
		/**
		*	离开屏幕
		*/
		virtual bool onTouchEnded(float x, float y, bool include) = 0;
	};
}