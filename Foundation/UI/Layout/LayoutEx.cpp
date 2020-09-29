#include "LayoutEx.h"

using namespace ui;

LayoutEx::LayoutEx()
{
	this->setWidget(CREATE_NODE(render::CtrlWidget));
}

LayoutEx::~LayoutEx()
{
	this->removeAllItems();
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

void LayoutEx::resize(const math::Size& size)
{
	//LayoutItem::resize(size);

	this->onLayoutSizeChanged(size);
}

math::Size LayoutEx::getLayoutMinSize()
{
	return m_sMinSize;
}

math::Size LayoutEx::getLayoutMaxSize()
{
	return m_sMaxSize;
}

bool LayoutEx::copy(LayoutEx* item)
{
	if (!LayoutItemEx::copy(item))
	{
		return false;
	}

	std::vector<LayoutItemEx*>::const_iterator iter = item->getChildren().begin();
	while (iter != item->getChildren().end())
	{
		this->addItem(*iter);
		iter++;
	}

	return true;
}

math::Size LayoutEx::getLayoutInnerMinSize()
{
	return m_sMinSize;
}

math::Size LayoutEx::getLayoutInnerMaxSize()
{
	return m_sMaxSize;
}

void LayoutEx::onLayoutSizeChanged(const math::Size& innerSize)
{
	LayoutItemEx* pItem;

	float calW = 0;
	float calH = 0;

	float realW = 0;
	float realH = 0;

	std::vector<math::Rect> innerItems;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 内部大小
		math::Rect innerItem;

		const math::Rect& itemRect = pItem->getLayoutRect();

		float x = itemRect.getX() / this->getGeometry().getWidth() * innerSize.getWidth();
		float y = itemRect.getY() / this->getGeometry().getHeight() * innerSize.getHeight();
		float w = itemRect.getWidth() / this->getGeometry().getWidth() * innerSize.getWidth();
		float h = itemRect.getHeight() / this->getGeometry().getHeight() * innerSize.getHeight();
		innerItems.push_back(math::Rect(x, y, w, h));
		iter++;
	}

	// 内部计算时，需要补差原点坐标的偏移量
	for (int i = 0; i < innerItems.size(); i++)
	{
		math::Rect allocRect = innerItems[i];
		//m_vChildren[i]->setLayoutGeometry(allocRect);
	}
}

float LayoutEx::calItemWidth(LayoutItemEx* item, float width)
{
	SizeType st = item->getSizePolicy().width;
	float w = 0;
	
	if (item->getLayoutMinSize().getWidth() > 0 && item->getLayoutMinSize().getWidth() > width)
	{
		w = item->getLayoutMinSize().getWidth();
	}
	if (item->getLayoutMaxSize().getWidth() > 0 && item->getLayoutMaxSize().getWidth() < width)
	{
		w = item->getLayoutMaxSize().getWidth();
	}

	return w;
}

float LayoutEx::calItemHeight(LayoutItemEx* item, float height)
{
	SizeType st = item->getSizePolicy().height;
	float h = 0;

	if (item->getLayoutMinSize().getHeight() > 0 && item->getLayoutMinSize().getHeight() > height)
	{
		h = item->getLayoutMinSize().getHeight();
	}

	if (item->getLayoutMaxSize().getHeight() > 0 && item->getLayoutMaxSize().getHeight() < height)
	{
		h = item->getLayoutMaxSize().getHeight();
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

math::Size HorizontalLayout::getLayoutInnerMinSize()
{
	LayoutItemEx* pItem;
	float w = 0, h = 0;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 宽度拼接
		w += pItem->getLayoutMinSize().getWidth();
		// 高度判断
		if (pItem->getLayoutMinSize().getHeight() > h)
			h = pItem->getLayoutMinSize().getHeight();
		iter++;
	}

	math::Size defaultSize = LayoutEx::getLayoutInnerMinSize();
	if (w < defaultSize.getWidth())
	{
		w = defaultSize.getWidth();
	}

	if (h < defaultSize.getHeight())
	{
		h = defaultSize.getHeight();
	}

	return math::Size(w, h);
}

math::Size HorizontalLayout::getLayoutInnerMaxSize()
{
	LayoutItemEx* pItem;
	float w = 0, h = 0;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 宽度拼接
		w += pItem->getLayoutMaxSize().getWidth();
		// 高度判断
		if (pItem->getLayoutMaxSize().getHeight() > h)
			h = pItem->getLayoutMaxSize().getHeight();
		iter++;
	}

	math::Size defaultSize = LayoutEx::getLayoutInnerMaxSize();
	if (w < defaultSize.getWidth())
	{
		w = defaultSize.getWidth();
	}

	if (h < defaultSize.getHeight())
	{
		h = defaultSize.getHeight();
	}

	return math::Size(w, h);
}

//////////////////////////////////////////////////////////////////////////

VerticalLayout::VerticalLayout()
{

}

VerticalLayout::~VerticalLayout()
{

}

math::Size VerticalLayout::getLayoutInnerMinSize()
{
	LayoutItemEx* pItem;
	float w = 0, h = 0;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 高度拼接
		h += pItem->getLayoutMinSize().getHeight();
		// 宽度判断
		if (pItem->getLayoutMinSize().getWidth() > w)
			w = pItem->getLayoutMinSize().getWidth();
		iter++;
	}

	math::Size defaultSize = LayoutEx::getLayoutInnerMinSize();
	if (w < defaultSize.getWidth())
	{
		w = defaultSize.getWidth();
	}

	if (h < defaultSize.getHeight())
	{
		h = defaultSize.getHeight();
	}

	return math::Size(w, h);
}

math::Size VerticalLayout::getLayoutInnerMaxSize()
{
	LayoutItemEx* pItem;

	float w = 0, h = 0;

	std::vector<LayoutItemEx*>::iterator iter = m_vChildren.begin();
	while (iter != m_vChildren.end())
	{
		pItem = *iter;
		// 高度拼接
		h += pItem->getLayoutMaxSize().getHeight();
		// 宽度判断
		if (pItem->getLayoutMaxSize().getWidth() > w)
			w = pItem->getLayoutMaxSize().getWidth();
		iter++;
	}

	math::Size defaultSize = LayoutEx::getLayoutInnerMaxSize();
	if (w < defaultSize.getWidth())
	{
		w = defaultSize.getWidth();
	}

	if (h < defaultSize.getHeight())
	{
		h = defaultSize.getHeight();
	}

	return math::Size(w,h);
}

//////////////////////////////////////////////////////////////////////////


GridLayout::GridLayout()
{

}

GridLayout::~GridLayout()
{

}

math::Size GridLayout::getLayoutInnerMinSize()
{
	return getMinSize();
}

math::Size GridLayout::getLayoutInnerMaxSize()
{
	return getMaxSize();
}
