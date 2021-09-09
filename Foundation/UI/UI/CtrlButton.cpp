#include "CtrlButton.h"
#include "CtrlText.h"
#include "CtrlImage.h"
#include "Layout/LayoutItem.h"

ui::CtrlButton::CtrlButton()
{
	_btnImage = CREATE_NODE(CtrlImage);
	_btnImage->setName("button_image");
	this->addProtectedWidget(_btnImage);

	_btnText = CREATE_NODE(CtrlText);
	_btnText->setAnchorPoint(0.5f, 0.5f);
	_btnText->setName("button_text");
	_btnText->setTextHorizontalAlignment(sys::HorizontalAlignment::CENTER);
	_btnText->setTextVerticalAlignment(sys::VerticalAlignment::MIDDLE);
	this->addProtectedWidget(_btnText);

	this->setTouchEnabled(true);
}

ui::CtrlButton::~CtrlButton()
{
}

bool ui::CtrlButton::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}
	this->addTouchFunc(render::TouchType::BEGAN, [this](const math::Vector2& touchPoint) {
		this->setScale(_touchScale);
	});

	this->addTouchFunc(render::TouchType::ENDED, [this](const math::Vector2& touchPoint) {
		this->setScale(1.0f);
	});

	this->addTouchFunc(render::TouchType::CANCELED, [this](const math::Vector2& touchPoint) {
		this->setScale(1.0f);
	});
	return true;
}

void ui::CtrlButton::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
	if (_btnText)
	{
		_btnText->setTexShaderProgram(shaderProgram);
	}
	if (_btnImage)
	{
		_btnImage->setTexShaderProgram(shaderProgram);
	}
}

void ui::CtrlButton::setString(const std::string& text)
{
	TextProtocol::setString(text);
	_btnText->setString(text);
}

void ui::CtrlButton::setFontPath(const std::string& fonturl)
{
	_btnText->setFontPath(fonturl);
}

const std::string& ui::CtrlButton::getFontPath() const
{
	return _btnText->getFontPath();
}

void ui::CtrlButton::setFontSize(float size)
{
	_btnText->setFontSize(size);
}

float ui::CtrlButton::getFontSize() const
{
	return _btnText->getFontSize();
}

void ui::CtrlButton::setTextColor(const phy::Color3B& color)
{
	_btnText->setTextColor(color);
}

const phy::Color3B& ui::CtrlButton::getTextColor() const
{
	return _btnText->getTextColor();
}

void ui::CtrlButton::setTextHorizontalAlignment(sys::HorizontalAlignment alignment)
{
	_btnText->setTextHorizontalAlignment(alignment);
}

sys::HorizontalAlignment ui::CtrlButton::getTextHorizontalAlignment() const
{
	return _btnText->getTextHorizontalAlignment();
}

void ui::CtrlButton::setTextVerticalAlignment(sys::VerticalAlignment alignment)
{
	_btnText->setTextVerticalAlignment(alignment);
}

sys::VerticalAlignment ui::CtrlButton::getTextVerticalAlignment() const
{
	return _btnText->getTextVerticalAlignment();
}

ui::CtrlText* ui::CtrlButton::getTextControl() const
{
	return _btnText;
}

void ui::CtrlButton::setEnableState(bool bEnabled)
{
	_enableButton = bEnabled;
	_btnImage->loadImage(bEnabled ? _btnImagePath.normal : _btnImagePath.disabled);
}

bool ui::CtrlButton::isEnabled() const
{
	return _enableButton;
}

void ui::CtrlButton::setSelectState(bool bSelected)
{
	_selected = bSelected;
	_btnImage->loadImage(bSelected ? _btnImagePath.selected : _btnImagePath.normal);
}

bool ui::CtrlButton::isSelected() const
{
	return _selected;
}

void ui::CtrlButton::setNormalImage(const std::string& filepath)
{
	_btnImagePath.normal = filepath;
	_btnImage->loadImage(filepath);
}

const std::string& ui::CtrlButton::getNormalImage() const
{
	return _btnImagePath.normal;
}

void ui::CtrlButton::setSelectedImage(const std::string& filepath)
{
	_btnImagePath.selected = filepath;
}

const std::string& ui::CtrlButton::getSelectedImage() const
{
	return _btnImagePath.selected;
}

void ui::CtrlButton::setDisabledImage(const std::string& filepath)
{
	_btnImagePath.disabled = filepath;
}

const std::string& ui::CtrlButton::getDisabledImage() const
{
	return _btnImagePath.disabled;
}

ui::CtrlImage* ui::CtrlButton::getImageControl() const
{
	return _btnImage;
}

void ui::CtrlButton::setTouchScale(float scale) 
{ 
	_touchScale = scale; 
}

float ui::CtrlButton::getTouchScale() const 
{ 
	return _touchScale; 
}
