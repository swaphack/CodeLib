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

render::DrawNode2D* ui::CtrlMask::getRenderNode()
{
	return _maskNode;
}

void ui::CtrlMask::onColorChange()
{
	if (_maskNode)
	{
		_maskNode->setColor(this->getColor());
	}
}
