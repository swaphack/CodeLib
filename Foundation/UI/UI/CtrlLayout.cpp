#include "CtrlLayout.h"
#include "CtrlImage.h"
#include "CtrlMask.h"
#include "Graphic/import.h"

using namespace render;

ui::CtrlLayout::CtrlLayout()
{
	this->setAnchorPoint(0.0f, 0.0f, 0.0f);

	_backgroundImage = CREATE_NODE(CtrlImage);
	_backgroundImage->setName("layout_bg_image");
	_backgroundImage->setVisible(false);
	this->addProtectedWidget(_backgroundImage);

	_backgroundMask = CREATE_NODE(CtrlMask);
	_backgroundMask->setName("layout_bg_mask");
	_backgroundMask->setColor(phy::Color4B(125, 125, 125, 125));
	_backgroundMask->setVisible(false);
	this->addProtectedWidget(_backgroundMask);
}

ui::CtrlLayout::~CtrlLayout()
{

}

bool ui::CtrlLayout::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	return true;
}

void ui::CtrlLayout::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
	if (_backgroundImage)
	{
		_backgroundImage->setTexShaderProgram(shaderProgram);
	}
}

void ui::CtrlLayout::setColorShaderProgram(render::ShaderProgram* shaderProgram)
{
	if (_backgroundMask)
	{
		_backgroundMask->setColorShaderProgram(shaderProgram);
	}
}

void ui::CtrlLayout::setCamera(const render::Camera* camera)
{
	CtrlWidget::setCamera(camera);
	if (_backgroundImage)
	{
		_backgroundImage->setCamera(camera);
	}
	if (_backgroundMask)
	{
		_backgroundMask->setCamera(camera);
	}
}

void ui::CtrlLayout::setUseDesignCamera(bool bUsed)
{
	CtrlWidget::setUseDesignCamera(bUsed);

	if (_backgroundImage)
	{
		_backgroundImage->setUseDesignCamera(bUsed);
	}
	if (_backgroundMask)
	{
		_backgroundMask->setUseDesignCamera(bUsed);
	}
}

void ui::CtrlLayout::setBackgroundColor(const phy::Color4B& color)
{
	_backgroundMask->setColor(color);
}

phy::Color4B ui::CtrlLayout::getBackgroundColor() const
{
	phy::Color4B color;
	convertColor4FTo4B(_backgroundMask->getColor(), color);
	return color;
}

void ui::CtrlLayout::setBackgroundImagePath(const std::string& filepath)
{
	_backgroundImage->setImagePath(filepath);
}

const std::string& ui::CtrlLayout::getBackgroundImagePath() const
{
	return _backgroundImage->getImagePath();
}

ui::CtrlImage* ui::CtrlLayout::getBackgroundImage() const
{
	return _backgroundImage;
}

ui::CtrlMask* ui::CtrlLayout::getBackgroundMask() const
{
	return _backgroundMask;
}

void ui::CtrlLayout::setBackgroudImageVisible(bool bVisible)
{
	_backgroundImage->setVisible(bVisible);
}

bool ui::CtrlLayout::isBackgroudImageVisible() const
{
	return _backgroundImage->isVisible();
}

void ui::CtrlLayout::setBackgroudMaskVisible(bool bVisible)
{
	_backgroundMask->setVisible(bVisible);
}

bool ui::CtrlLayout::isBackgroudMaskVisible() const
{
	return _backgroundMask->isVisible();
}
