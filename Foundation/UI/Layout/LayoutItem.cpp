#include "LayoutItem.h"
#include "Layout.h"

using namespace ui;

LayoutItem::LayoutItem()
{
}

LayoutItem::~LayoutItem()
{
}

void ui::LayoutItem::setMargin(const sys::CSSMargin& margin)
{
	m_sMargin = margin;
}

const sys::CSSMargin& ui::LayoutItem::getMargin() const
{
	return m_sMargin;
}

void ui::LayoutItem::setSize(const sys::CSSSize& size)
{
	m_sSize = size;
}

const sys::CSSSize& ui::LayoutItem::getSize() const
{
	return m_sSize;
}

bool LayoutItem::copy(LayoutItem* item)
{
	if (!LayoutItemBase::copy(item))
	{
		return false;
	}

	setMargin(item->getMargin());

	return true;
}

void LayoutItem::resize(const math::Size& size)
{
	if (m_pWidget == nullptr)
	{
		return;
	}

	float x = 0, y = 0, w = size.getWidth(), h = size.getHeight();

	const auto& left = m_sMargin.getLeft();
	const auto& right = m_sMargin.getRight();
	const auto& top = m_sMargin.getTop();
	const auto& bottom = m_sMargin.getBottom();

	const auto& width = m_sSize.getWidth();
	const auto& height = m_sSize.getHeight();

	if (left.isFixedValue())
	{
		x = left.getValue();
		w -= x;
	}
	else
	{
		x = size.getWidth() * left.getValue();
		w -= x;
	}

	if (bottom.isFixedValue())
	{
		y = bottom.getValue();
		h -= y;
	}
	else
	{
		y = size.getHeight() * bottom.getValue();
		h -= y;
	}

	if (width.getValue() != 0)
	{
		if (width.isFixedValue())
		{
			w = width.getValue();
		}
		else
		{
			w = size.getWidth() * width.getValue();
		}
	}
	else
	{
		if (right.isFixedValue())
		{
			w -= right.getValue();
		}
		else
		{
			w -= size.getWidth() * right.getValue();
		}
	}

	if (height.getValue() != 0)
	{
		if (height.isFixedValue())
		{
			h = height.getValue();
		}
		else
		{
			h = size.getHeight() * height.getValue();
		}
	}
	else
	{
		if (top.isFixedValue())
		{
			h -= top.getValue();
		}
		else
		{
			h -= size.getHeight() * top.getValue();
		}
	}

	x += w * m_pWidget->getAnchorPointX();
	y += h * m_pWidget->getAnchorPointY();

	auto pParent = m_pWidget->getParent();
	if (pParent)
	{
		x -= pParent->getAnchorPointX() * size.getWidth();
		y -= pParent->getAnchorPointY() * size.getHeight();
	}

	m_pWidget->setVolume(w, h);
	m_pWidget->setPosition(x, y);
}

