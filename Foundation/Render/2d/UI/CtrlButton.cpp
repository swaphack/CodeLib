#include "CtrlButton.h"
#include "CtrlText.h"
#include "CtrlImage.h"

render::CtrlButton::CtrlButton()
{
	_btnImage = CREATE_NODE(CtrlImage);
	_btnImage->setName("button_image");
	_btnImage->setAnchorPoint(0, 0);
	this->addWidget(_btnImage, -1);

	_btnText = CREATE_NODE(CtrlText);
	_btnText->setName("button_text");
	_btnText->setAnchorPoint(0, 0);
	_btnText->setHorizontalAlignment(sys::HorizontalAlignment::CENTER);
	_btnText->setVerticalAlignment(sys::VerticalAlignment::MIDDLE);
	this->addWidget(_btnText, -1);

	this->setTouchEnable(true);
}

render::CtrlButton::~CtrlButton()
{
}

bool render::CtrlButton::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		_btnImage->setAnchorPoint(this->getAnchorPoint());
		_btnImage->setVolume(this->getVolume());

		_btnText->setAnchorPoint(this->getAnchorPoint());
		_btnText->setDimensions(this->getSize());
	});

	return true;
}

void render::CtrlButton::setString(const std::string& text)
{
	TextProtocol::setString(text);
	_btnText->setString(text);
}

void render::CtrlButton::setFontPath(const std::string& fonturl)
{
	_btnText->setFontPath(fonturl);
}

const std::string& render::CtrlButton::getFontPath() const
{
	return _btnText->getFontPath();
}

void render::CtrlButton::setFontSize(float size)
{
	_btnText->setFontSize(size);
}

float render::CtrlButton::getFontSize() const
{
	return _btnText->getFontSize();
}

void render::CtrlButton::setTextColor(const sys::Color3B& color)
{
	_btnText->setTextColor(color);
}

const sys::Color3B& render::CtrlButton::getTextColor() const
{
	return _btnText->getTextColor();
}

render::CtrlText* render::CtrlButton::getTextControl() const
{
	return _btnText;
}

void render::CtrlButton::setEnableImage(bool bEnabled)
{
	_btnImage->loadImage(bEnabled ? _btnImagePath.normal : _btnImagePath.disabled);
}

void render::CtrlButton::setSelectImage(bool bSelected)
{
	_btnImage->loadImage(bSelected ? _btnImagePath.selected : _btnImagePath.normal);
}

void render::CtrlButton::setNormalImage(const std::string& filepath)
{
	_btnImagePath.normal = filepath;
	_btnImage->setImagePath(filepath);
}

const std::string& render::CtrlButton::getNormalImage() const
{
	return _btnImagePath.normal;
}

void render::CtrlButton::setSelectedImage(const std::string& filepath)
{
	_btnImagePath.selected = filepath;
}

const std::string& render::CtrlButton::getSelectedImage() const
{
	return _btnImagePath.selected;
}

void render::CtrlButton::setDisabledImage(const std::string& filepath)
{
	_btnImagePath.disabled = filepath;
}

const std::string& render::CtrlButton::getDisabledImage() const
{
	return _btnImagePath.disabled;
}

render::CtrlImage* render::CtrlButton::getImageControl() const
{
	return _btnImage;
}

void render::CtrlButton::setTouchScale(float scale) 
{ 
	_touchScale = scale; 
}

float render::CtrlButton::getTouchScale() const 
{ 
	return _touchScale; 
}

bool render::CtrlButton::onTouchBegan(float x, float y, bool include)
{
	this->setScale(_touchScale);
	return include;
}

bool render::CtrlButton::onTouchMoved(float x, float y, bool include)
{
	this->setScale(_touchScale);
	return include;
}

bool render::CtrlButton::onTouchEnded(float x, float y, bool include)
{
	this->setScale(1.0f);
	return include;
}
