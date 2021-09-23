#include "CtrlMask.h"

using namespace ui;
using namespace render;

ui::CtrlMask::CtrlMask()
{
	_maskNode = CREATE_NODE(render::Mask);
	this->addChild(_maskNode);
}

ui::CtrlMask::~CtrlMask()
{
}

bool ui::CtrlMask::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::BODY, [this]() {
		_maskNode->setVolume(this->getVolume());
	});

	return true;
}

void ui::CtrlMask::setColorShaderProgram(render::ShaderProgram* shaderProgram)
{
	if (_maskNode)
	{
		_maskNode->setShaderProgram(shaderProgram);
	}
}

void ui::CtrlMask::setCamera(const render::Camera* camera)
{
	CtrlWidget::setCamera(camera);

	if (_maskNode)
	{
		_maskNode->setCamera(camera);
	}
}

void ui::CtrlMask::setUseDesignCamera(bool bUsed)
{
	CtrlWidget::setUseDesignCamera(bUsed);

	if (_maskNode)
	{
		_maskNode->setUseDesignCamera(bUsed);
	}
}

void ui::CtrlMask::onColorChange()
{
	if (_maskNode)
	{
		_maskNode->setColor(this->getColor());
	}
}
