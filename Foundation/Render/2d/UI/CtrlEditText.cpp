#include "CtrlEditText.h"
#include "CtrlText.h"
#include "Common/Input/KeyChar.h"
#include <map>
using namespace render;

//////////////////////////////////////////////////////////////////////////
CtrlEditText::CtrlEditText()
{
	_ctrlTextPlaceholder = CREATE_NODE(CtrlText);
	_ctrlTextPlaceholder->setHorizontalAlignment(sys::HorizontalAlignment::LEFT);
	_ctrlTextPlaceholder->setAnchorPoint(0, 0);
	this->addWidget(_ctrlTextPlaceholder);

	_ctrlText = CREATE_NODE(CtrlText);
	_ctrlText->setHorizontalAlignment(sys::HorizontalAlignment::LEFT);
	_ctrlText->setAnchorPoint(0, 0);
	this->addWidget(_ctrlText);

	this->setTouchEnable(true);
}

CtrlEditText::~CtrlEditText()
{
}

void CtrlEditText::setString(const std::string& text)
{
	TextProtocol::setString(text);
	if (_ctrlText)
	{
		_ctrlText->setString(text);
	}

	bool empty = text.empty();
	_ctrlTextPlaceholder->setVisible(empty);
	//_ctrlText->setVisible(!empty);
}

CtrlText* CtrlEditText::getTextControl() const
{
	return _ctrlText;
}

bool render::CtrlEditText::init()
{
	if (!CtrlEditBox::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		_ctrlTextPlaceholder->setAnchorPoint(this->getAnchorPoint());
		_ctrlTextPlaceholder->setDimensions(this->getSize());

		_ctrlText->setAnchorPoint(this->getAnchorPoint());
		_ctrlText->setDimensions(this->getSize());
	});


	return true;
}

void render::CtrlEditText::setPlaceholder(const std::string& text)
{
	_ctrlTextPlaceholder->setString(text);
}

const std::string& render::CtrlEditText::getPlaceholder() const
{
	return _ctrlTextPlaceholder->getString();
}

void render::CtrlEditText::setFontPath(const std::string& fonturl)
{
	_ctrlText->setFontPath(fonturl);
	_ctrlTextPlaceholder->setFontPath(fonturl);
}

const std::string& render::CtrlEditText::getFontPath()  const
{
	return _ctrlText->getFontPath();
}

void render::CtrlEditText::setFontSize(float size)
{
	_ctrlText->setFontSize(size);
	_ctrlTextPlaceholder->setFontSize(size);
}

float render::CtrlEditText::getFontSize()  const
{
	return _ctrlText->getFontSize();
}

void render::CtrlEditText::setTextColor(const sys::Color3B& color)
{
	_ctrlText->setTextColor(color);
}

const sys::Color3B& render::CtrlEditText::getTextColor() const
{
	return _ctrlText->getTextColor();
}

void render::CtrlEditText::setPlaceholderTextColor(const sys::Color3B& color)
{
	_ctrlTextPlaceholder->setTextColor(color);
}

const sys::Color3B& render::CtrlEditText::getPlaceholderTextColor() const
{
	return _ctrlTextPlaceholder->getTextColor();
}

void CtrlEditText::onInputHand(sys::BoardKey key, sys::ButtonStatus type)
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

void CtrlEditText::onInputKeyBackHandler()
{
	std::string text = this->getString();
	if (!text.empty())
	{
		text = text.substr(0, text.size() - 1);
		this->setString(text.c_str());
	}
}

void CtrlEditText::onInputKeyReturnHandler()
{
	this->setKeyboardEnable(false);
}

void CtrlEditText::onInputKeyCharHandler(char value)
{
	std::string text = this->getString();
	text.append(1, value);
	this->setString(text.c_str());
}
