#include "CtrlEditText.h"
#include "CtrlText.h"
#include "CtrlImage.h"
#include "Common/Input/KeyChar.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Action/import.h"
#include "Layout/LayoutItem.h"
#include <map>
using namespace ui;
using namespace render;

//////////////////////////////////////////////////////////////////////////
CtrlEditText::CtrlEditText()
{
	_ctrlTextPlaceholder = CREATE_NODE(CtrlText);
	_ctrlTextPlaceholder->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
	this->addProtectedWidget(_ctrlTextPlaceholder);

	_ctrlText = CREATE_NODE(CtrlText);
	_ctrlText->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
	this->addProtectedWidget(_ctrlText);

	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(phy::Color4B(255, 255, 255, 255));
	_ctrlCursor = CREATE_NODE(CtrlImage);
	_ctrlCursor->loadTexture(pTexture);
	_ctrlCursor->setVisible(false);
	_ctrlCursor->getLayoutItem()->setMarginState(true, false, true, true);
	_ctrlCursor->getLayoutItem()->setWidth(2);
	this->addProtectedWidget(_ctrlCursor);

	this->setTouchEnabled(true);
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

bool ui::CtrlEditText::init()
{
	if (!CtrlEditBox::init())
	{
		return false;
	}

	_ctrlText->addNotifyListener(NodeNotifyType::TEXT, [this]() {
		_ctrlCursor->getLayoutItem()->setLeftMargin(_ctrlText->getRender()->getWidth() + 1);
		_ctrlCursor->refreshLayout();
	});

	this->setInputFunc([this](sys::Object* object, EditInputStatus status) {
		if (status == EditInputStatus::BEGIN)
		{
			showCursor();
		}
		else
		{
			hideCursor();
		}
	});
	return true;
}

void ui::CtrlEditText::setPlaceholderString(const std::string& text)
{
	_ctrlTextPlaceholder->setString(text);
}

const std::string& ui::CtrlEditText::getPlaceholderString() const
{
	return _ctrlTextPlaceholder->getString();
}

void ui::CtrlEditText::setFontPath(const std::string& fonturl)
{
	_ctrlText->setFontPath(fonturl);
	_ctrlTextPlaceholder->setFontPath(fonturl);
}

const std::string& ui::CtrlEditText::getFontPath()  const
{
	return _ctrlText->getFontPath();
}

void ui::CtrlEditText::setFontSize(float size)
{
	_ctrlText->setFontSize(size);
	_ctrlTextPlaceholder->setFontSize(size);
}

float ui::CtrlEditText::getFontSize()  const
{
	return _ctrlText->getFontSize();
}

void ui::CtrlEditText::setTextColor(const phy::Color3B& color)
{
	_ctrlText->setTextColor(color);
}

const phy::Color3B& ui::CtrlEditText::getTextColor() const
{
	return _ctrlText->getTextColor();
}

void ui::CtrlEditText::setPlaceholderTextColor(const phy::Color3B& color)
{
	_ctrlTextPlaceholder->setTextColor(color);
}

const phy::Color3B& ui::CtrlEditText::getPlaceholderTextColor() const
{
	return _ctrlTextPlaceholder->getTextColor();
}

void ui::CtrlEditText::setMultiLine(bool bMulti)
{
	_multiLine = bMulti;

	if (_multiLine)
	{
		_ctrlText->setDimensions(this->getSize());
	}
	else
	{
		_ctrlText->setDimensions(math::Vector2());
	}
}

bool ui::CtrlEditText::isMultiLine() const
{
	return _multiLine;
}

void ui::CtrlEditText::setTextHorizontalAlignment(sys::HorizontalAlignment alignment)
{
	_ctrlText->setTextHorizontalAlignment(alignment);
	_ctrlTextPlaceholder->setTextHorizontalAlignment(alignment);
}

sys::HorizontalAlignment ui::CtrlEditText::getTextHorizontalAlignment() const
{
	return _ctrlText->getTextHorizontalAlignment();
}

void ui::CtrlEditText::setTextVerticalAlignment(sys::VerticalAlignment alignment)
{
	_ctrlText->setTextVerticalAlignment(alignment);
	_ctrlTextPlaceholder->setTextVerticalAlignment(alignment);
}

sys::VerticalAlignment ui::CtrlEditText::getTextVerticalAlignment() const
{
	return _ctrlText->getTextVerticalAlignment();
}

float ui::CtrlEditText::getCursorFlashTime() const
{
	return _cursorFlashTime;
}

void ui::CtrlEditText::setCursorFlashTime(float value)
{
	_cursorFlashTime = value;
}

void ui::CtrlEditText::setCursorColor(const phy::Color4B& color)
{
	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(color);
	_ctrlCursor->loadTexture(pTexture);
}

void CtrlEditText::onInputHand(sys::BoardKey key, sys::ButtonStatus type)
{
	if (type != sys::ButtonStatus::BUTTON_DOWN)
	{
		return;
	}

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

void ui::CtrlEditText::showCursor()
{
	if (_ctrlCursor == nullptr)
	{
		return;
	}

	_ctrlCursor->setVisible(true);

	auto pSequenceAction = SequenceAction::create(
		DelayAction::create(_cursorFlashTime),
		CallFuncN::create([](Node* node) { node->setVisible(true); }),
		DelayAction::create(_cursorFlashTime),
		CallFuncN::create([](Node* node) { node->setVisible(false); })
	);
	auto pForeverAction = RepeateForeverAction::create(pSequenceAction);

	_ctrlCursor->getActionProxy()->stopAllActions();
	_ctrlCursor->getActionProxy()->runAction(pForeverAction);
}

void ui::CtrlEditText::hideCursor()
{
	if (_ctrlCursor == nullptr)
	{
		return;
	}

	_ctrlCursor->setVisible(false);
	_ctrlCursor->getActionProxy()->stopAllActions();
}
