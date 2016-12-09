#include "Layout.h"

using namespace ui;

typedef struct InnerItem
{
	float fixX;
	float perX;

	float fixY;
	float perY;

	InnerItem() :fixX(0), perX(0), fixY(0), perY(0){}
};

Layout::Layout()
{

}

Layout::~Layout()
{
	this->removeAllItems();
}

void Layout::setLeftMargin(float margin)
{
	m_fLeftMargin = margin;
}

float Layout::getLeftMargin()
{
	return m_fLeftMargin;
}

void Layout::setRightMargin(float margin)
{
	m_fRightMargin = margin;
}

float Layout::getRightMargin()
{
	return m_fRightMargin;
}

void Layout::setTopMargin(float margin)
{
	m_fTopMargin = margin;
}

float Layout::getTopMargin()
{
	return m_fTopMargin;
}

void Layout::setBottomMargin(float margin)
{
	m_fBottomMargin = margin;
}

float Layout::getBottomMargin()
{
	return m_fBottomMargin;
}

void Layout::addItem(LayoutItem* item)
{
	ASSERT(item != nullptr);

	m_vChildren.push_back(item);
}

void Layout::removeItem(LayoutItem* item)
{
	ASSERT(item != nullptr);

	for (int i = 0; i < m_vChildren.size(); i++)
	{
		if (m_vChildren[i] == item)
		{
			m_vChildren.erase(m_vChildren.begin() + i);
			delete item;
			break;
		}
	}
}

void Layout::removeAllItems()
{
	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();

	while (iter != m_vChildren.end())
	{
		delete *iter;
		iter++;
	}
}

void Layout::onViewSizeChanged(const sys::Size& inputSize)
{
	sys::Rect innerRect;
	innerRect.x = m_fLeftMargin;
	innerRect.y = m_fBottomMargin;

	sys::Size innerSize;
	innerSize.width = inputSize.width - m_fLeftMargin - m_fRightMargin;
	innerSize.height = inputSize.height - m_fBottomMargin - m_fTopMargin;

	this->onLayoutInnerSizeChanged(innerSize);
}

sys::Size Layout::getLayoutItemMinSize()
{
	sys::Size size = getLayoutInnerMinSize();
	size.width += m_fLeftMargin + m_fRightMargin;
	size.height += m_fBottomMargin + m_fTopMargin;

	return size;
}

sys::Size Layout::getLayoutItemMaxSize()
{
	sys::Size size = getLayoutInnerMaxSize();
	size.width += m_fLeftMargin + m_fRightMargin;
	size.height += m_fBottomMargin + m_fTopMargin;

	return size;
}

float Layout::calItemWidth(LayoutItem* item, float width)
{
	SizeType st = item->getSizePolicy().getWidthType();
	float w = 0;
	
	if (item->getLayoutItemMinSize().width > 0 && item->getLayoutItemMinSize().width > width)
	{
		w = item->getLayoutItemMinSize().width;
	}
	if (item->getLayoutItemMaxSize().width > 0 && item->getLayoutItemMaxSize().width < width)
	{
		w = item->getLayoutItemMaxSize().width;
	}

	return w;
}

float Layout::calItemHeight(LayoutItem* item, float height)
{
	SizeType st = item->getSizePolicy().getHeightType();
	float h = 0;

	if (item->getLayoutItemMinSize().height > 0 && item->getLayoutItemMinSize().height > height)
	{
		h = item->getLayoutItemMinSize().height;
	}

	if (item->getLayoutItemMaxSize().height > 0 && item->getLayoutItemMaxSize().height < height)
	{
		h = item->getLayoutItemMaxSize().height;
	}
	return h;
}

//////////////////////////////////////////////////////////////////////////

HorizontalLayout::HorizontalLayout()
{

}

HorizontalLayout::~HorizontalLayout()
{

}

sys::Size HorizontalLayout::getLayoutInnerMinSize()
{
	sys::Size size;
	LayoutItem* pItem;

	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		size.width += pItem->getLayoutItemMinSize().width;
		if (pItem->getLayoutItemMinSize().height > size.height)
			size.height = pItem->getLayoutItemMinSize().height;
		iter++;
	}

	sys::Size defaultSize = Layout::getLayoutItemMinSize();
	if (size.width < defaultSize.width)
	{
		size.width = defaultSize.width;
	}

	if (size.height < defaultSize.height)
	{
		size.height = defaultSize.height;
	}

	return size;
}

sys::Size HorizontalLayout::getLayoutInnerMaxSize()
{
	sys::Size size;
	LayoutItem* pItem;

	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		size.width += pItem->getLayoutItemMaxSize().width;
		if (pItem->getLayoutItemMaxSize().height > size.height)
			size.height = pItem->getLayoutItemMaxSize().height;
		iter++;
	}

	sys::Size defaultSize = Layout::getLayoutItemMaxSize();
	if (size.width < defaultSize.width)
	{
		size.width = defaultSize.width;
	}

	if (size.height < defaultSize.height)
	{
		size.height = defaultSize.height;
	}

	return size;
}

void HorizontalLayout::onLayoutInnerSizeChanged(const sys::Size& innerSize)
{
	LayoutItem* pItem;

	float calW = 0;
	float calH = 0;

	float realW = 0;
	float realH = 0;

	std::vector<InnerItem> innerItems;

	float allocW = 0;
	float allocH = 0;

	float reallocW = 0;
	float reallocH = 0;

	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		InnerItem innerItem;

		const sys::Rect& itemRect = pItem->getGeometry();

		calW = itemRect.width / this->getGeometry().width * innerSize.width;
		calH = itemRect.height / this->getGeometry().height * innerSize.height;

		realW = calItemWidth(pItem, calW);
		if (realW == 0)
			innerItem.perX = itemRect.width;
		else
			innerItem.fixX = realW;

		realH = calItemHeight(pItem, calH);
		if (realH == 0)
			innerItem.perY = itemRect.height;
		else
			innerItem.fixY = realH;

		allocW += realW;
		allocH += realH;

		reallocW += innerItem.perX;
		reallocH += innerItem.perY;

		innerItems.push_back(innerItem);
		iter++;
	}

	float reallocWS = innerSize.width - allocW;
	float reallocHS = innerSize.height - allocH;

	sys::Rect allocRect;
	for (int i = 0; i < innerItems.size(); i++)
	{
		if (innerItems[i].fixX > 0)
			allocRect.width = innerItems[i].fixX;
		else
			allocRect.width = innerItems[i].perX / reallocW * reallocWS;

		if (innerItems[i].fixY > 0)
			allocRect.height = innerItems[i].fixY;
		else
			allocRect.height = innerItems[i].perY / reallocH * reallocHS;
		
		allocRect.y = (innerSize.height - allocRect.height) * 0.5f;
		m_vChildren[i]->setLayoutItemGeometry(allocRect);
		allocRect.x += allocRect.width;
	}
}

//////////////////////////////////////////////////////////////////////////

VerticalLayout::VerticalLayout()
{

}

VerticalLayout::~VerticalLayout()
{

}

sys::Size VerticalLayout::getLayoutItemMinSize()
{
	sys::Size size;
	LayoutItem* pItem;

	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		size.height += pItem->getLayoutItemMinSize().height;
		if (pItem->getLayoutItemMinSize().width > size.width)
			size.width = pItem->getLayoutItemMinSize().width;
		iter++;
	}

	return size;
}

//////////////////////////////////////////////////////////////////////////


GridLayout::GridLayout()
{

}

GridLayout::~GridLayout()
{

}