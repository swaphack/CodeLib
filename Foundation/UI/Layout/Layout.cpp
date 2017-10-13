#include "Layout.h"

using namespace ui;

Layout::Layout()
{
}

Layout::~Layout()
{
	this->removeAllItems();
	if (this->getWidget())
	{
		this->getWidget()->removeFromParent();
	}
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
	if (this->getWidget())
	{
		this->getWidget()->removeAllChildren();
	}
}

const std::vector<LayoutItem*>& Layout::getChildren()
{
	return m_vChildren;
}

void Layout::resize(const sys::Size& inputSize)
{
	this->resize(getOrgin(), inputSize);
}

void Layout::resize(const sys::Vector2& position, const sys::Size& size)
{
	this->resize(sys::Rect(position.x, position.y, size.width, size.height));
}

void Layout::resize(const sys::Rect& rect)
{
	this->setWidgetGeomerty(rect);

	sys::Size innerSize;
	innerSize.width = rect.width - m_fMargin.left - m_fMargin.right;
	innerSize.height = rect.height - m_fMargin.bottom - m_fMargin.top;

	this->onLayoutSizeChanged(innerSize);
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

void Layout::onLayoutSizeChanged(const sys::Size& innerSize)
{
	float calW = 0;
	float calH = 0;

	float realW = 0;
	float realH = 0;

	std::vector<sys::Rect> innerItems;

	int count = m_vChildren.size();
	for (int i = 0; i < count; i++)
	{
		// 内部大小
		sys::Rect innerItem;
		const sys::Rect& itemRect = m_vChildren[i]->getGeometry();

		innerItem.x = itemRect.x / this->getGeometry().width * innerSize.width;
		innerItem.y = itemRect.x / this->getGeometry().height * innerSize.height;
		innerItem.width = itemRect.width / this->getGeometry().width * innerSize.width;
		innerItem.height = itemRect.height / this->getGeometry().height * innerSize.height;

		Layout* pLayout = dynamic_cast<Layout*>(m_vChildren[i]);
		if (pLayout)
		{
			pLayout->resize(innerItem);
		}
		else
		{
			m_vChildren[i]->setWidgetGeomerty(innerItem);
		}
	}
}