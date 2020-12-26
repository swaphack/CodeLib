#include "CtrlListView.h"
#include "Layout/LayoutItem.h"
using namespace render;

ui::CtrlListView::CtrlListView()
{
}

ui::CtrlListView::~CtrlListView()
{
}

bool ui::CtrlListView::init()
{
	if (!CtrlScrollView::init())
	{
		return false;
	}
	return true;
}

void ui::CtrlListView::setScrollDirection(ScrollDirection direction)
{
	_scrollDirection = direction;

	notify(NodeNotifyType::GEOMETRY);
}

ui::ScrollDirection ui::CtrlListView::getScrollDirection()
{
	return _scrollDirection;
}

void ui::CtrlListView::setItemSize(const sys::CSSSize& size)
{
	_itemSize = size;

	notify(NodeNotifyType::GEOMETRY);
}

void ui::CtrlListView::setItemSize(float width, float height)
{
	_itemSize.setWidth(sys::NumberType::Fixed, width);
	_itemSize.setHeight(sys::NumberType::Fixed, height);
}

const sys::CSSSize& ui::CtrlListView::getItemSize()
{
	return _itemSize;
}

bool ui::CtrlListView::isUseItemSize() const
{
	return _useItemSize;
}

void ui::CtrlListView::setUseItemSize(bool bUsed)
{
	_useItemSize = bUsed;
}

bool ui::CtrlListView::isShowInCenter() const
{
	return _showInCenter;
}

void ui::CtrlListView::setShowInCenter(bool bCenter)
{
	_showInCenter = bCenter;
}

void ui::CtrlListView::initItems()
{
	if (_scrollItems.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT)
	{
		std::vector<ScrollItem*>::iterator iter = _scrollItems.begin();
		while (iter != _scrollItems.end())
		{
			ScrollItem* pItem = *iter;
			pItem->getLayoutItem()->unsetRightMargin();
			pItem->getLayoutItem()->setLeftMargin(posX);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
	{
		std::vector<ScrollItem*>::iterator iter = _scrollItems.begin();
		while (iter != _scrollItems.end())
		{
			ScrollItem* pItem = *iter;
			pItem->getLayoutItem()->unsetLeftMargin();
			pItem->getLayoutItem()->setRightMargin(posX);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM)
	{
		std::vector<ScrollItem*>::iterator iter = _scrollItems.begin();
		while (iter != _scrollItems.end())
		{
			ScrollItem* pItem = *iter;
			pItem->getLayoutItem()->unsetBottomMargin();
			pItem->getLayoutItem()->setTopMargin(posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY));
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
	{
		std::vector<ScrollItem*>::iterator iter = _scrollItems.begin();
		while (iter != _scrollItems.end())
		{
			ScrollItem* pItem = *iter;
			pItem->getLayoutItem()->unsetTopMargin();
			pItem->getLayoutItem()->setBottomMargin(posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY));
	}
}

void ui::CtrlListView::initContent()
{
	float offX = -getAnchorPoint().getX() * getWidth();
	float offY = -getAnchorPoint().getY() * getHeight();

	if (_showInCenter)
	{
		if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT
			|| _scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
		{
			_content->setPosition(0.5f *(getWidth() - _content->getWidth()) + offX, 0 + offY);
		}
		else if(_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM
			|| _scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
		{
			_content->setPosition(0 + offX, 0.5f * (getHeight() - _content->getHeight()) + offY);
		}
	}
	else
	{
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
}

void ui::CtrlListView::addItem(CtrlWidget* item, int zOrder)
{
	if (item == nullptr)
	{
		return;
	}
	if (_useItemSize)
	{
		CtrlScrollView::addItem(item, _itemSize, zOrder);
	}
	else
	{
		CtrlScrollView::addItem(item, item->getSize(), zOrder);
	}
}

bool ui::CtrlListView::onTouchMoved(float x, float y, bool include)
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
