#include "Mouse.h"

using namespace sys;


Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}

void Mouse::setButtonHandler(Object* target, MOUSE_BUTTON_HANDLER handler)
{
	_buttonHandler.first = target;
	_buttonHandler.second = handler;
}

void Mouse::setScrollHandler(Object* target, MOUSE_SCROLL_HANDLER handler)
{
	_scrollHandler.first = target;
	_scrollHandler.second = handler;
}

void Mouse::setMoveHandler(Object* target, MOUSE_MOVE_HANDLER handler)
{
	_moveHandler.first = target;
	_moveHandler.second = handler;
}

void Mouse::onButtonHandler(MouseKey Key, ButtonStatus type, float x, float y)
{
	if (_buttonHandler.first && _buttonHandler.second)
	{
		(_buttonHandler.first->*_buttonHandler.second)(Key, type, x, y);
	}
}

void Mouse::onScrollHandler(ScrollEvent type, float param)
{
	if (_scrollHandler.first && _scrollHandler.second)
	{
		(_scrollHandler.first->*_scrollHandler.second)(type, param);
	}
}

void Mouse::onMoveHandler(float x, float y)
{
	if (_moveHandler.first && _moveHandler.second)
	{
		(_moveHandler.first->*_moveHandler.second)(x, y);
	}
}
