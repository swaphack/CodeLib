#include "CtrlEditBox.h"
#include "Common/Touch/TouchProxy.h"
#include "Common/Touch/TouchDelegate.h"
#include "Common/Touch/TouchManager.h"
#include "Common/Keyboard/KeyboardManager.h"

using namespace render;


CtrlEditBox::CtrlEditBox()
:_keyboardEnabled(false)
, _editInputHandler(nullptr)
{
	this->getTouchProxy()->addTouchDelegate(render::TouchType::UP, this, TOUCH_DELEGATTE_SELECTOR(CtrlEditBox::onTouchUp));

	this->addKeyboardDelegate();
}

CtrlEditBox::~CtrlEditBox()
{
	this->removeKeyboardDelegate();
}

void CtrlEditBox::setKeyboardEnable(bool status)
{
	if (_keyboardEnabled == status)
	{
		return;
	}

	_keyboardEnabled = status;

	if (_keyboardEnabled)
	{
		this->dispatchInputListen(render::EditInputStatus::BEGIN);
	}
	else
	{
		this->dispatchInputListen(render::EditInputStatus::END);
	}
}

bool CtrlEditBox::isKeyboardEnable()
{
	return _keyboardEnabled;
}

void CtrlEditBox::setInputListen(EDITINPUT_DELEGATE_HANDLER handler)
{
	_editInputHandler = handler;
}

void CtrlEditBox::dispatchInputListen(EditInputStatus status)
{
	if (_editInputHandler == nullptr)
	{
		return;
	}

	_editInputHandler(this, status);
}

void CtrlEditBox::addKeyboardDelegate()
{
	G_KEYBOARDMANAGER->addDispatcher(this, this, KEYBOARD_DELEGATTE_SELECTOR(CtrlEditBox::onKeyBoardInput));
}

void CtrlEditBox::removeKeyboardDelegate()
{
	G_KEYBOARDMANAGER->removeDispatcher(this);
}

void CtrlEditBox::onTouchUp(sys::Object* object, float x, float y)
{
	CtrlEditBox* editBox = dynamic_cast<CtrlEditBox*>(object);
	if (editBox == nullptr)
	{
		return;
	}

	editBox->setKeyboardEnable(true);
}

void CtrlEditBox::onKeyBoardInput(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlEditBox* editBox = dynamic_cast<CtrlEditBox*>(object);
	if (editBox == nullptr || editBox->isKeyboardEnable() == false)
	{
		return;
	}

	editBox->onInputHand(key, type);
}
