#include "LayoutItem.h"
#include "Layout.h"

using namespace ui;

LayoutItem::LayoutItem()
:m_pWidget(nullptr)
, m_bBoxVisible(false)
{
}

LayoutItem::~LayoutItem()
{
}

const math::Rect& LayoutItem::getGeometry() const
{
	return m_rGeometry;
}

void LayoutItem::setGeometry(float x, float y, float width, float height)
{
	m_rGeometry.set(x,y, width, height);
}

void LayoutItem::setGeometry(const math::Rect& rect)
{
	m_rGeometry = rect;

	//this->setLayoutGeometry(rect);
}

void LayoutItem::setOrgin(float x, float y)
{
	m_rGeometry.setOrigin(x, y);
}

void ui::LayoutItem::setOrgin(const math::Vector2& position)
{
	m_rGeometry.setOrigin(position);
}

const math::Vector2& LayoutItem::getOrgin() const
{
	return m_rGeometry.getOrigin();
}

void LayoutItem::setSize(float width, float height)
{
	m_rGeometry.setSize(width, height);
}

void ui::LayoutItem::setSize(const math::Size& size)
{
	m_rGeometry.setSize(size);
}

const math::Size& LayoutItem::getSize() const
{
	return m_rGeometry.getSize();
}

void LayoutItem::setWidget(render::CtrlWidget* widget)
{
	if (widget == nullptr)
	{
		return;
	}
	m_pWidget = widget;
}

render::CtrlWidget* LayoutItem::getWidget() const
{
	return m_pWidget;
}

void LayoutItem::setAnchorPoint(const math::Vector2& anchorPoint)
{
	m_vAnchorPoint = anchorPoint;
}

const math::Vector2& LayoutItem::getAnchorPoint() const
{
	return m_vAnchorPoint;
}

bool LayoutItem::copy(LayoutItem* item)
{
	if (item == nullptr)
	{
		return false;
	}

	setWidget(item->getWidget());
	setGeometry(item->getGeometry());
	setBoxColor(item->getBoxColor());
	setBoxVisible(item->isBoxVisible());
	setAnchorPoint(item->getAnchorPoint());

	return true;
}

void LayoutItem::resize(const math::Rect& rect)
{
	float x = 0;
	float y = 0;
	calAnchorPoint(x, y);
	this->setWidgetGeomerty(rect, math::Vector2(x, y));
}

void LayoutItem::setBoxVisible(bool status)
{
	m_bBoxVisible = status;
}

bool LayoutItem::isBoxVisible() const
{
	return m_bBoxVisible;
}

void LayoutItem::setBoxColor(const sys::Color4B& color)
{
	m_cBoxColor = color;
}

const sys::Color4B& LayoutItem::getBoxColor() const
{
	return m_cBoxColor;
}

void LayoutItem::setWidgetGeomerty(const math::Rect& geometry, const math::Vector2& anchorPoint)
{
	if (m_pWidget == nullptr)
	{
		return;
	}

	m_pWidget->setPosition(geometry.getOrigin());
	m_pWidget->setVolume(geometry.getWidth(), geometry.getHeight());
	m_pWidget->setAnchorPoint(anchorPoint);
}

void LayoutItem::calAnchorPoint(float& x, float& y)
{
	x = m_vAnchorPoint.getX();
	y = m_vAnchorPoint.getY();
}

void ui::LayoutItem::showWidgetInfo()
{
	if (m_pWidget == nullptr)
	{
		return;
	}
	PRINT("Position: (%f,%f)\n", m_pWidget->getPositionX(), m_pWidget->getPositionY());
	PRINT("Size: (%f,%f)\n", m_pWidget->getWidth(), m_pWidget->getHeight());
	PRINT("AnchorPoint: (%f,%f)\n", m_pWidget->getAnchorPointX(), m_pWidget->getAnchorPointY());
}

