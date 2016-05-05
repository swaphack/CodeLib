#include "KeyBoard.h"

using namespace sys;


KeyBoard::KeyBoard()
{

}

KeyBoard::~KeyBoard()
{

}

void KeyBoard::setKeyhandler(Object* target, KEYBOARD_BUTTON_HANDLER handler)
{
	_buttonHandler.target = target;
	_buttonHandler.handler = handler;
}

void KeyBoard::onKeyEvent(BoardKey key, ButtonStatus status)
{
	_buttonHandler.hand(key, status);
}
