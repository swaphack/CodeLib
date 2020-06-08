#include "CtrlEditLabel.h"
#include "CtrlText.h"
#include "Common/Input/KeyChar.h"
#include <map>
using namespace render;

//////////////////////////////////////////////////////////////////////////
CtrlEditLabel::CtrlEditLabel()
{
	_ctrlText = CREATE_OBJECT(CtrlText);
	this->addChild(_ctrlText);
}

CtrlEditLabel::~CtrlEditLabel()
{
	_ctrlText->release();
}

void CtrlEditLabel::setString(const std::string& text)
{
	TextProtocol::setString(text);
	if (_ctrlText)
	{
		_ctrlText->setString(text);
	}
}

CtrlText* CtrlEditLabel::getCtrlText()
{
	return _ctrlText;
}

void CtrlEditLabel::onInputHand(sys::BoardKey key, sys::ButtonStatus type)
{
	if (type != sys::ButtonStatus::BUTTON_DOWN)
	{
		return;
	}

	G_KEYCHAR->setControlKey(key);

	if (key == sys::BoardKey::KRETURN)
	{
		onInputKeyReturnHandler();
		return;
	}

	std::string text = this->getString();
	if (key == sys::BoardKey::KBACK)
	{
		onInputKeyBackHandler();
		return;
	}

	char value = G_KEYCHAR->getChar(key);
	if (value)
	{
		onInputKeyCharHandler(value);
	}
}

void CtrlEditLabel::onInputKeyBackHandler()
{
	std::string text = this->getString();
	text = text.substr(0, text.size() - 1);
	this->setString(text.c_str());
}

void CtrlEditLabel::onInputKeyReturnHandler()
{
	this->setKeyboardEnable(false);
}

void CtrlEditLabel::onInputKeyCharHandler(char value)
{
	std::string text = this->getString();
	text.append(1, value);
	this->setString(text.c_str());
}
