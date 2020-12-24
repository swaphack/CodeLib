#include "CtrlWidget.h"
#include "Layout/LayoutItem.h"

#define PROTECTED_ZORDER -999

using namespace render;

ui::CtrlWidget::CtrlWidget()
{
	this->resetLayoutItem();
}

ui::CtrlWidget::~CtrlWidget()
{
	SAFE_RELEASE(_layoutItem);

	this->removeAllProtectedWidgets();
	this->removeAllWidgets();
}

bool ui::CtrlWidget::init()
{
	if (!DrawNode2D::init())
	{
		return false;
	}

	// ������Ըı����
	_notify->addListen(NodeNotifyType::BODY, [this]() {
		onCtrlWidgetBodyChange();

		broadcastBodyChange();
	});

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(false);
	}

	return true; 
}

void ui::CtrlWidget::setClip(bool bClip)
{
	_bClip = bClip;
}

bool ui::CtrlWidget::isClip()
{
	return _bClip;
}

void ui::CtrlWidget::beforeDrawNode()
{
	if (_bClip)
	{
		GLState::enable(EnableMode::SCISSOR_TEST);
		GLState::setScissor(_clipRect.getX(), _clipRect.getY(), _clipRect.getWidth(), _clipRect.getHeight());
	}
}

void ui::CtrlWidget::afterDrawNode()
{
	this->drawAllChildren();

	this->drawRect();

	if (_bClip)
	{
		GLState::disable(EnableMode::SCISSOR_TEST);
	}
}

void ui::CtrlWidget::addWidget(CtrlWidget* widget)
{
	this->addWidget(widget, 0);
}

void ui::CtrlWidget::addWidget(CtrlWidget* widget, int zOrder)
{
	if (widget == nullptr)
	{
		return;
	}

	_widgets.push_back(widget);

	this->addChild(widget, zOrder);
}

void ui::CtrlWidget::removeWidget(CtrlWidget* widget)
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

void ui::CtrlWidget::removeAllWidgets()
{
	for (auto item : _widgets)
	{
		this->removeChild(item);
	}
	_widgets.clear();
}

ui::CtrlWidget* ui::CtrlWidget::findWidgetByName(const std::string& name)
{
	if (this->getName() == name)
	{
		return this;
	}
	for (auto item : _widgets)
	{
		if (item->getName() == name)
		{
			return item;
		}

		auto target = item->findWidgetByName(name);
		if (target != nullptr)
		{
			return target;
		}
	}

	return nullptr;
}

const std::vector<ui::CtrlWidget*>& ui::CtrlWidget::getAllWidgets() const
{
	return _widgets;
}

ui::CtrlWidget* ui::CtrlWidget::getFirstWidget() const
{
	if (_widgets.size() == 0)
	{
		return nullptr;
	}
	return _widgets[0];
}

void ui::CtrlWidget::removeFromParent()
{
	if (this->getParent() == nullptr)
	{
		return;
	}

	if (this->getParent()->is<CtrlWidget>())
	{
		this->getParent()->as<CtrlWidget>()->removeWidget(this);
	}
	else if (this->getParent()->is<Node>())
	{
		this->getParent()->as<Node>()->removeChild(this);
	}

	this->setParent(nullptr);
}

void ui::CtrlWidget::setLayoutItem(LayoutItem* item)
{
	SAFE_RETAIN(item);
	SAFE_RELEASE(_layoutItem);
	_layoutItem = item;

	if (item)
	{
		item->setWidget(this);
	}
}

void ui::CtrlWidget::resetLayoutItem()
{
	auto layoutItem = LayoutItem::create();
	this->setLayoutItem(layoutItem);
}

ui::LayoutItem* ui::CtrlWidget::getLayoutItem()
{
	return _layoutItem;
}

void ui::CtrlWidget::resize(const math::Size& size)
{
	if (_layoutItem != nullptr)
	{
		_layoutItem->resize(size);
	}
}

bool ui::CtrlWidget::isTouchEnable()
{
	if (getTouchProxy() == nullptr)
	{
		return false;
	}
	return getTouchProxy()->isTouchEnabled();
}

void ui::CtrlWidget::setTouchEnable(bool bEnabled)
{
	if (bEnabled)
	{
		if (_touchProxy == nullptr)
		{
			getTouchProxy()->setTouchEnabled(bEnabled);
			getTouchProxy()->addTouchDelegate(TouchType::DOWN, this, TOUCH_DELEGATTE_SELECTOR(CtrlWidget::onBeginTouch));
			getTouchProxy()->addTouchDelegate(TouchType::ON, this, TOUCH_DELEGATTE_SELECTOR(CtrlWidget::onMoveTouch));
			getTouchProxy()->addTouchDelegate(TouchType::UP, this, TOUCH_DELEGATTE_SELECTOR(CtrlWidget::onEndTouch));
		}
	}
	else if (_touchProxy)
	{
		getTouchProxy()->removeAllTouchDelegates();
		getTouchProxy()->setTouchEnabled(false);
		SAFE_RELEASE(_touchProxy);
		_touchProxy = nullptr;
	}
}

void ui::CtrlWidget::addClickFunc(const ClickWidgetFunc& func)
{
	_clickFuncs.push_back(func);
}

void ui::CtrlWidget::removeAllClickFuncs()
{
	_clickFuncs.clear();
}

void ui::CtrlWidget::onBeginTouch(Node* node, float x, float y, bool include)
{
	if (node != this)
	{
		return;
	}

	onTouchBegan(x, y, include);
}

void ui::CtrlWidget::onMoveTouch(Node* node, float x, float y, bool include)
{
	if (node != this)
	{
		return;
	}

	onTouchMoved(x, y, include);
}

void ui::CtrlWidget::onEndTouch(Node* node, float x, float y, bool include)
{
	if (node != this)
	{
		return;
	}

	onTouchEnded(x, y, include);
}

bool ui::CtrlWidget::onTouchBegan(float x, float y, bool include) 
{ 
	return include;
}

bool ui::CtrlWidget::onTouchMoved(float x, float y, bool include) 
{ 
	if (!include)
	{
		return false;
	}
	return true;
}

bool ui::CtrlWidget::onTouchEnded(float x, float y, bool include) 
{ 
	if (!include)
	{
		return false;
	}
	for (auto item : _clickFuncs)
	{
		item(this);
	}
	return true;
}

void ui::CtrlWidget::onCtrlWidgetBodyChange()
{
	float x0 = _realRectPoints.leftDown.getX();
	float y0 = _realRectPoints.leftDown.getY();
	float x1 = _realRectPoints.rightDown.getX();
	float y1 = _realRectPoints.leftUp.getY();

	_clipRect.setOrigin(x0, y0);
	_clipRect.setSize(x1 - x0, y1 - y0);
}

void ui::CtrlWidget::broadcastBodyChange()
{
	for (auto item : _protectedWidgets)
	{
		item->onParentBodyChange();
	}

	for (auto item : _widgets)
	{
		item->onParentBodyChange();
	}
}

void ui::CtrlWidget::refreshLayout()
{
	onParentBodyChange();
}

void ui::CtrlWidget::onParentBodyChange()
{
	if (getParent() != nullptr)
	{
		if (_layoutItem)
		{
			_layoutItem->resize(getParent()->getSize());
		}
	}

	//broadcastBodyChange();
}

void ui::CtrlWidget::addProtectedWidget(CtrlWidget* widget)
{
	if (widget == nullptr)
	{
		return;
	}

	_protectedWidgets.push_back(widget);

	this->addChild(widget, PROTECTED_ZORDER);
}

void ui::CtrlWidget::removeProtectedWidget(CtrlWidget* widget)
{
	if (widget == nullptr)
	{
		return;
	}

	auto it = std::find(_protectedWidgets.begin(), _protectedWidgets.end(), widget);
	if (it != _widgets.end())
	{
		_protectedWidgets.erase(it);
	}

	this->removeChild(widget);
}

void ui::CtrlWidget::removeAllProtectedWidgets()
{
	for (auto item : _protectedWidgets)
	{
		this->removeChild(item);
	}
	_protectedWidgets.clear();
}

