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

void CtrlScrollView::setScrollDirection(ScrollDirection direction)
{
	if (_scrollDirection != direction)
	{
		_scrollDirection = direction;
		initItems();
		initContent();
	}
}

ScrollDirection CtrlScrollView::getScrollDirection()
{
	return _scrollDirection;
}

void CtrlScrollView::addItem(CtrlWidget* item, int zOrder)
{
	if (item == nullptr)
	{
		return;
	}
	
	this->addItem(item, _itemSize, zOrder);
}

void CtrlScrollView::addItem(CtrlWidget* item, const math::Size& size, int zOrder)
{
	if (item == nullptr)
	{
		return;
	}

	assert(size.getWidth() != 0 && size.getHeight() != 0);
	
	ScrollItem* pScrollItem = ScrollItem::create(item, size);
	_content->addWidget(pScrollItem, zOrder);
	_itemWidgets.push_back(pScrollItem);

	initItems();
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

	initItems();
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
	initItems();
}


void CtrlScrollView::setItemSize(const math::Size& size)
{
	_itemSize = size;
}

void CtrlScrollView::setItemSize(float width, float height)
{
	_itemSize.set(width, height);
}

const math::Size& CtrlScrollView::getItemSize()
{
	return _itemSize;
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

bool CtrlScrollView::onTouchMoved(float x, float y, bool include)
{
	math::Vector2 delta = math::Vector2(x, y);
	delta-=_touchPosition;

	float offX = -getAnchorPoint().getX() * getWidth();
	float offY = -getAnchorPoint().getY() * getHeight();

	math::Vector3 pos = _content->getPosition();

	float min = 0;
	float max = 0;

	switch (_scrollDirection)
	{
	case ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT:
	{
		pos.setX(pos.getX() + delta.getX());
		min = getWidth() - _content->getWidth() + offX;
		max = 0 + offX;
		if (pos.getX() < min) pos.setX(min);
		if (pos.getX() > max) pos.setX(max);
		break;
	}
	case ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT:
	{
		pos.setX(pos.getX() + delta.getX());
		min = getWidth() - _content->getWidth() + offX;
		max = 0 + offX;
		if (pos.getX() < min) pos.setX(min);
		if (pos.getX() > max) pos.setX(max);
		break;
	}
	case ScrollDirection::VERTICAL_TOP_TO_BOTTOM:
	{
		pos.setY(pos.getY() + delta.getY());
		min = getHeight() - _content->getHeight() + offY;
		max = 0 + offY;
		if (pos.getY() < min) pos.setY(min);
		if (pos.getY() > max) pos.setY(max);
		break;
	}
	case ScrollDirection::VERTICAL_BOTTOM_TO_TOP:
	{
		pos.setY(pos.getY() + delta.getY());
		min = getHeight() - _content->getHeight() + offY;
		max = 0 + offY;
		if (pos.getY() < min) pos.setY(min);
		if (pos.getY() > max) pos.setY(max);
		break;
	}
	default:
		break;
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
	if (_scrollDirection == ScrollDirection::NONE)
	{
		return;
	}
	if (_itemWidgets.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	switch (_scrollDirection)
	{
	case ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT:
	{
		std::vector<CtrlWidget*>::iterator iter = _itemWidgets.begin();
		while (iter != _itemWidgets.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
		break;
	}
	case ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT:
	{
		std::vector<CtrlWidget*>::reverse_iterator iter = _itemWidgets.rbegin();
		while (iter != _itemWidgets.rend())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
		break;
	}
	case ScrollDirection::VERTICAL_TOP_TO_BOTTOM:
	{
		std::vector<CtrlWidget*>::iterator iter = _itemWidgets.begin();
		while (iter != _itemWidgets.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY));
		break;
	}
	case ScrollDirection::VERTICAL_BOTTOM_TO_TOP:
	{
		std::vector<CtrlWidget*>::reverse_iterator iter = _itemWidgets.rbegin();
		while (iter != _itemWidgets.rend())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPosition(posX, posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY));
		break;
	}
	default:
		break;
	}
}

void CtrlScrollView::initContent()
{
	float offX = -getAnchorPoint().getX() * getWidth();
	float offY = -getAnchorPoint().getY() * getHeight();

	switch (_scrollDirection)
	{
	case ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT:
		_content->setPosition(0 + offX, 0 + offY);
		break;
	case ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT:
		_content->setPosition(getWidth() - _content->getWidth() + offX, 0 + offY);
		break;
	case ScrollDirection::VERTICAL_TOP_TO_BOTTOM:
		_content->setPosition(0 + offX, getHeight() - _content->getHeight() + offY);
		break;
	case ScrollDirection::VERTICAL_BOTTOM_TO_TOP:
		_content->setPosition(0 + offX, 0 + offY);
		break;
	default:
		break;
	}
}