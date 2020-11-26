#include "CtrlLayout.h"
#include "CtrlImage.h"
#include "CtrlMask.h"
#include "Graphic/import.h"

render::CtrlLayout::CtrlLayout()
{
	this->setAnchorPoint(0.0f, 0.0f, 0.0f);

	_backgroundImage = CREATE_NODE(CtrlImage);
	_backgroundImage->setName("layout_bg_image");
	_backgroundImage->setAnchorPoint(0, 0);
	_backgroundImage->setVisible(false);
	this->addProtectedWidget(_backgroundImage);

	_backgroundMask = CREATE_NODE(CtrlMask);
	_backgroundMask->setName("layout_bg_mask");
	_backgroundMask->setAnchorPoint(0, 0);
	_backgroundMask->setColor(phy::Color4B(125, 125, 125, 125));
	_backgroundMask->setVisible(false);
	this->addProtectedWidget(_backgroundMask);
}

render::CtrlLayout::~CtrlLayout()
{

}

bool render::CtrlLayout::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this](){
		_backgroundImage->setAnchorPoint(this->getAnchorPoint());
		_backgroundImage->setVolume(this->getVolume());

		_backgroundMask->setAnchorPoint(this->getAnchorPoint());
		_backgroundMask->setVolume(this->getVolume());
	});

	//setBackgroudImageVisible(false);
	//setBackgroudMaskVisible(false);

	return true;
}

void render::CtrlLayout::setBackgroundColor(const phy::Color4B& color)
{
	_backgroundMask->setColor(color);
}

const phy::Color4B& render::CtrlLayout::getBackgroundColor() const
{
	return _backgroundMask->getColor();
}

void render::CtrlLayout::setBackgroundImagePath(const std::string& filepath)
{
	_backgroundImage->setImagePath(filepath);
}

const std::string& render::CtrlLayout::getBackgroundImagePath() const
{
	return _backgroundImage->getImagePath();
}

render::CtrlImage* render::CtrlLayout::getBackgroundImage() const
{
	return _backgroundImage;
}

render::CtrlMask* render::CtrlLayout::getBackgroundMask() const
{
	return _backgroundMask;
}

void render::CtrlLayout::setBackgroudImageVisible(bool bVisible)
{
	_backgroundImage->setVisible(bVisible);
}

bool render::CtrlLayout::isBackgroudImageVisible() const
{
	return _backgroundImage->isVisible();
}

void render::CtrlLayout::setBackgroudMaskVisible(bool bVisible)
{
	_backgroundMask->setVisible(bVisible);
}

bool render::CtrlLayout::isBackgroudMaskVisible() const
{
	return _backgroundMask->isVisible();
}
