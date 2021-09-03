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

	this->removeTouchFunc(render::TouchType::MOVED);
	this->addTouchFunc(render::TouchType::MOVED, [this](const math::Vector2& touchPoint) {
		math::Vector2 delta = touchPoint;
		delta -= _touchPosition;

		delta *= getMovingMultiple();

		math::Vector3 pos = _content->getPosition();

		float min = 0;
		float max = 0;

		if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT)
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
		else if (_scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
		{
			if (!_bHorizontalScroll) return;

			pos.setX(pos.getX() + delta.getX());
			if (getWidth() > _content->getWidth())
			{
				min = getWidth()-_content->getWidth();
				max = getWidth()-_content->getWidth();
			}
			else
			{
				min = getWidth() - _content->getWidth();
				max = 0;
			}
			if (pos.getX() < min) pos.setX(min);
			if (pos.getX() > max) pos.setX(max);
		}
		else if (_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM)
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
		else if (_scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
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

		_content->getActionProxy()->stopAllActions();
		_content->getActionProxy()->runAction(render::MoveToAction::create(0.5f, pos));

		//_content->setPosition(pos);

		_touchPosition = touchPoint;
	});

	return true;
}

void ui::CtrlListView::setDirection(ScrollDirection direction)
{
	_scrollDirection = direction;

	notify(NodeNotifyType::GEOMETRY);
}

ui::ScrollDirection ui::CtrlListView::getDirection()
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
	if (_scrollWidgets.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;
			pItem->getLayoutItem()->unsetRightMargin();
			pItem->getLayoutItem()->setLeftMargin(posX);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;
			pItem->getLayoutItem()->unsetLeftMargin();
			pItem->getLayoutItem()->setRightMargin(posX);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(abs(posX), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;
			pItem->getLayoutItem()->unsetBottomMargin();
			pItem->getLayoutItem()->setTopMargin(posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY));
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;
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
		CtrlScrollView::addItem(item, item->getLayoutItem()->getSize(), zOrder);
	}
}

bool ui::CtrlListView::onTouchMoved(float x, float y, bool include)
{

	return true;
}
