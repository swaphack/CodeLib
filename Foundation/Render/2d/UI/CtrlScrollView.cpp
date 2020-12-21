#include "CtrlScrollView.h"
#include "Common/Input/TouchProxy.h"
#include "Common/Input/TouchManager.h"
#include <cassert>
using namespace render;

ScrollItem::ScrollItem()
{
	this->setAnchorPoint(0, 0);
}

ScrollItem::~ScrollItem()
{

}

void ScrollItem::addItem(Node* node, const math::Size& size)
{
	if (node == nullptr)
	{
		return;
	}
	node->setAnchorPoint(0.5f, 0.5f);
	node->setPosition(size.getWidth() * 0.5f, size.getHeight() * 0.5f);
	this->addChild(node);
	this->setVolume(size.getWidth(), size.getHeight());
}

ScrollItem* ScrollItem::create(Node* node, const math::Size& size)
{
	ScrollItem* item = CREATE_NODE(ScrollItem);
	if (item)
	{
		item->addItem(node, size);
	}

	return item;
}


//////////////////////////////////////////////////////////////////////////
CtrlScrollView::CtrlScrollView()
{
	_content = CREATE_NODE(CtrlLayout);
	this->addChild(_content);
}

CtrlScrollView::~CtrlScrollView()
{

}

bool render::CtrlScrollView::init()
{
	if (!CtrlLayout::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::GEOMETRY, [this]() {
		this->initItems();
		this->initContent();
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

	auto itemSize = item->getSize();

	if (size.getWidth() != 0 || size.getHeight() != 0)
	{
		itemSize = size;
	}	

	ScrollItem* pScrollItem = ScrollItem::create(item, itemSize);
	_content->addWidget(pScrollItem, zOrder);
	_itemWidgets.push_back(pScrollItem);

	notify(NodeNotifyType::GEOMETRY);
}

void CtrlScrollView::removeItem(CtrlWidget* item)
{
	if (item == nullptr)
	{
		return;
	}
	
	std::vector<CtrlWidget*>::iterator iter = _itemWidgets.begin();
	while (iter != _itemWidgets.end())
	{
		if ((*iter)->getFirstChild() == item)
		{
			_itemWidgets.erase(iter);
			_content->removeChild(*iter);
			break;
		}
		iter++;
	}

	notify(NodeNotifyType::GEOMETRY);
}

void CtrlScrollView::removeAllItems()
{
	std::vector<CtrlWidget*>::iterator iter = _itemWidgets.begin();
	while (iter != _itemWidgets.end())
	{
		(*iter)->release();
		iter++;
	}

	_itemWidgets.clear();
	notify(NodeNotifyType::GEOMETRY);
}

bool render::CtrlScrollView::isHorizontalScroll() const
{
	return _bHorizontalScroll;
}

void render::CtrlScrollView::setHorizontalScroll(bool scroll)
{
	_bHorizontalScroll = scroll;
}

bool render::CtrlScrollView::isVerticalScroll() const
{
	return _bVerticalScroll;
}

void render::CtrlScrollView::setVerticalScroll(bool scroll)
{
	_bVerticalScroll = scroll;
}

void render::CtrlScrollView::addWidget(CtrlWidget* item)
{
	this->addItem(item);
}

void render::CtrlScrollView::addWidget(CtrlWidget* item, int zOrder)
{
	this->addItem(item, zOrder);
}

void render::CtrlScrollView::removeWidget(CtrlWidget* item)
{
	this->removeItem(item);
}

void render::CtrlScrollView::removeAllWidgets()
{
	this->removeAllItems();
}

bool CtrlScrollView::onTouchBegan(float x, float y, bool include)
{
	_touchPosition.set(x, y);

	return true;
}

bool render::CtrlScrollView::onTouchMoved(float x, float y, bool include)
{
	if (!_bHorizontalScroll && !_bVerticalScroll) return false;

	math::Vector2 delta = math::Vector2(x, y);
	delta -= _touchPosition;

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

	_touchPosition = math::Vector2(x, y);

	return true;
}


bool CtrlScrollView::onTouchEnded(float x, float y, bool include)
{
	return true;
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