#include "Layout.h"

using namespace ui;

struct InnerItem
{
	float fixX;
	float perX;

	float fixY;
	float perY;

	InnerItem() :fixX(0), perX(0), fixY(0), perY(0){}
};

Layout::Layout()
{
	this->setWidget(render::createNode<Widget>());
	this->setLayout(this);
}

Layout::~Layout()
{
	this->removeAllItems();
}

void Layout::setLeftMargin(float margin)
{
	m_fMargin.left = margin;
}

float Layout::getLeftMargin()
{
	return m_fMargin.left;
}

void Layout::setRightMargin(float margin)
{
	m_fMargin.right = margin;
}

float Layout::getRightMargin()
{
	return m_fMargin.right;
}

void Layout::setTopMargin(float margin)
{
	m_fMargin.top = margin;
}

float Layout::getTopMargin()
{
	return m_fMargin.top;
}

void Layout::setBottomMargin(float margin)
{
	m_fMargin.bottom = margin;
}

float Layout::getBottomMargin()
{
	return m_fMargin.bottom;
}

void Layout::setMargin(const sys::Margin& margin)
{
	m_fMargin = margin;
}

const sys::Margin& Layout::getMargin()
{
	return m_fMargin;
}

void Layout::addItem(LayoutItem* item)
{
	ASSERT(item != nullptr);

	m_vChildren.push_back(item);
	
	if (item->getWidget() && this->getWidget())
	{
		this->getWidget()->addChild(item->getWidget());
	}
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

	if (item->getWidget() && this->getWidget())
	{
		this->getWidget()->removeChild(item->getWidget());
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

	m_vChildren.clear();

// 	if (this->getWidget())
// 	{
// 		this->getWidget()->removeAllChildren();
// 	}
}

const std::vector<LayoutItem*>& Layout::getChildren()
{
	return m_vChildren;
}

void Layout::resize(const sys::Size& inputSize)
{
	sys::Rect innerRect;
	innerRect.x = m_fMargin.left;
	innerRect.y = m_fMargin.bottom;

	sys::Size innerSize;
	innerSize.width = inputSize.width - m_fMargin.left - m_fMargin.right;
	innerSize.height = inputSize.height - m_fMargin.bottom - m_fMargin.top;

	this->onLayoutInnerSizeChanged(innerSize);
}

sys::Size Layout::getLayoutMinSize()
{
	sys::Size size = getLayoutInnerMinSize();
	size.width += m_fMargin.left + m_fMargin.right;
	size.height += m_fMargin.bottom + m_fMargin.top;

	return size;
}

sys::Size Layout::getLayoutMaxSize()
{
	sys::Size size = getLayoutInnerMaxSize();
	size.width += m_fMargin.left + m_fMargin.right;
	size.height += m_fMargin.bottom + m_fMargin.top;

	return size;
}

bool Layout::copy(Layout* item)
{
	if (item == nullptr) 
	{
		return false;
	}

	setMargin(item->getMargin());

	std::vector<LayoutItem*>::const_iterator iter = item->getChildren().begin();
	while (iter != item->getChildren().end())
	{
		this->addItem(*iter);
		iter++;
	}

	return LayoutItem::copy(item);
}

sys::Size Layout::getLayoutInnerMinSize()
{
	return sys::Size(
		m_sMinSize.width - m_fMargin.left - m_fMargin.right,
		m_sMinSize.height - m_fMargin.bottom - m_fMargin.top);
}

sys::Size Layout::getLayoutInnerMaxSize()
{
	return sys::Size(
		m_sMaxSize.width - m_fMargin.left - m_fMargin.right,
		m_sMaxSize.height - m_fMargin.bottom - m_fMargin.top);
}

void Layout::onLayoutInnerSizeChanged(const sys::Size& innerSize)
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

	// 内部计算时，需要补差原点坐标的偏移量
	float offX = m_fMargin.left;
	float offY = m_fMargin.bottom;

	sys::Rect allocRect;
	allocRect.x = offX;
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

		allocRect.y = (innerSize.height - allocRect.height) * 0.5f + offY;
		m_vChildren[i]->setLayoutGeometry(allocRect);
		allocRect.x += allocRect.width;
	}
}

float Layout::calItemWidth(LayoutItem* item, float width)
{
	SizeType st = item->getSizePolicy().width;
	float w = 0;
	
	if (item->getLayoutMinSize().width > 0 && item->getLayoutMinSize().width > width)
	{
		w = item->getLayoutMinSize().width;
	}
	if (item->getLayoutMaxSize().width > 0 && item->getLayoutMaxSize().width < width)
	{
		w = item->getLayoutMaxSize().width;
	}

	return w;
}

float Layout::calItemHeight(LayoutItem* item, float height)
{
	SizeType st = item->getSizePolicy().height;
	float h = 0;

	if (item->getLayoutMinSize().height > 0 && item->getLayoutMinSize().height > height)
	{
		h = item->getLayoutMinSize().height;
	}

	if (item->getLayoutMaxSize().height > 0 && item->getLayoutMaxSize().height < height)
	{
		h = item->getLayoutMaxSize().height;
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
		// 宽度拼接
		size.width += pItem->getLayoutMinSize().width;
		// 高度判断
		if (pItem->getLayoutMinSize().height > size.height)
			size.height = pItem->getLayoutMinSize().height;
		iter++;
	}

	sys::Size defaultSize = Layout::getLayoutInnerMinSize();
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
		// 宽度拼接
		size.width += pItem->getLayoutMaxSize().width;
		// 高度判断
		if (pItem->getLayoutMaxSize().height > size.height)
			size.height = pItem->getLayoutMaxSize().height;
		iter++;
	}

	sys::Size defaultSize = Layout::getLayoutInnerMaxSize();
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

//////////////////////////////////////////////////////////////////////////

VerticalLayout::VerticalLayout()
{

}

VerticalLayout::~VerticalLayout()
{

}

sys::Size VerticalLayout::getLayoutInnerMinSize()
{
	sys::Size size;
	LayoutItem* pItem;

	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 高度拼接
		size.height += pItem->getLayoutMinSize().height;
		// 宽度判断
		if (pItem->getLayoutMinSize().width > size.width)
			size.width = pItem->getLayoutMinSize().width;
		iter++;
	}

	sys::Size defaultSize = Layout::getLayoutInnerMinSize();
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

sys::Size VerticalLayout::getLayoutInnerMaxSize()
{
	sys::Size size;
	LayoutItem* pItem;

	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 高度拼接
		size.height += pItem->getLayoutMaxSize().height;
		// 宽度判断
		if (pItem->getLayoutMaxSize().width > size.width)
			size.width = pItem->getLayoutMaxSize().width;
		iter++;
	}

	sys::Size defaultSize = Layout::getLayoutInnerMaxSize();
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

//////////////////////////////////////////////////////////////////////////


GridLayout::GridLayout()
{

}

GridLayout::~GridLayout()
{

}

sys::Size GridLayout::getLayoutInnerMinSize()
{
	return getMinSize();
}

sys::Size GridLayout::getLayoutInnerMaxSize()
{
	return getMaxSize();
}
