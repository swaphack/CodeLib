#include "CtrlLayout.h"
#include "CtrlImage.h"
#include "2d/Primitive/Mask.h"
#include "Graphic/import.h"

render::CtrlLayout::CtrlLayout()
{
	_backgroundImage = CREATE_NODE(CtrlImage);
	this->addWidget(_backgroundImage, -1);

	_backgroundMask = CREATE_NODE(Mask);
	this->addChild(_backgroundMask, -1);
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
		_backgroundImage->setVolume(this->getVolume());
		_backgroundMask->setVolume(this->getVolume());
	});

	return true;
}

void render::CtrlLayout::draw()
{

}

void render::CtrlLayout::setBackgroundColor(const sys::Color4B& color)
{
	_backgroundMask->setColor(color);
}

void render::CtrlLayout::setBackgroundImage(const std::string& filepath)
{
	_backgroundImage->setImagePath(filepath);
}

render::CtrlImage* render::CtrlLayout::getBackgroundImage() const
{
	return _backgroundImage;
}

render::Mask* render::CtrlLayout::getBackgroundMask() const
{
	return _backgroundMask;
}
