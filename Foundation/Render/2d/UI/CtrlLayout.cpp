#include "CtrlLayout.h"
#include "CtrlImage.h"
#include "CtrlMask.h"
#include "Graphic/import.h"

render::CtrlLayout::CtrlLayout()
{
	_backgroundImage = CREATE_NODE(CtrlImage);
	this->addWidget(_backgroundImage);

	_backgroundMask = CREATE_NODE(CtrlMask);
	this->addWidget(_backgroundMask);
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

	_notify->addListen(NodeNotifyType::SPACE, [this](){
		_backgroundImage->setVolume(this->getVolume());
		_backgroundMask->setVolume(this->getVolume());
	});

	return true;
}

void render::CtrlLayout::setBackgroundColor(const sys::Color4B& color)
{
	_backgroundMask->setColor(color);
}

void render::CtrlLayout::setBackgroundImage(const std::string& filepath)
{
	_backgroundImage->setImagePath(filepath);
}