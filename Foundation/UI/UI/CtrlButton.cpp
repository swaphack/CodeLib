#include "CtrlButton.h"
#include "CtrlText.h"
#include "CtrlImage.h"
#include "CtrlTextAtlas.h"
#include "Layout/LayoutItem.h"

ui::CtrlButton::CtrlButton()
{
	_btnImage = CREATE_NODE(CtrlImage);
	_btnImage->setName("button_image");
	//_btnImage->setVisible(false);
	_btnImage->getLayoutItem()->setMarginState(true, true, true, true);
	_btnImage->getLayoutItem()->setMargin(0, 0, 0, 0);
	this->addProtectedWidget(_btnImage);

	_btnText = CREATE_NODE(CtrlText);
	_btnText->setAnchorPoint(0.5f, 0.5f);
	_btnText->setName("button_text");
	_btnText->setTextHorizontalAlignment(sys::HorizontalAlignment::CENTER);
	_btnText->setTextVerticalAlignment(sys::VerticalAlignment::MIDDLE);
	_btnText->setVisible(false);
	this->addProtectedWidget(_btnText);

	_btnTextAtlas = CREATE_NODE(CtrlTextAtlas);
	_btnTextAtlas->setBoxVisible(true);
	_btnTextAtlas->setAnchorPoint(0.5f, 0.5f);
	_btnTextAtlas->setName("button_text_atlas");
	_btnTextAtlas->setTextHorizontalAlignment(sys::HorizontalAlignment::CENTER);
	_btnTextAtlas->setTextVerticalAlignment(sys::VerticalAlignment::MIDDLE);
	//_btnTextAtlas->setVisible(false);
	this->addProtectedWidget(_btnTextAtlas);

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

	this->addNotifyListener(render::NodeNotifyType::TEXT, [this]() {
		this->onButtonTextChange();
	});
	this->addNotifyListener(render::NodeNotifyType::BODY, [this]() {
		this->onButtonTextChange();
	});
	return true;
}

void ui::CtrlButton::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
	if (_btnText)
	{
		_btnText->setTexShaderProgram(shaderProgram);
	}
	if (_btnTextAtlas)
	{
		_btnTextAtlas->setTexShaderProgram(shaderProgram);
	}
	if (_btnImage)
	{
		_btnImage->setTexShaderProgram(shaderProgram);
	}
}

void ui::CtrlButton::setCamera(const render::Camera* camera)
{
	CtrlWidget::setCamera(camera);

	if (_btnText)
	{
		_btnText->setCamera(camera);
	}
	if (_btnTextAtlas)
	{
		_btnTextAtlas->setCamera(camera);
	}
	if (_btnImage)
	{
		_btnImage->setCamera(camera);
	}
}

void ui::CtrlButton::setUseDesignCamera(bool bUsed)
{
	CtrlWidget::setUseDesignCamera(bUsed);

	if (_btnText)
	{
		_btnText->setUseDesignCamera(bUsed);
	}
	if (_btnTextAtlas)
	{
		_btnTextAtlas->setUseDesignCamera(bUsed);
	}
	if (_btnImage)
	{
		_btnImage->setUseDesignCamera(bUsed);
	}
}

void ui::CtrlButton::setString(const std::string& text)
{
	TextProtocol::setString(text);
	_btnText->setString(text);
	_btnTextAtlas->setString(text);
}

void ui::CtrlButton::setFontPath(const std::string& fontUrl)
{
	_btnText->setFontPath(fontUrl);
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
void ui::CtrlButton::setFontImagePath(const std::string& fontImageUrl)
{
	_btnTextAtlas->setImagePath(fontImageUrl);
}

const std::string& ui::CtrlButton::getFontImagePath() const
{
	return _btnTextAtlas->getImagePath();
}

void ui::CtrlButton::setTextColor(const phy::Color3B& color)
{
	_btnText->setTextColor(color);
	_btnTextAtlas->setTextColor(color);
}

const phy::Color3B& ui::CtrlButton::getTextColor() const
{
	return _btnText->getTextColor();
}

void ui::CtrlButton::setTextHorizontalAlignment(sys::HorizontalAlignment alignment)
{
	if (_textHoriztontalAlignment == alignment) return;
	_textHoriztontalAlignment = alignment;
	this->notify(render::NodeNotifyType::TEXT);

}

sys::HorizontalAlignment ui::CtrlButton::getTextHorizontalAlignment() const
{
	return _textHoriztontalAlignment;
}

void ui::CtrlButton::setTextVerticalAlignment(sys::VerticalAlignment alignment)
{
	if (_textVerticalAlignment == alignment) return;
	_textVerticalAlignment = alignment;

	this->notify(render::NodeNotifyType::TEXT);
}

sys::VerticalAlignment ui::CtrlButton::getTextVerticalAlignment() const
{
	return _textVerticalAlignment;
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

void ui::CtrlButton::onButtonTextChange()
{
	sys::CSSMargin margin;
	ui::MarginState mariginState;

	_btnText->setTextHorizontalAlignment(_textHoriztontalAlignment);
	_btnText->setTextVerticalAlignment(_textVerticalAlignment);

	_btnTextAtlas->setTextHorizontalAlignment(_textHoriztontalAlignment);
	_btnTextAtlas->setTextVerticalAlignment(_textVerticalAlignment);


	if (_textVerticalAlignment == sys::VerticalAlignment::BOTTOM)
	{
		margin.setBottom(sys::NumberType::Fixed, 0);
		mariginState.Bottom = true;
	}
	else if (_textVerticalAlignment == sys::VerticalAlignment::MIDDLE)
	{
		_btnText->setAnchorPointX(0.5f);
		_btnText->setPositionX(this->getWidth() * 0.5f);

		_btnTextAtlas->setAnchorPointX(0.5f);
		_btnTextAtlas->setPositionX(this->getWidth() * 0.5f);
	}
	else if (_textVerticalAlignment == sys::VerticalAlignment::TOP)
	{
		margin.setTop(sys::NumberType::Fixed, 0);
		mariginState.Top = true;
	}

	if (_textHoriztontalAlignment == sys::HorizontalAlignment::LEFT)
	{
		margin.setLeft(sys::NumberType::Fixed, 0);
		mariginState.Left = true;
	}
	else if (_textHoriztontalAlignment == sys::HorizontalAlignment::CENTER)
	{
		_btnText->setAnchorPointY(0.5f);
		_btnText->setPositionY(this->getHeight() * 0.5f);

		_btnTextAtlas->setAnchorPointY(0.5f);
		_btnTextAtlas->setPositionY(this->getHeight() * 0.5f);
	}
	else if (_textHoriztontalAlignment == sys::HorizontalAlignment::RIGHT)
	{
		margin.setRight(sys::NumberType::Fixed, 0);
		mariginState.Right = true;
	}

	_btnText->getLayoutItem()->setMarginState(mariginState);
	_btnText->getLayoutItem()->setMargin(margin);

	_btnTextAtlas->getLayoutItem()->setMarginState(mariginState);
	_btnTextAtlas->getLayoutItem()->setMargin(margin);
	_btnTextAtlas->setPosition(-0.5f * getVolume());
}