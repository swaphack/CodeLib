#pragma once

#include "macros.h"

#include "DeviceEventHandler.h"

namespace sys
{
	// ���
	class Mouse
	{		
	public:
		Mouse();
		virtual ~Mouse();
	public:
		// ���ð�ť��������¼�
		void setButtonHandler(Object* target, MOUSE_BUTTON_HANDLER handler);
		// ���û��ֹ��������¼�
		void setScrollHandler(Object* target, MOUSE_SCROLL_HANDLER handler);
		// ��������ƶ������¼�
		void setMoveHandler(Object* target, MOUSE_MOVE_HANDLER handler);

		void onButtonHandler(MouseKey Key, ButtonStatus type, float x, float y) const;
		void onScrollHandler(ScrollEvent type, float param) const;
		void onMoveHandler(float x, float y) const;
	protected:
	private:
		// ��ť�¼�
		MouseButtonEvent _buttonHandler;
		// �����¼�
		MouseScrollEvent _scrollHandler;
		// ��껬��
		MouseMoveEvent	_moveHandler;
	};
}