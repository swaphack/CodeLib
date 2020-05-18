#include "CtrlWidget.h"
#include "Common/Tool/import.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Fragment/import.h"
#include "Common/DrawNode/import.h"

using namespace render;

render::CtrlWidget::CtrlWidget()
{
}

render::CtrlWidget::~CtrlWidget()
{
	this->removeAllWidgets();
}

bool render::CtrlWidget::init()
{
	if (!DrawNode::init())
	{
		return false;
	}
	// 添加属性改变监听
	_notify->addListen(NodeNotifyType::SPACE, [this](){
		calRectData();
	});

	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setEnabled(true);
	}

	return true; 
}

void render::CtrlWidget::setClip(bool bClip)
{
	_bClip = bClip;
}

void render::CtrlWidget::updateNode()
{
	this->updateWidget();

	DrawNode::updateNode();
}

void render::CtrlWidget::drawNode()
{
	if (_bClip)
	{
		GLState::enable(EnableModel::SCISSOR_TEST);
		GLState::setScissor(_clipRect.getX(), _clipRect.getY(), _clipRect.getWidth(), _clipRect.getHeight());
	}

	this->drawWidget();

	DrawNode::drawNode();

	if (_bClip)
	{
		GLState::disable(EnableModel::SCISSOR_TEST);
	}
}

void render::CtrlWidget::updateWidget()
{
	for (auto item : _widgets)
	{
		item->updateNode();
	}
}

void render::CtrlWidget::drawWidget()
{
	for (auto item : _widgets)
	{
		item->drawNode();
	}
}

void render::CtrlWidget::addWidget(CtrlWidget* widget)
{
	if (widget == nullptr)
	{
		return;
	}

	SAFE_RETAIN(widget);

	_widgets.push_back(widget);
}

void render::CtrlWidget::removeWidget(CtrlWidget* widget)
{
	if (widget == nullptr)
	{
		return;
	}

	auto it = std::find(_widgets.begin(), _widgets.end(), widget);
	if (it != _widgets.end())
	{
		_widgets.erase(it);
		SAFE_RELEASE(widget);
	}
}

void render::CtrlWidget::removeAllWidgets()
{
	for (auto item : _widgets)
	{
		SAFE_RELEASE(item);
	}
}

const render::RectVectices& render::CtrlWidget::getRectVertex()
{
	return _rectVertex;
}

bool render::CtrlWidget::containTouchPoint(float x, float y)
{
	return _realRectVertex.containPoint(x, y);
}

void render::CtrlWidget::calRectData()
{
	Tool::calRect(math::Vector3(), _volume, _anchor, _rectVertex);

	_realRectVertex.leftDown = this->convertLocalPostitionToWorld(_rectVertex.leftDown);
	_realRectVertex.rightDown = this->convertLocalPostitionToWorld(_rectVertex.rightDown);
	_realRectVertex.rightUp = this->convertLocalPostitionToWorld(_rectVertex.rightUp);
	_realRectVertex.leftUp = this->convertLocalPostitionToWorld(_rectVertex.leftUp);

	float x0 = _realRectVertex.leftDown.getX();
	float y0 = _realRectVertex.leftDown.getY();
	float x1 = _realRectVertex.rightDown.getX();
	float y1 = _realRectVertex.leftUp.getY();

	_clipRect.setOrigin(x0, y0);
	_clipRect.setSize(x1 - x0, y1 - y0);
}

void render::CtrlWidget::onColorChange()
{
	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		sys::Color4F color;
		convertColor4BTo4F(_color, color);
		pBlend->setBlendColor(color);
	}
}

void render::CtrlWidget::onBlendChange()
{
	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setBlendFactor(_blendParam.src, _blendParam.dest);
	}
}

