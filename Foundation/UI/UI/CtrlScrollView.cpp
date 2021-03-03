#include "CtrlScrollView.h"
#include "Common/Input/TouchManager.h"
#include "Layout/LayoutItem.h"
#include <cassert>
using namespace ui;
using namespace render;

ScrollItem::ScrollItem()
{
	this->setAnchorPoint(0, 0);
}

ScrollItem::~ScrollItem()
{

}

void ScrollItem::addItem(CtrlWidget* node, const sys::CSSSize& size)
{
	if (node == nullptr)
	{
		return;
	}

	this->addWidget(node);

	auto pLayoutItem = node->getLayoutItem();
	pLayoutItem->setSize(size);
	this->setLayoutItem(pLayoutItem);

	node->resetLayoutItem();
}

void ui::ScrollItem::setScrollView(CtrlScrollView* view)
{
	_relativeView = view;
}

const CtrlScrollView* ui::ScrollItem::getScrollView() const
{
	return _relativeView;
}

void ui::ScrollItem::removeWidget(CtrlWidget* item)
{
	if (item == nullptr || _relativeView == nullptr) return;
	if (this->indexOfChild(item) != 0) return;

	_relativeView->removeWidget(item);
}

ScrollItem* ScrollItem::create(CtrlWidget* node, const sys::CSSSize& size, CtrlScrollView* view)
{
	ScrollItem* item = CREATE_NODE(ScrollItem);
	if (item)
	{
		item->setScrollView(view);
		item->addItem(node, size);
	}

	return item;
}


//////////////////////////////////////////////////////////////////////////
CtrlScrollView::CtrlScrollView()
{
	_content = CREATE_NODE(CtrlLayout);
	_content->getLayoutItem()->unsetMarginState();
	CtrlWidget::addWidget(_content, 0);

	this->setTouchSwallowed(true);
}

CtrlScrollView::~CtrlScrollView()
{

}

bool ui::CtrlScrollView::init()
{
	if (!CtrlLayout::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->initItems();
		this->initContent();
	});

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->initItems();
		this->initContent();
	});


	this->addTouchFunc(render::TouchType::BEGAN, [this](const math::Vector2& touchPoint) {

		_touchPosition = touchPoint;

	});
	this->addTouchFunc(render::TouchType::MOVED, [this](const math::Vector2& touchPoint) {
		if (!_bHorizontalScroll && !_bVerticalScroll) return;

		math::Vector2 delta = touchPoint;
		delta -= _touchPosition;

		delta *= getMovingMultiple();

		float offX = -getAnchorPoint().getX() * getWidth();
		float offY = -getAnchorPoint().getY() * getHeight();

		math::Vector3 pos = _content->getPosition();

		float min = 0;
		float max = 0;

		if (_bHorizontalScroll)
		{
			pos.setX(pos.getX() + delta.getX());
			min = getWidth() - _content->getWidth() + offX;
			max = 0 + offX;
			if (pos.getX() < min) pos.setX(min);
			if (pos.getX() > max) pos.setX(max);
		}

		if (_bVerticalScroll)
		{
			pos.setY(pos.getY() + delta.getY());

			min = getHeight() - _content->getHeight() + offY;
			max = 0 + offY;
			if (pos.getY() < min) pos.setY(min);
			if (pos.getY() > max) pos.setY(max);
		}

		_content->setPosition(pos);

		_touchPosition = touchPoint;
	});


	return true;
}



void CtrlScrollView::addItem(CtrlWidget* item, int zOrder)
{
	if (item == nullptr)
	{
		return;
	}
	
	this->addItem(item, item->getSize(), zOrder);
}

void CtrlScrollView::addItem(CtrlWidget* item, const math::Size& size, int zOrder)
{
	if (item == nullptr)
	{
		return;
	}

	sys::CSSSize layoutSize;
	layoutSize.setWidth(sys::NumberType::Fixed, size.getWidth());
	layoutSize.setHeight(sys::NumberType::Fixed, size.getHeight());

	addItem(item, layoutSize, zOrder);
}

void ui::CtrlScrollView::addItem(CtrlWidget* item, const sys::CSSSize& size, int zOrder)
{
	if (item == nullptr)
	{
		return;
	}
	ScrollItem* pScrollItem = ScrollItem::create(item, size, this);
	_content->addWidget(pScrollItem, zOrder);
	_scrollItems.push_back(pScrollItem);

	notify(NodeNotifyType::GEOMETRY);
}

void CtrlScrollView::removeItem(CtrlWidget* item)
{
	if (item == nullptr)
	{
		return;
	}
	
	std::vector<ScrollItem*>::iterator iter = _scrollItems.begin();
	while (iter != _scrollItems.end())
	{
		if ((*iter)->getFirstChild() == item)
		{
			_content->removeWidget(*iter);
			_scrollItems.erase(iter);
			break;
		}
		iter++;
	}

	notify(NodeNotifyType::GEOMETRY);
}

void CtrlScrollView::removeAllItems()
{
	std::vector<ScrollItem*>::iterator iter = _scrollItems.begin();
	while (iter != _scrollItems.end())
	{
		(*iter)->removeAllWidgets();
		(*iter)->removeFromParent();
		iter++;
	}

	_scrollItems.clear();
	notify(NodeNotifyType::GEOMETRY);
}

int ui::CtrlScrollView::getItemCount() const
{
	return _scrollItems.size();
}

ui::CtrlWidget* ui::CtrlScrollView::getItemByIndex(int index) const
{
	if (index < 0 || index > getItemCount())
	{
		return nullptr;
	}

	auto pScrollItem = _scrollItems.at(index);
	if (pScrollItem == nullptr) return nullptr;

	return pScrollItem->getFirstWidget();
}

CtrlWidget* ui::CtrlScrollView::findItemByName(const std::string& name) const
{
	for (size_t i = 0; i < _scrollItems.size(); i++)
	{
		auto pWidget = _scrollItems.at(i)->getFirstWidget();
		if (pWidget->getName() == name)
		{
			return pWidget;
		}
	}

	return nullptr;
}

bool ui::CtrlScrollView::isHorizontalScroll() const
{
	return _bHorizontalScroll;
}

void ui::CtrlScrollView::setHorizontalScroll(bool scroll)
{
	_bHorizontalScroll = scroll;
}

bool ui::CtrlScrollView::isVerticalScroll() const
{
	return _bVerticalScroll;
}

void ui::CtrlScrollView::setVerticalScroll(bool scroll)
{
	_bVerticalScroll = scroll;
}

void ui::CtrlScrollView::addWidget(CtrlWidget* item)
{
	this->addItem(item);
}

void ui::CtrlScrollView::addWidget(CtrlWidget* item, int zOrder)
{
	this->addItem(item, zOrder);
}

void ui::CtrlScrollView::removeWidget(CtrlWidget* item)
{
	this->removeItem(item);
}

void ui::CtrlScrollView::removeAllWidgets()
{
	this->removeAllItems();
}

void CtrlScrollView::initItems()
{
	
}

void CtrlScrollView::initContent()
{
	
}

void CtrlScrollView::setInnerSize(const math::Size& size)
{
	if (_content != nullptr)
	{
		_content->setVolume(size);
	}
}

math::Size CtrlScrollView::getInnerSize()
{
	if (_content != nullptr) return _content->getSize();
	else return math::Size();
}

const CtrlLayout* CtrlScrollView::getInner() const
{
	return _content;
}

void ui::CtrlScrollView::setMovingMultiple(float value)
{
	_movingMultiple = value;
}

float ui::CtrlScrollView::getMovingMultiple() const
{
	return _movingMultiple;
}
