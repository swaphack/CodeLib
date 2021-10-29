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
	_buttonHandler.first = target;
	_buttonHandler.second = handler;
}

void Keyboard::onKeyEvent(BoardKey key, ButtonStatus status) const
{
	if (_buttonHandler.first && _buttonHandler.second)
	{
		(_buttonHandler.first->*_buttonHandler.second)(key, status);
	}
}
