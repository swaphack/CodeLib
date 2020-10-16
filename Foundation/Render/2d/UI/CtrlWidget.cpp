#include "CtrlWidget.h"
#include "Common/Tool/import.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Fragment/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Input/import.h"

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
	if (!DrawNode2D::init())
	{
		return false;
	}

	// 添加属性改变监听
	_notify->addListen(NodeNotifyType::BODY, [this]() {
		onCtrlWidgetBodyChange();
	});
	
	
 	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setEnabled(true);
	}

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(false);
	}

	getTouchProxy()->addTouchDelegate(TouchType::DOWN, this, TOUCH_DELEGATTE_SELECTOR(CtrlWidget::onBeginTouch));
	getTouchProxy()->addTouchDelegate(TouchType::ON, this, TOUCH_DELEGATTE_SELECTOR(CtrlWidget::onMoveTouch));
	getTouchProxy()->addTouchDelegate(TouchType::UP, this, TOUCH_DELEGATTE_SELECTOR(CtrlWidget::onEndTouch));

	return true; 
}

void render::CtrlWidget::setClip(bool bClip)
{
	_bClip = bClip;
}

bool render::CtrlWidget::isClip()
{
	return _bClip;
}

void render::CtrlWidget::beforeDrawNode()
{
	if (_bClip)
	{
		GLState::enable(EnableMode::SCISSOR_TEST);
		GLState::setScissor(_clipRect.getX(), _clipRect.getY(), _clipRect.getWidth(), _clipRect.getHeight());
	}
}

void render::CtrlWidget::afterDrawNode()
{
	this->drawAllChildren();

	this->drawRect();

	if (_bClip)
	{
		GLState::disable(EnableMode::SCISSOR_TEST);
	}
}

void render::CtrlWidget::addWidget(CtrlWidget* widget)
{
	this->addWidget(widget, 0);
}

void render::CtrlWidget::addWidget(CtrlWidget* widget, int zOrder)
{
	if (widget == nullptr)
	{
		return;
	}

	_widgets.push_back(widget);

	this->addChild(widget, zOrder);
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
	}

	this->removeChild(widget);
}

void render::CtrlWidget::removeAllWidgets()
{
	for (auto item : _widgets)
	{
		this->removeChild(item);
	}
	_widgets.clear();
}

bool render::CtrlWidget::isTouchEnable()
{
	return getTouchProxy()->isTouchEnabled();
}

void render::CtrlWidget::setTouchEnable(bool bEnabled)
{
	getTouchProxy()->setTouchEnabled(bEnabled);
}

void render::CtrlWidget::onBeginTouch(Node* node, float x, float y, bool include)
{
	if (node != this)
	{
		return;
	}

	onTouchBegan(x, y, include);
}

void render::CtrlWidget::onMoveTouch(Node* node, float x, float y, bool include)
{
	if (node != this)
	{
		return;
	}

	onTouchMoved(x, y, include);
}

void render::CtrlWidget::onEndTouch(Node* node, float x, float y, bool include)
{
	if (node != this)
	{
		return;
	}

	onTouchEnded(x, y, include);
}

bool render::CtrlWidget::onTouchBegan(float x, float y, bool include) 
{ 
	return false; 
}

bool render::CtrlWidget::onTouchMoved(float x, float y, bool include) 
{ 
	return false; 
}

bool render::CtrlWidget::onTouchEnded(float x, float y, bool include) 
{ 
	return false;
}

void render::CtrlWidget::onBlendChange()
{
	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setBlendFactor(_blendParam.src, _blendParam.dest);

		pBlend->setBlendColor(_blendColor);
	}
}

void render::CtrlWidget::onCtrlWidgetBodyChange()
{
	float x0 = _realRectPoints.leftDown.getX();
	float y0 = _realRectPoints.leftDown.getY();
	float x1 = _realRectPoints.rightDown.getX();
	float y1 = _realRectPoints.leftUp.getY();

	_clipRect.setOrigin(x0, y0);
	_clipRect.setSize(x1 - x0, y1 - y0);
}

