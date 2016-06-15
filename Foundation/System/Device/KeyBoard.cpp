#include "Keyboard.h"

using namespace sys;


Keyboard::Keyboard()
{

}

Keyboard::~Keyboard()
{

}

void Keyboard::setKeyhandler(Object* target, KEYBOARD_BUTTON_HANDLER handler)
{
	_buttonHandler.target = target;
	_buttonHandler.handler = handler;
}

void Keyboard::onKeyEvent(BoardKey key, ButtonStatus status)
{
	_buttonHandler.hand(key, status);
}
