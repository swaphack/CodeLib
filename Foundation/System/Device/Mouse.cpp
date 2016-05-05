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
	_buttonHandler.target = target;
	_buttonHandler.handler = handler;
}

void Mouse::setScrollHandler(Object* target, MOUSE_SCROLL_HANDLER handler)
{
	_scrollHandler.target = target;
	_scrollHandler.handler = handler;
}

void Mouse::setMoveHandler(Object* target, MOUSE_MOVE_HANDLER handler)
{
	_moveHandler.target = target;
	_moveHandler.handler = handler;
}

void Mouse::onButtonHandler(MouseKey Key, ButtonStatus type)
{
	_buttonHandler.hand(Key, type);
}

void Mouse::onScrollHandler(ScrollEvent type, float param)
{
	_scrollHandler.hand(type, param);
}

void Mouse::onMoveHandler(float x, float y)
{
	_moveHandler.hand(x, y);
}
