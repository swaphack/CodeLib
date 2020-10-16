#include "CtrlEditLabel.h"
#include "CtrlText.h"
#include "Common/Input/KeyChar.h"
#include <map>
using namespace render;

//////////////////////////////////////////////////////////////////////////
CtrlEditLabel::CtrlEditLabel()
{
	_ctrlTextPlaceholder = CREATE_NODE(CtrlText);
	this->addWidget(_ctrlTextPlaceholder);

	_ctrlText = CREATE_NODE(CtrlText);
	this->addWidget(_ctrlText);
}

CtrlEditLabel::~CtrlEditLabel()
{
}

void CtrlEditLabel::setString(const std::string& text)
{
	TextProtocol::setString(text);
	if (_ctrlText)
	{
		_ctrlText->setString(text);
	}

	bool empty = text.empty();
	_ctrlTextPlaceholder->setVisible(empty);
}

CtrlText* CtrlEditLabel::getTextControl() const
{
	return _ctrlText;
}

void render::CtrlEditLabel::setPlaceholder(const std::string& text)
{
	_ctrlTextPlaceholder->setString(text);
}

const std::string& render::CtrlEditLabel::getPlaceholder() const
{
	return _ctrlTextPlaceholder->getString();
}

void render::CtrlEditLabel::setFontPath(const std::string& fonturl)
{
	_ctrlText->setFontPath(fonturl);
	_ctrlTextPlaceholder->setFontPath(fonturl);
}

const std::string& render::CtrlEditLabel::getFontPath()  const
{
	return _ctrlText->getFontPath();
}

void render::CtrlEditLabel::setFontSize(float size)
{
	_ctrlText->setFontSize(size);
	_ctrlTextPlaceholder->setFontSize(size);
}

float render::CtrlEditLabel::getFontSize()  const
{
	return _ctrlText->getFontSize();
}

void render::CtrlEditLabel::setTextColor(const sys::Color3B& color)
{
	_ctrlText->setTextColor(color);
}

const sys::Color3B& render::CtrlEditLabel::getTextColor() const
{
	return _ctrlText->getTextColor();
}

void render::CtrlEditLabel::setPlaceholderTextColor(const sys::Color3B& color)
{
	_ctrlTextPlaceholder->setTextColor(color);
}

const sys::Color3B& render::CtrlEditLabel::getPlaceholderTextColor() const
{
	return _ctrlTextPlaceholder->getTextColor();
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
