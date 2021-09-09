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

void ui::CtrlMask::onColorChange()
{
	if (_maskNode)
	{
		_maskNode->setColor(this->getColor());
	}
}
