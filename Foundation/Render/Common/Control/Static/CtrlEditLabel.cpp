#include "CtrlEditLabel.h"

using namespace render;


CtrlEditLabel::CtrlEditLabel()
{
	_ctrlText = new CtrlText();
	AUTO_RELEASE_OBJECT(_ctrlText);
	this->addChild(_ctrlText);
}

CtrlEditLabel::~CtrlEditLabel()
{
	_ctrlText->release();
}

void CtrlEditLabel::setString(const char* text)
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
	if (type != sys::EBS_BUTTON_DOWN)
	{
		return;
	}

	if (key == sys::EBK_RETURN)
	{
		this->setKeyboardEnable(false);
		return;
	}

	std::string text = this->getString();
	if (key == sys::EBK_BACK)
	{
		text = text.substr(0, text.size() - 1);
	}
	else
	{
		text.append(1, (char)key);
	}
	this->setString(text.c_str());
}
