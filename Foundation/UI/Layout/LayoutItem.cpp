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

sys::CSSMargin& ui::LayoutItem::getMargin()
{
	return m_sMargin;
}

void ui::LayoutItem::setMarginState(const MarginState& state)
{
	m_sMarginState = state;
}

const MarginState& ui::LayoutItem::getMarginState() const
{
	return m_sMarginState;
}

MarginState& ui::LayoutItem::getMarginState()
{
	return m_sMarginState;
}

void ui::LayoutItem::setSize(const sys::CSSSize& size)
{
	m_sSize = size;
}

const sys::CSSSize& ui::LayoutItem::getSize() const
{
	return m_sSize;
}

sys::CSSSize& ui::LayoutItem::getSize()
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
	LayoutItemBase::resize(size);

	if (m_pWidget == nullptr)
	{
		return;
	}

	float sizeW = size.getWidth(), sizeH = size.getHeight();

	const auto& left = m_sMargin.getLeft();
	const auto& right = m_sMargin.getRight();
	const auto& top = m_sMargin.getTop();
	const auto& bottom = m_sMargin.getBottom();

	const auto& width = m_sSize.getWidth();
	const auto& height = m_sSize.getHeight();

	float leftX = 0, rightX = 0, topY = 0, bottomY = 0, widthX = 0, heightY = 0;

	leftX = left.getRealValue(sizeW);

	bottomY = bottom.getRealValue(sizeH);

	rightX = right.getRealValue(sizeW);

	topY = top.getRealValue(sizeH);

	if (width.getRealValue() != 0) 
	{
		widthX = width.getRealValue(sizeW);
	}

	if (height.getRealValue() != 0)
	{
		heightY = height.getRealValue(sizeH);
	}

	float x = 0, y = 0, w = 0, h = 0;
	if (getMarginState().Left)
	{
		x = leftX;

		if (getMarginState().Right)
		{
			w = sizeW - x - rightX;
		}
		else
		{
			w = widthX;
		}
	}
	else if (getMarginState().Right)
	{
		x = sizeW - rightX - widthX;
		w = widthX;
	}
	else
	{// Ĭ�����
		x = leftX;
		w = widthX;
	}

	if (getMarginState().Bottom)
	{
		y = bottomY;

		if (getMarginState().Top)
		{
			h = sizeH - y - topY;
		}
		else
		{
			h = heightY;
		}
	}
	else if (getMarginState().Top)
	{
		y = sizeH - topY - heightY;
		h = heightY;
	}
	else
	{// Ĭ���·�
		y = bottomY;
		h = heightY;
	}

	if (w < 0) w = 0;
	if (h < 0) h = 0;

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



void ui::LayoutItem::addWidget(render::CtrlWidget* widget)
{
	if (widget == nullptr || this->getWidget() == nullptr)
	{
		return;
	}

	this->getWidget()->addWidget(widget);
}

