#pragma once

#include "macros.h"
#include "DeviceEventHandler.h"

namespace sys
{	
	// 键盘
	class Keyboard
	{
	private:
		
	public:
		Keyboard();
		virtual ~Keyboard();
	public:
		// 设置接收处理
		void setKeyhandler(Object* target, KEYBOARD_BUTTON_HANDLER handler);
		// 键盘触发事件
		void onKeyEvent(BoardKey key, ButtonStatus status);
	private:
		KeyBoardButtonEvent _buttonHandler;
	};
}