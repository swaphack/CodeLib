#include "LayoutItem.h"
#include "Layout.h"

using namespace ui;

LayoutItem::LayoutItem()
:m_pWidget(nullptr)
, m_bBoxVisible(false)
, m_eAnchorPosition(EAP_NONE)
{
}

LayoutItem::~LayoutItem()
{
}

const math::Rect& LayoutItem::getGeometry()
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
	m_rGeometry.orgin.set(x, y);
}

math::Vector2 LayoutItem::getOrgin()
{
	return m_rGeometry.orgin;
}

void LayoutItem::setSize(float width, float height)
{
	m_rGeometry.size.set(width, height);
}

math::Size LayoutItem::getSize()
{
	return m_rGeometry.size;
}

void LayoutItem::setWidget(Widget* widget)
{
	if (widget == nullptr)
	{
		return;
	}

	SAFE_RELEASE(m_pWidget);
	SAFE_RETAIN(widget);

	m_pWidget = widget;
}

Widget* LayoutItem::getWidget()
{
	return m_pWidget;
}

void LayoutItem::setAnchorPosition(AnchorPosition anchorPos)
{
	m_eAnchorPosition = (AnchorPosition)anchorPos;
}

AnchorPosition LayoutItem::getAnchorPosition()
{
	return m_eAnchorPosition;
}

bool LayoutItem::copy(LayoutItem* item)
{
	if (item == nullptr)
	{
		return false;
	}

	setGeometry(item->getGeometry());
	setBoxColor(item->getBoxColor());
	setBoxVisible(item->isBoxVisible());
	setWidget(item->getWidget());
	setAnchorPosition(item->getAnchorPosition());

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

bool LayoutItem::isBoxVisible()
{
	return m_bBoxVisible;
}

void LayoutItem::setBoxColor(const sys::Color4B& color)
{
	m_cBoxColor = color;
}

const sys::Color4B& LayoutItem::getBoxColor()
{
	return m_cBoxColor;
}

void LayoutItem::setWidgetGeomerty(const math::Rect& geometry, const math::Vector2& anchorPoint)
{
	if (m_pWidget == nullptr)
	{
		return;
	}

	m_pWidget->setPosition(geometry.orgin);
	m_pWidget->setVolume(geometry.getWidth(), geometry.getHeight());
	m_pWidget->setAnchorPoint(anchorPoint);
}

void LayoutItem::calAnchorPoint(float& x, float& y)
{
	switch (m_eAnchorPosition)
	{
	case ui::EAP_NONE:
		x = 0;
		y = 0;
		break;
	case ui::EAP_DOWN_LEFT:
		x = 0;
		y = 0;
		break;
	case ui::EAP_DOWN_CENTER:
		x = 0.5f;
		y = 0;
		break;
	case ui::EAP_DOWN_RIGHT:
		x = 1;
		y = 0;
		break;
	case ui::EAP_CENTER_LEFT:
		x = 0;
		y = 0.5f;
		break;
	case ui::EAP_CENTER_CENTER:
		x = 0.5f;
		y = 0.5f;
		break;
	case ui::EAP_CENTER_RIGHT:
		x = 1;
		y = 0.5f;
		break;
	case ui::EAP_UP_LEFT:
		x = 0;
		y = 1;
		break;
	case ui::EAP_UP_CENTER:
		x = 0.5f;
		y = 1;
		break;
	case ui::EAP_UP_RIGHT:
		x = 1;
		y = 1;
		break;
	default:
		break;
	}
}

