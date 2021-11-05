#include "CtrlListView.h"
#include "Layout/LayoutItem.h"
using namespace render;

ui::CtrlListView::CtrlListView()
{
	_scrollDirection = ScrollDirection::LeftToRight;
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
	if (_scrollWidgets.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	if (_scrollDirection == ScrollDirection::LeftToRight)
	{
		for (auto& item : _scrollWidgets)
		{
			item->getLayoutItem()->unsetRightMargin();
			item->getLayoutItem()->setLeftMargin(posX);
			posX += item->getWidth();
		}
		_content->setVolume(abs(posX), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::RightToLeft)
	{
		for (auto& item : _scrollWidgets)
		{
			item->getLayoutItem()->unsetLeftMargin();
			item->getLayoutItem()->setRightMargin(posX);
			posX += item->getWidth();
		}
		_content->setVolume(abs(posX), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::TopToBottom)
	{
		for (auto& item : _scrollWidgets)
		{
			item->getLayoutItem()->unsetBottomMargin();
			item->getLayoutItem()->setTopMargin(posY);
			posY += item->getHeight();
		}
		_content->setVolume(getWidth(), abs(posY));
	}
	else if (_scrollDirection == ScrollDirection::BottomToTop)
	{
		for (auto& item : _scrollWidgets)
		{
			item->getLayoutItem()->unsetTopMargin();
			item->getLayoutItem()->setBottomMargin(posY);
			posY += item->getHeight();
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
		if (_scrollDirection == ScrollDirection::LeftToRight
			|| _scrollDirection == ScrollDirection::RightToLeft)
		{
			_content->setPosition(0.5f *(getWidth() - _content->getWidth()) + offX, 0 + offY);
		}
		else if(_scrollDirection == ScrollDirection::TopToBottom
			|| _scrollDirection == ScrollDirection::BottomToTop)
		{
			_content->setPosition(0 + offX, 0.5f * (getHeight() - _content->getHeight()) + offY);
		}
	}
	else
	{
		if (_scrollDirection == ScrollDirection::LeftToRight)
		{
			_content->setPosition(0 + offX, 0 + offY);
		}
		else if (_scrollDirection == ScrollDirection::RightToLeft)
		{
			_content->setPosition(getWidth() - _content->getWidth() + offX, 0 + offY);
		}
		else if (_scrollDirection == ScrollDirection::TopToBottom)
		{
			_content->setPosition(0 + offX, getHeight() - _content->getHeight() + offY);
		}
		else if (_scrollDirection == ScrollDirection::BottomToTop)
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
		CtrlScrollView::addItem(item, item->getLayoutItem()->getSize(), zOrder);
	}
}

void ui::CtrlListView::handMovedTouch(const math::Vector2& touchPoint)
{
	math::Vector2 delta = touchPoint;
	delta -= _touchPosition;

	delta *= getMovingMultiple();

	math::Vector3 pos = _content->getPosition();

	float min = 0;
	float max = 0;

	if (_scrollDirection == ScrollDirection::LeftToRight)
	{
		if (!_bHorizontalScroll) return;

		pos.setX(pos.getX() + delta.getX());
		if (getWidth() > _content->getWidth())
		{
			min = 0;
			max = 0;
		}
		else
		{
			min = getWidth() - _content->getWidth();
			max = 0;
		}

		if (pos.getX() < min) pos.setX(min);
		if (pos.getX() > max) pos.setX(max);
	}
	else if (_scrollDirection == ScrollDirection::RightToLeft)
	{
		if (!_bHorizontalScroll) return;

		pos.setX(pos.getX() + delta.getX());
		if (getWidth() > _content->getWidth())
		{
			min = getWidth() - _content->getWidth();
			max = getWidth() - _content->getWidth();
		}
		else
		{
			min = getWidth() - _content->getWidth();
			max = 0;
		}
		if (pos.getX() < min) pos.setX(min);
		if (pos.getX() > max) pos.setX(max);
	}
	else if (_scrollDirection == ScrollDirection::TopToBottom)
	{
		if (!_bVerticalScroll) return;

		pos.setY(pos.getY() + delta.getY());
		if (getHeight() > _content->getHeight())
		{
			min = getHeight() - _content->getHeight();
			max = getHeight() - _content->getHeight();
		}
		else
		{
			min = getHeight() - _content->getHeight();
			max = 0;
		}
		if (pos.getY() < min) pos.setY(min);
		if (pos.getY() > max) pos.setY(max);
	}
	else if (_scrollDirection == ScrollDirection::BottomToTop)
	{
		if (!_bVerticalScroll) return;

		pos.setY(pos.getY() + delta.getY());
		if (getHeight() > _content->getHeight())
		{
			min = 0;
			max = 0;
		}
		else
		{
			min = getHeight() - _content->getHeight();
			max = 0;
		}
		if (pos.getY() < min) pos.setY(min);
		if (pos.getY() > max) pos.setY(max);
	}
	_content->setPosition(pos);
	_touchPosition = touchPoint;
}
