#include "CtrlTableView.h"
#include "Layout/LayoutItem.h"

ui::CtrlTableView::CtrlTableView()
{
	_scrollDirection = ScrollDirection::LeftToRight;
}

ui::CtrlTableView::~CtrlTableView()
{
}

bool ui::CtrlTableView::init()
{
	if (!CtrlScrollView::init())
	{
		return false;
	}


	return true;
}

void ui::CtrlTableView::setTableData(TableDataProtocol* tableData)
{
	_sourceData = tableData;
}

const ui::TableDataProtocol* ui::CtrlTableView::getTableData() const
{
	return _sourceData;
}

void ui::CtrlTableView::reload()
{
	if (_sourceData == nullptr)
	{
		return;
	}

	_content->removeAllWidgets();

	int nCount = _sourceData->getDataCount();
	if (nCount == 0) return;

	float fTotalWidth = 0;
	float fTotalHeight = 0;
	for (int i = 0; i < nCount; i++)
	{
		TableCell& cell = _tabelCells[i];
		cell.size = _sourceData->getDataSize(i);
		fTotalWidth += cell.size.getWidth();
		fTotalHeight += cell.size.getHeight();
	}
	
	float fWidth = 0;
	float fHeight = 0;
	if (_scrollDirection == ScrollDirection::LeftToRight)
	{
		fWidth = 0;
		fHeight = this->getHeight();
		for (int i = 0; i < nCount; i++)
		{
			TableCell& cell = _tabelCells[i];
			cell.position.setX(fWidth);
			fWidth += cell.size.getWidth();
		}

		_content->setAnchorPoint(0, 0);
		_content->setPosition(0, 0);
		_content->setVolume(fWidth, fHeight);
	}
	else if (_scrollDirection == ScrollDirection::RightToLeft)
	{
		fWidth = fTotalWidth;
		fHeight = this->getHeight();
		for (int i = 0; i < nCount; i++)
		{
			TableCell& cell = _tabelCells[i];
			cell.position.setX(fWidth);
			fWidth -= cell.size.getWidth();
		}

		_content->setAnchorPoint(1, 0);
		_content->setPosition(this->getWidth() - fTotalWidth, 0);
		_content->setVolume(fTotalWidth, fHeight);
	}
	else if (_scrollDirection == ScrollDirection::TopToBottom)
	{
		fWidth = this->getWidth();
		fHeight = fTotalHeight;
		for (int i = 0; i < nCount; i++)
		{
			TableCell& cell = _tabelCells[i];
			cell.position.setY(fHeight);
			fHeight -= cell.size.getHeight();
		}

		_content->setAnchorPoint(0, 1);
		_content->setPosition(0, this->getHeight() - fTotalHeight);
		_content->setVolume(fWidth, fTotalHeight);
	}
	else if (_scrollDirection == ScrollDirection::BottomToTop)
	{
		_content->setAnchorPoint(0, 0);
		fWidth = this->getWidth();
		fHeight = 0;
		for (int i = 0; i < nCount; i++)
		{
			TableCell& cell = _tabelCells[i];
			cell.position.setY(fHeight);
			fHeight += cell.size.getHeight();
		}

		_content->setAnchorPoint(0, 1);
		_content->setPosition(0, 0);
		_content->setVolume(fWidth, fTotalHeight);
	}

	processData();
}

void ui::CtrlTableView::processData()
{
	if (_sourceData == nullptr) return;

	int nCount = _sourceData->getDataCount();
	bool bHide = false;
	float minX = this->getWidth() - _content->getWidth();
	float minY = this->getHeight() - _content->getHeight();
	for (int i = 0; i < nCount; i++)
	{
		TableCell& cell = _tabelCells[i];

		bHide = false;
		if (_scrollDirection == ScrollDirection::LeftToRight
			|| _scrollDirection == ScrollDirection::RightToLeft)
		{
			float posX = _content->getPositionX() - minX;
			if (cell.position.getX() + cell.size.getWidth() < posX || cell.position.getX() > posX + this->getWidth())
			{
				bHide = true;
			}
		}
		else if (_scrollDirection == ScrollDirection::TopToBottom
			|| _scrollDirection == ScrollDirection::BottomToTop)
		{
			float posY0 = -(_content->getPositionY() - this->getHeight());
			float posY1 = -_content->getPositionY();
			if (cell.position.getY() - cell.size.getHeight() > posY0 || cell.position.getY() < posY1)
			{
				bHide = true;
			}
		}
		
		if (bHide)
		{
			if (cell.widget == nullptr) continue;
			else cell.widget->setVisible(false);
		}
		else
		{
			if (cell.widget == nullptr)
			{
				auto widget = _sourceData->getDataCell(i);
				if (widget)
				{
					cell.widget = widget;
					widget->setPosition(cell.position);
					widget->setVolume(cell.size);
					if (_scrollDirection == ScrollDirection::LeftToRight)
					{
						widget->getLayoutItem()->unsetRightMargin();
						widget->getLayoutItem()->setLeftMargin(cell.position.getX());
					}
					else if (_scrollDirection == ScrollDirection::RightToLeft)
					{
						widget->getLayoutItem()->unsetLeftMargin();
						widget->getLayoutItem()->setRightMargin(cell.position.getX());
					}
					else if (_scrollDirection == ScrollDirection::TopToBottom)
					{
						widget->getLayoutItem()->unsetBottomMargin();
						widget->getLayoutItem()->setTopMargin(cell.position.getY());
					}
					else if (_scrollDirection == ScrollDirection::BottomToTop)
					{
						widget->getLayoutItem()->unsetTopMargin();
						widget->getLayoutItem()->setBottomMargin(cell.position.getY());
					}
					_content->addWidget(widget);
				}
			}
			if (cell.widget)
			{
				cell.widget->setVisible(true);
			}
			
		}
	}
}

void ui::CtrlTableView::handMovedTouch(const math::Vector2& touchPoint)
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

	processData();
}
