#include "Layout.h"

using namespace ui;

Layout::Layout()
{
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
	
	SAFE_RETAIN(item);
	m_vChildren.push_back(item);
	
// 	if (item->getWidget() && this->getWidget())
// 	{
// 		this->getWidget()->addChild(item->getWidget());
// 	}
}

void Layout::removeItem(LayoutItem* item)
{
	ASSERT(item != nullptr);

	for (int i = 0; i < m_vChildren.size(); i++)
	{
		if (m_vChildren[i] == item)
		{
			m_vChildren.erase(m_vChildren.begin() + i);
			SAFE_RELEASE(item);
			break;
		}
	}

// 	if (item->getWidget() && this->getWidget())
// 	{
// 		this->getWidget()->removeChild(item->getWidget());
// 	}
}

void Layout::removeAllItems()
{
	std::vector<LayoutItem*>::iterator iter = m_vChildren.begin();

	while (iter != m_vChildren.end())
	{
		SAFE_RELEASE((*iter));
		iter++;
	}

	m_vChildren.clear();
	
}

const std::vector<LayoutItem*>& Layout::getChildren()
{
	return m_vChildren;
}

void Layout::resize(const math::Size& inputSize)
{
	math::Vector2 pos = getOrgin();
	float x = pos.getX() / this->getGeometry().getWidth() * inputSize.getWidth();
	float y = pos.getY() / this->getGeometry().getHeight() * inputSize.getHeight();

	this->resize(math::Vector2(x, y), inputSize);
}

void Layout::resize(const math::Vector2& position, const math::Size& size)
{
	this->resize(math::Rect(position, size));
}

void Layout::resize(const math::Rect& rect)
{
	LayoutItem::resize(rect);

	float w = rect.getWidth() - m_fMargin.left - m_fMargin.right;
	float h = rect.getHeight() - m_fMargin.bottom - m_fMargin.top;
	this->onLayoutSizeChanged(math::Size(w, h));
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

void Layout::onLayoutSizeChanged(const math::Size& innerSize)
{
	float calW = 0;
	float calH = 0;

	float realW = 0;
	float realH = 0;

	std::vector<math::Rect> innerItems;
	const math::Size& parentSize = this->getSize();
	
	float x, y;
	calAnchorPoint(x, y);

	int count = m_vChildren.size();
	for (int i = 0; i < count; i++)
	{
		LayoutItem* child = m_vChildren[i];
		if (child == nullptr)
		{
			continue;
		}

		// 内部大小
		const math::Size& srcSize = child->getSize();

		float xx, yy, ww, hh;
		calLayoutPosition(child, srcSize, innerSize, xx, yy);
		calLayoutSize(child, parentSize, innerSize, ww, hh);
		ww -= ww * x;
		yy -= hh * y;

		child->resize(math::Rect(xx, yy, ww, hh));
	}
}

void Layout::calLayoutPosition(LayoutItem* child, const math::Size& srcSize, const math::Size& newSize, float& x, float& y)
{
	if (child == nullptr)
	{
		return;
	}

	const math::Rect& itemRect = child->getGeometry();

	const math::Vector2 anchorPoint = child->getAnchorPoint();

	x = anchorPoint.getX();
	y = anchorPoint.getY();
	/*
	switch (anchorPos)
	{
	case ui::EAP_NONE:
		x = itemRect.getX() / srcSize.getWidth() * newSize.getWidth();
		y = itemRect.getY() / srcSize.getHeight() * newSize.getHeight();
		break;
	case ui::EAP_DOWN_LEFT:
		x = 0;
		y = 0;
		break;
	case ui::EAP_DOWN_CENTER:
		x = newSize.getWidth() * 0.5f;
		y = 0;
		break;
	case ui::EAP_DOWN_RIGHT:
		x = newSize.getWidth();
		y = 0;
		break;
	case ui::EAP_CENTER_LEFT:
		x = 0;
		y = newSize.getHeight() * 0.5f;
		break;
	case ui::EAP_CENTER_CENTER:
		x = newSize.getWidth() * 0.5f;
		y = newSize.getHeight() * 0.5f;
		break;
	case ui::EAP_CENTER_RIGHT:
		x = newSize.getWidth();
		y = newSize.getHeight() * 0.5f;
		break;
	case ui::EAP_UP_LEFT:
		x = 0;
		y = newSize.getHeight();
		break;
	case ui::EAP_UP_CENTER:
		x = newSize.getWidth() * 0.5f;
		y = newSize.getHeight();
		break;
	case ui::EAP_UP_RIGHT:
		x = newSize.getWidth();
		y = newSize.getHeight();
		break;
	default:
		break;
	}
	*/
}

void Layout::calLayoutSize(LayoutItem* child, const math::Size& srcSize, const math::Size& newSize, float& w, float& h)
{
	if (child == nullptr)
	{
		return;
	}

	float scaleX = newSize.getWidth() / srcSize.getWidth();
	float scaleY = newSize.getHeight() / srcSize.getHeight();
	float scale = 1;
	if (scaleX < 1 || scaleY < 1)
	{
		scale = scaleX < scaleY ? scaleX : scaleY;
	}

	const math::Size& childSize = child->getSize();
	w = childSize.getWidth() * scale;
	h = childSize.getHeight() * scale;
}
