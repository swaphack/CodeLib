#pragma once

#include "macros.h"

#include "DeviceEventHandler.h"

namespace sys
{
	// 鼠标
	class Mouse
	{		
	public:
		Mouse();
		virtual ~Mouse();
	public:
		// 设置按钮点击监听事件
		void setButtonHandler(Object* target, MOUSE_BUTTON_HANDLER handler);
		// 设置滑轮滚动监听事件
		void setScrollHandler(Object* target, MOUSE_SCROLL_HANDLER handler);
		// 设置鼠标移动监听事件
		void setMoveHandler(Object* target, MOUSE_MOVE_HANDLER handler);

		void onButtonHandler(MouseKey Key, ButtonStatus type, float x, float y) const;
		void onScrollHandler(ScrollEvent type, float param) const;
		void onMoveHandler(float x, float y) const;
	protected:
	private:
		// 按钮事件
		MouseButtonEvent _buttonHandler;
		// 滚轮事件
		MouseScrollEvent _scrollHandler;
		// 鼠标滑动
		MouseMoveEvent	_moveHandler;
	};
}