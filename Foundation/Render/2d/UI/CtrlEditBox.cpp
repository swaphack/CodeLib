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
	G_KEYBOARDMANAGER->addKeyboardDelegate(this, this, KEYBOARD_DELEGATTE_SELECTOR(CtrlEditBox::onKeyBoardInput));
}

void CtrlEditBox::removeKeyboardDelegate()
{
	G_KEYBOARDMANAGER->removeKeyboardDelegate(this);
}

void CtrlEditBox::onTouchUp(Node* node, float x, float y, bool include)
{
	CtrlEditBox* editBox = node->as<CtrlEditBox>();
	if (editBox == nullptr)
	{
		return;
	}

	editBox->setKeyboardEnable(true);
}

void CtrlEditBox::onKeyBoardInput(Node* node, sys::BoardKey key, sys::ButtonStatus type)
{
	CtrlEditBox* editBox = node->as<CtrlEditBox>();
	if (editBox == nullptr || editBox->isKeyboardEnable() == false)
	{
		return;
	}

	editBox->onInputHand(key, type);
}
