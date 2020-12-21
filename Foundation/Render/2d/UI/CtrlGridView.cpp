#include "CtrlGridView.h"

render::CtrlGridView::CtrlGridView()
{
}

render::CtrlGridView::~CtrlGridView()
{
}

bool render::CtrlGridView::init()
{
	if (!CtrlListView::init())
	{
		return false;
	}
	return true;
}

void render::CtrlGridView::initItems()
{
	if (_itemWidgets.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	math::Vector2 maxValue;

	if (_scrollDirection == ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT)
	{
		std::vector<CtrlWidget*>::iterator iter = _itemWidgets.begin();
		while (iter != _itemWidgets.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);

			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posY > this->getHeight())
			{
				posX += maxValue.getX();
				posY = 0;
				maxValue.setX(0);
			}
			posY += pItem->getHeight();
			pItem->setPosition(posX, posY);
			iter++;
		}
		_content->setVolume(abs(posX) + maxValue.getX(), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::HORIZONTAL_RIGHT_TO_LEFT)
	{
		std::vector<CtrlWidget*>::iterator iter = _itemWidgets.begin();
		while (iter != _itemWidgets.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posY > this->getHeight())
			{
				posX -= maxValue.getX();
				posY = 0;
				maxValue.setX(0);
			}

			posY += pItem->getHeight();
			pItem->setPosition(posX, posY); 
			iter++;
		}
		_content->setVolume(abs(posX) + maxValue.getX(), getHeight());

		iter = _itemWidgets.begin();
		while (iter != _itemWidgets.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPositionX(_content->getWidth() + pItem->getPositionX());
		}
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_TOP_TO_BOTTOM)
	{
		std::vector<CtrlWidget*>::iterator iter = _itemWidgets.begin();
		while (iter != _itemWidgets.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posX > this->getWidth())
			{
				posY -= maxValue.getY();
				posX = 0;
				maxValue.setY(0);
			}
			pItem->setPosition(posX, posY);
			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY) + maxValue.getY());

		iter = _itemWidgets.begin();
		while (iter != _itemWidgets.end())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			pItem->setPositionY(_content->getHeight() + pItem->getPositionY());
		}
	}
	else if (_scrollDirection == ScrollDirection::VERTICAL_BOTTOM_TO_TOP)
	{
		std::vector<CtrlWidget*>::reverse_iterator iter = _itemWidgets.rbegin();
		while (iter != _itemWidgets.rend())
		{
			ScrollItem* pItem = static_cast<ScrollItem*>(*iter);
			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posX > this->getWidth())
			{
				posY += maxValue.getY();
				posX = 0;
				maxValue.setY(0);
			}
			pItem->setPosition(posX, posY);
			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY) + maxValue.getY());
	}
}
