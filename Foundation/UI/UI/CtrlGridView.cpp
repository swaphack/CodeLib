#include "CtrlGridView.h"
#include "Layout/LayoutItem.h"
ui::CtrlGridView::CtrlGridView()
{
}

ui::CtrlGridView::~CtrlGridView()
{
}

bool ui::CtrlGridView::init()
{
	if (!CtrlListView::init())
	{
		return false;
	}
	return true;
}

void ui::CtrlGridView::initItems()
{
	if (_scrollWidgets.size() == 0)
	{
		return;
	}
	float posX = 0;
	float posY = 0;

	math::Vector2 maxValue;

	if (_scrollDirection == ScrollDirection::LeftToRight)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;

			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posY + pItem->getHeight() > this->getHeight())
			{
				posX += maxValue.getX();
				posY = 0;
				maxValue.setX(0);
			}
			pItem->getLayoutItem()->unsetRightMargin();
			pItem->getLayoutItem()->unsetBottomMargin();
			pItem->getLayoutItem()->setLeftMargin(posX);
			pItem->getLayoutItem()->setTopMargin(posY);

			posY += pItem->getHeight();
			iter++;
		}
		_content->setVolume(abs(posX) + maxValue.getX(), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::RightToLeft)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;
			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posY + pItem->getHeight() > this->getHeight())
			{
				posX += maxValue.getX();
				posY = 0;
				maxValue.setX(0);
			}

			pItem->getLayoutItem()->unsetLeftMargin();
			pItem->getLayoutItem()->unsetBottomMargin();
			pItem->getLayoutItem()->setRightMargin(posX);
			pItem->getLayoutItem()->setTopMargin(posY);


			posY += pItem->getHeight();

			iter++;
		}
		_content->setVolume(abs(posX) + maxValue.getX(), getHeight());
	}
	else if (_scrollDirection == ScrollDirection::TopToBottom)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;
			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posX + pItem->getWidth() > this->getWidth())
			{
				posY += maxValue.getY();
				posX = 0;
				maxValue.setY(0);
			}

			pItem->getLayoutItem()->unsetRightMargin();
			pItem->getLayoutItem()->unsetBottomMargin();
			pItem->getLayoutItem()->setLeftMargin(posX);
			pItem->getLayoutItem()->setTopMargin(posY);

			posX += pItem->getWidth();

			iter++;
		}
		_content->setVolume(getWidth(), abs(posY) + maxValue.getY());
	}
	else if (_scrollDirection == ScrollDirection::BottomToTop)
	{
		auto iter = _scrollWidgets.begin();
		while (iter != _scrollWidgets.end())
		{
			ui::CtrlWidget* pItem = *iter;
			if (pItem->getWidth() > maxValue.getX()) maxValue.setX(pItem->getWidth());
			if (pItem->getHeight() > maxValue.getY()) maxValue.setY(pItem->getHeight());

			if (posX + pItem->getWidth() > this->getWidth())
			{
				posY += maxValue.getY();
				posX = 0;
				maxValue.setY(0);
			}
			pItem->getLayoutItem()->unsetRightMargin();
			pItem->getLayoutItem()->unsetTopMargin();

			pItem->getLayoutItem()->setLeftMargin(posX);
			pItem->getLayoutItem()->setBottomMargin(posY);

			posX += pItem->getWidth();
			iter++;
		}
		_content->setVolume(getWidth(), abs(posY) + maxValue.getY());
	}
}
