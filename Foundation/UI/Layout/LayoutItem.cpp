#include "LayoutItem.h"
#include "UI/CtrlWidget.h"

using namespace ui;

LayoutItem::LayoutItem()
{
}

LayoutItem::~LayoutItem()
{
}

LayoutItem* ui::LayoutItem::create()
{
	sys::CSSSize size;
	size.setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	size.setHeight(sys::NumberType::Percent, ONE_HUNDRED);
	LayoutItem* sInstance = CREATE_OBJECT(ui::LayoutItem);
	sInstance->setMargin(0, 0, 0, 0);
	sInstance->setLeftMargin(0);
	sInstance->setSize(size);
	sInstance->retain();

	return sInstance;
}

void ui::LayoutItem::setMargin(const sys::CSSMargin& margin)
{
	m_sMargin = margin;

	this->refresh();
}

const sys::CSSMargin& ui::LayoutItem::getMargin() const
{
	return m_sMargin;
}

sys::CSSMargin& ui::LayoutItem::getMargin()
{
	return m_sMargin;
}

void ui::LayoutItem::setMarginState(bool left, bool right, bool top, bool bottom)
{
	m_sMarginState.Left = left;
	m_sMarginState.Right = right;
	m_sMarginState.Top = top;
	m_sMarginState.Bottom = bottom;

	this->refresh();
}

void ui::LayoutItem::setMarginState(const MarginState& state)
{
	m_sMarginState = state;

	this->refresh();
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

	this->refresh();
}

const sys::CSSSize& ui::LayoutItem::getSize() const
{
	return m_sSize;
}

sys::CSSSize& ui::LayoutItem::getSize()
{
	return m_sSize;
}

void ui::LayoutItem::setMargin(float top, float right, float bottom, float left)
{
	this->setLeftMargin(left);
	this->setRightMargin(right);
	this->setTopMargin(top);
	this->setBottomMargin(bottom);
}

void ui::LayoutItem::setLeftMargin(float offset, bool enable)
{
	m_sMarginState.Left = enable;
	m_sMargin.setLeft(sys::NumberType::Fixed, offset);

	this->refresh();
}

void ui::LayoutItem::setRightMargin(float offset, bool enable)
{
	m_sMarginState.Right = enable;
	m_sMargin.setRight(sys::NumberType::Fixed, offset);

	this->refresh();
}

void ui::LayoutItem::setTopMargin(float offset, bool enable)
{
	m_sMarginState.Top = enable;
	m_sMargin.setTop(sys::NumberType::Fixed, offset);

	this->refresh();
}

void ui::LayoutItem::setBottomMargin(float offset, bool enable)
{
	m_sMarginState.Bottom = enable;
	m_sMargin.setBottom(sys::NumberType::Fixed, offset);

	this->refresh();
}

void ui::LayoutItem::unsetLeftMargin()
{
	m_sMarginState.Left = false;

	this->refresh();
}

void ui::LayoutItem::unsetRightMargin()
{
	m_sMarginState.Right = false;

	this->refresh();
}

void ui::LayoutItem::unsetTopMargin()
{
	m_sMarginState.Top = false;

	this->refresh();
}

void ui::LayoutItem::unsetBottomMargin()
{
	m_sMarginState.Bottom = false;

	this->refresh();
}

void ui::LayoutItem::unsetMarginState()
{
	m_sMarginState = ui::MarginState();

	this->refresh();
}

void ui::LayoutItem::setWidth(float value)
{
	m_sSize.setWidth(sys::NumberType::Fixed, value);

	this->refresh();
}

void ui::LayoutItem::setHeight(float value)
{
	m_sSize.setHeight(sys::NumberType::Fixed, value);

	this->refresh();
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

void ui::LayoutItem::setWidget(CtrlWidget* widget)
{
	m_pWidget = widget;

	this->refresh();
}

