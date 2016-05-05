#pragma once

#include "macros.h"
#include "DeviceEventHandler.h"

namespace sys
{	
	// ¼üÅÌ
	class KeyBoard
	{
	private:
		
	public:
		KeyBoard();
		virtual ~KeyBoard();
	public:
		void setKeyhandler(Object* target, KEYBOARD_BUTTON_HANDLER handler);

		void onKeyEvent(BoardKey key, ButtonStatus status);
	protected:
	private:
		KeyBoardButtonEvent _buttonHandler;
	};
}