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
	sys::Vector2 pos = getOrgin();
	pos.x = pos.x / this->getGeometry().width * inputSize.width;
	pos.y = pos.y / this->getGeometry().height * inputSize.height;

	this->resize(pos, inputSize);
}

void Layout::resize(const sys::Vector2& position, const sys::Size& size)
{
	this->resize(sys::Rect(position.x, position.y, size.width, size.height));
}

void Layout::resize(const sys::Rect& rect)
{
	LayoutItem::resize(rect);

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
	const sys::Size& parentSize = this->getSize();
	sys::Vector2 parentAnchor;
	calAnchorPoint(parentAnchor.x, parentAnchor.y);

	int count = m_vChildren.size();
	for (int i = 0; i < count; i++)
	{
		LayoutItem* child = m_vChildren[i];
		if (child == nullptr)
		{
			continue;
		}

		// 内部大小
		sys::Rect innerItem;
		const sys::Size& srcSize = child->getSize();

		calLayoutPosition(child, srcSize, innerSize, innerItem.x, innerItem.y);
		calLayoutSize(child, parentSize, innerSize, innerItem.width, innerItem.height);
		innerItem.x -= parentSize.width * parentAnchor.x;
		innerItem.y -= parentSize.height * parentAnchor.y;

		child->resize(innerItem);
	}
}

void Layout::calLayoutPosition(LayoutItem* child, const sys::Size& srcSize, const sys::Size& newSize, float& x, float& y)
{
	if (child == nullptr)
	{
		return;
	}

	const sys::Rect& itemRect = child->getGeometry();
	AnchorPosition anchorPos = (AnchorPosition)child->getAnchorPosition();
	switch (anchorPos)
	{
	case ui::EAP_NONE:
		x = itemRect.x / srcSize.width * newSize.width;
		y = itemRect.y / srcSize.height * newSize.height;
		break;
	case ui::EAP_DOWN_LEFT:
		x = 0;
		y = 0;
		break;
	case ui::EAP_DOWN_CENTER:
		x = newSize.width * 0.5f;
		y = 0;
		break;
	case ui::EAP_DOWN_RIGHT:
		x = newSize.width;
		y = 0;
		break;
	case ui::EAP_CENTER_LEFT:
		x = 0;
		y = newSize.height * 0.5f;
		break;
	case ui::EAP_CENTER_CENTER:
		x = newSize.width * 0.5f;
		y = newSize.height * 0.5f;
		break;
	case ui::EAP_CENTER_RIGHT:
		x = newSize.width;
		y = newSize.height * 0.5f;
		break;
	case ui::EAP_UP_LEFT:
		x = 0;
		y = newSize.height;
		break;
	case ui::EAP_UP_CENTER:
		x = newSize.width * 0.5f;
		y = newSize.height;
		break;
	case ui::EAP_UP_RIGHT:
		x = newSize.width;
		y = newSize.height;
		break;
	default:
		break;
	}
}

void Layout::calLayoutSize(LayoutItem* child, const sys::Size& srcSize, const sys::Size& newSize, float& w, float& h)
{
	if (child == nullptr)
	{
		return;
	}

	float scaleX = newSize.width / srcSize.width;
	float scaleY = newSize.height / srcSize.height;
	float scale = 1;
	if (scaleX < 1 || scaleY < 1)
	{
		scale = scaleX < scaleY ? scaleX : scaleY;
	}

	const sys::Size& childSize = child->getSize();
	w = childSize.width * scale;
	h = childSize.height * scale;
}
