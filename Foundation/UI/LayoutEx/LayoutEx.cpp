#include "LayoutEx.h"

using namespace ui;

LayoutEx::LayoutEx()
{
	this->setWidget(CREATE_NODE(Widget));
}

LayoutEx::~LayoutEx()
{
	this->removeAllItems();
}

void LayoutEx::setLeftMargin(float margin)
{
	m_fMargin.left = margin;
}

float LayoutEx::getLeftMargin()
{
	return m_fMargin.left;
}

void LayoutEx::setRightMargin(float margin)
{
	m_fMargin.right = margin;
}

float LayoutEx::getRightMargin()
{
	return m_fMargin.right;
}

void LayoutEx::setTopMargin(float margin)
{
	m_fMargin.top = margin;
}

float LayoutEx::getTopMargin()
{
	return m_fMargin.top;
}

void LayoutEx::setBottomMargin(float margin)
{
	m_fMargin.bottom = margin;
}

float LayoutEx::getBottomMargin()
{
	return m_fMargin.bottom;
}

void LayoutEx::setMargin(const sys::Margin& margin)
{
	m_fMargin = margin;
}

const sys::Margin& LayoutEx::getMargin()
{
	return m_fMargin;
}

void LayoutEx::addItem(LayoutItemEx* item)
{
	ASSERT(item != nullptr);

	m_vChildren.push_back(item);
	
	if (item->getWidget() && this->getWidget())
	{
		this->getWidget()->addChild(item->getWidget());
	}
}

void LayoutEx::removeItem(LayoutItemEx* item)
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

void LayoutEx::removeAllItems()
{
	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();

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

const std::vector<LayoutItemEx*>& LayoutEx::getChildren()
{
	return m_vChildren;
}

void LayoutEx::resize(const sys::Size& inputSize)
{
	this->resize(getOrgin(), inputSize);
}

void LayoutEx::resize(const sys::Vector2& position, const sys::Size& size)
{
	this->resize(sys::Rect(position.x, position.y, size.width, size.height));
}

void LayoutEx::resize(const sys::Rect& rect)
{
	this->resize(rect);

	sys::Size innerSize;
	innerSize.width = rect.width - m_fMargin.left - m_fMargin.right;
	innerSize.height = rect.height - m_fMargin.bottom - m_fMargin.top;

	this->onLayoutSizeChanged(innerSize);
}

sys::Size LayoutEx::getLayoutMinSize()
{
	sys::Size size = getLayoutInnerMinSize();
	size.width += m_fMargin.left + m_fMargin.right;
	size.height += m_fMargin.bottom + m_fMargin.top;

	return size;
}

sys::Size LayoutEx::getLayoutMaxSize()
{
	sys::Size size = getLayoutInnerMaxSize();
	size.width += m_fMargin.left + m_fMargin.right;
	size.height += m_fMargin.bottom + m_fMargin.top;

	return size;
}

bool LayoutEx::copy(LayoutEx* item)
{
	if (item == nullptr) 
	{
		return false;
	}

	setMargin(item->getMargin());

	std::vector<LayoutItemEx*>::const_iterator iter = item->getChildren().begin();
	while (iter != item->getChildren().end())
	{
		this->addItem(*iter);
		iter++;
	}

	return LayoutItemEx::copy(item);
}

sys::Size LayoutEx::getLayoutInnerMinSize()
{
	return sys::Size(
		m_sMinSize.width - m_fMargin.left - m_fMargin.right,
		m_sMinSize.height - m_fMargin.bottom - m_fMargin.top);
}

sys::Size LayoutEx::getLayoutInnerMaxSize()
{
	return sys::Size(
		m_sMaxSize.width - m_fMargin.left - m_fMargin.right,
		m_sMaxSize.height - m_fMargin.bottom - m_fMargin.top);
}

void LayoutEx::onLayoutSizeChanged(const sys::Size& innerSize)
{
	LayoutItemEx* pItem;

	float calW = 0;
	float calH = 0;

	float realW = 0;
	float realH = 0;

	std::vector<sys::Rect> innerItems;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 内部大小
		sys::Rect innerItem;

		const sys::Rect& itemRect = pItem->getGeometry();

		innerItem.x = itemRect.x / this->getGeometry().width * innerSize.width;
		innerItem.y = itemRect.x / this->getGeometry().height * innerSize.height;
		innerItem.width = itemRect.width / this->getGeometry().width * innerSize.width;
		innerItem.height = itemRect.height / this->getGeometry().height * innerSize.height;
		innerItems.push_back(innerItem);
		iter++;
	}

	// 内部计算时，需要补差原点坐标的偏移量
	for (int i = 0; i < innerItems.size(); i++)
	{
		sys::Rect allocRect = innerItems[i];
		//m_vChildren[i]->setLayoutGeometry(allocRect);
	}
}

float LayoutEx::calItemWidth(LayoutItemEx* item, float width)
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

float LayoutEx::calItemHeight(LayoutItemEx* item, float height)
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
	LayoutItemEx* pItem;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
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

	sys::Size defaultSize = LayoutEx::getLayoutInnerMinSize();
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
	LayoutItemEx* pItem;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
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

	sys::Size defaultSize = LayoutEx::getLayoutInnerMaxSize();
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
	LayoutItemEx* pItem;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
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

	sys::Size defaultSize = LayoutEx::getLayoutInnerMinSize();
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
	LayoutItemEx* pItem;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
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

	sys::Size defaultSize = LayoutEx::getLayoutInnerMaxSize();
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
