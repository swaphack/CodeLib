#include "CtrlWidget.h"
#include "Layout/LayoutItem.h"
#include "Common/View/Cameras.h"
#define PROTECTED_ZORDER -999

using namespace render;

int ui::CtrlWidget::s_nScissorCount = 0;

ui::CtrlWidget::CtrlWidget()
{
	this->setBoxNode(this);
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
	if (!Node::init())
	{
		return false;
	}

	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::SPACE, [this]() {
		onCtrlWidgetWorldBodyChange();
	});

	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::BODY, [this]() {
		onCtrlWidgetBodyChange();

		broadcastBodyChange();
	});

	this->addTouchFunc(render::TouchType::ENDED, [this](const math::Vector2& touchPoint) {
		for (auto item : _clickFuncs)
		{
			item(this);
		}
	});
	/*
	this->addTouchFunc(render::TouchType::CANCELED, [this](const math::Vector2& touchPoint) {
		_clickFuncs.clear();
	});
	*/
	this->setCamera(G_CAMERAS->getCamera2D());
	return true; 
}

void ui::CtrlWidget::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
}

void ui::CtrlWidget::setColorShaderProgram(render::ShaderProgram* shaderProgram)
{
}

bool ui::CtrlWidget::containPoint(const math::Vector2& touchPoint)
{
	math::Polygon rect = _worldRectVertex;
	return rect.contains(touchPoint);
}

void ui::CtrlWidget::beforeDrawNode()
{
	if (isClippingEnabled())
	{
		if (s_nScissorCount == 0)
		{
			GLState::enable(EnableMode::SCISSOR_TEST);
		}

		GLState::setScissor(_clipRect.getX(), _clipRect.getY(), _clipRect.getWidth(), _clipRect.getHeight());
		
		s_nScissorCount++;
	}
}

void ui::CtrlWidget::afterDrawNode()
{
	this->drawAllChildren();

	if (isClippingEnabled())
	{
		if (s_nScissorCount > 0)
		{
			s_nScissorCount--;
			if (s_nScissorCount == 0)
			{
				GLState::disable(EnableMode::SCISSOR_TEST);
			}
		}
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
		auto pParent = static_cast<CtrlWidget*>(this->getParent());
		pParent->removeWidget(this);
	}
	else if (this->getParent()->is<Node>())
	{
		auto pParent = static_cast<Node*>(this->getParent());

		pParent->removeChild(this);
	}

	this->setParent(nullptr);
}

int ui::CtrlWidget::getWidgetCount() const
{
	return _widgets.size();
}

ui::CtrlWidget* ui::CtrlWidget::getWidgetByIndex(int index) const
{
	if (index < 0 || index >= _widgets.size())
	{
		return nullptr;
	}

	return _widgets.at(index);
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

ui::LayoutItem* ui::CtrlWidget::getLayoutItem() const
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

void ui::CtrlWidget::addClickFunc(const ClickWidgetFunc& func)
{
	_clickFuncs.push_back(func);
}

void ui::CtrlWidget::removeAllClickFuncs()
{
	_clickFuncs.clear();
}

void ui::CtrlWidget::onCtrlWidgetBodyChange()
{
	VertexTool::setTexture2DVertices(&_localRectVertex, math::Vector3(), _volume, _anchor);

	onCtrlWidgetWorldBodyChange();
}

void ui::CtrlWidget::onCtrlWidgetWorldBodyChange()
{
	_worldRectVertex.setLeftBottomPosition(this->convertLocalPostitionToWorld(_localRectVertex.getLeftBottomPosition()));
	_worldRectVertex.setRightBottomPosition(this->convertLocalPostitionToWorld(_localRectVertex.getRightBottomPosition()));
	_worldRectVertex.setRightTopPosition(this->convertLocalPostitionToWorld(_localRectVertex.getRightTopPosition()));
	_worldRectVertex.setLeftTopPosition(this->convertLocalPostitionToWorld(_localRectVertex.getLeftTopPosition()));

	setBoxVertices(_worldRectVertex);

	math::Vector2 pos0 = _worldRectVertex.getLeftBottomPosition();
	math::Vector2 pos1 = _worldRectVertex.getRightTopPosition();

	_clipRect.setOrigin(pos0 + 0.5f * math::Vector2(Tool::getGLViewWidth(), Tool::getGLViewHeight()));
	_clipRect.setSize(pos1 - pos0);
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

