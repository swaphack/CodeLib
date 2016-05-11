#pragma once

#include "macros.h"
#include "DeviceEventHandler.h"

namespace sys
{	
	// ����
	class KeyBoard
	{
	private:
		
	public:
		KeyBoard();
		virtual ~KeyBoard();
	public:
		// ���ý��մ���
		void setKeyhandler(Object* target, KEYBOARD_BUTTON_HANDLER handler);
		// ���̴����¼�
		void onKeyEvent(BoardKey key, ButtonStatus status);
	private:
		KeyBoardButtonEvent _buttonHandler;
	};
}