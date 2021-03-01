#include "CtrlEditBox.h"
#include "Common/Input/import.h"

using namespace ui;


CtrlEditBox::CtrlEditBox()
:_keyboardEnabled(false)
, _editInputHandler(nullptr)
{
}

CtrlEditBox::~CtrlEditBox()
{
	this->removeKeyboardDelegate();
}

void CtrlEditBox::setKeyboardEnable(bool status)
{
	/*
	if (_keyboardEnabled == status)
	{
		return;
	}
	*/
	_keyboardEnabled = status;

	if (_keyboardEnabled)
	{
		this->dispatchInputListen(ui::EditInputStatus::BEGIN);
	}
	else
	{
		this->dispatchInputListen(ui::EditInputStatus::END);
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

void ui::CtrlEditBox::setInputFunc(const EditInputFunc& func)
{
	_editInputFunc = func;
}

void CtrlEditBox::dispatchInputListen(EditInputStatus status)
{
	if (_editInputHandler)
	{
		_editInputHandler(this, status);
	}

	if (_editInputFunc)
	{
		_editInputFunc(this, status);
	}
}

void CtrlEditBox::addKeyboardDelegate()
{
	G_KEYBOARDMANAGER->addKeyboardDelegate(this, this, KEYBOARD_DELEGATE_SELECTOR(CtrlEditBox::onKeyBoardInput));
}

void CtrlEditBox::removeKeyboardDelegate()
{
	G_KEYBOARDMANAGER->removeKeyboardDelegate(this, this);
}

void CtrlEditBox::onKeyBoardInput(Node* node, sys::BoardKey key, sys::ButtonStatus type)
{
	if (node != this)
	{
		return;
	}
	if (this->isKeyboardEnable() == false)
	{
		return;
	}

	this->onInputHand(key, type);
}

bool ui::CtrlEditBox::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	this->addTouchFunc(render::TouchType::BEGAN, [this](const math::Vector2& touchPoint, bool include) {
		this->setKeyboardEnable(false);
	});

	this->addTouchFunc(render::TouchType::ENDED, [this](const math::Vector2& touchPoint, bool include) {
		if (include)
		{
			bool bEnable = !isKeyboardEnable();
			this->setKeyboardEnable(bEnable);
		}
	});

	this->addKeyboardDelegate();

	return true;
}

void ui::CtrlEditBox::draw()
{

}
