#include "CtrlListView.h"

render::CtrlListView::CtrlListView()
{
}

render::CtrlListView::~CtrlListView()
{
}

bool render::CtrlListView::init()
{
	if (!CtrlScrollView::init())
	{
		return false;
	}
	return true;
}

void render::CtrlListView::setScrollDirection(ScrollDirection direction)
{
	_scrollDirection = direction;

	notify(NodeNotifyType::GEOMETRY);
}

render::ScrollDirection render::CtrlListView::getScrollDirection()
{
	return _scrollDirection;
}

void render::CtrlListView::setItemSize(const math::Size& size)
{
	_itemSize = size;

	notify(NodeNotifyType::GEOMETRY);
}

void render::CtrlListView::setItemSize(float width, float height)
{
	_itemSize.set(width, height);
}

const math::Size& render::CtrlListView::getItemSize()
{
	return _itemSize;
}

void render::CtrlListView::initItems()
{
	if (_itemWidgets.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT)
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
	}
	else if (_scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
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
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM)
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
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
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
	}
}

void render::CtrlListView::initContent()
{
	float offX = -getAnchorPoint().getX() * getWidth();
	float offY = -getAnchorPoint().getY() * getHeight();

	if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT)
	{
		_content->setPosition(0 + offX, 0 + offY);
	}
	else if (_scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
	{
		_content->setPosition(getWidth() - _content->getWidth() + offX, 0 + offY);
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM)
	{
		_content->setPosition(0 + offX, getHeight() - _content->getHeight() + offY);
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
	{
		_content->setPosition(0 + offX, 0 + offY);
	}
}

void render::CtrlListView::addItem(CtrlWidget* item, int zOrder)
{
	CtrlScrollView::addItem(item, _itemSize, zOrder);
}

bool render::CtrlListView::onTouchMoved(float x, float y, bool include)
{

	math::Vector2 delta = math::Vector2(x, y);
	delta -= _touchPosition;

	float offX = -getAnchorPoint().getX() * getWidth();
	float offY = -getAnchorPoint().getY() * getHeight();

	math::Vector3 pos = _content->getPosition();

	float min = 0;
	float max = 0;
	
	if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT)
	{
		if (!_bHorizontalScroll) return false;

		pos.setX(pos.getX() + delta.getX());
		min = getWidth() - _content->getWidth() + offX;
		max = 0 + offX;
		if (pos.getX() < min) pos.setX(min);
		if (pos.getX() > max) pos.setX(max);
	}
	else if (_scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
	{
		if (!_bHorizontalScroll) return false;

		pos.setX(pos.getX() + delta.getX());
		min = getWidth() - _content->getWidth() + offX;
		max = 0 + offX;
		if (pos.getX() < min) pos.setX(min);
		if (pos.getX() > max) pos.setX(max);
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM)
	{
		if (!_bVerticalScroll) return false;

		pos.setY(pos.getY() + delta.getY());
		min = getHeight() - _content->getHeight() + offY;
		max = 0 + offY;
		if (pos.getY() < min) pos.setY(min);
		if (pos.getY() > max) pos.setY(max);
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
	{
		if (!_bVerticalScroll) return false;

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
