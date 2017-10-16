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

const sys::Rect& LayoutItem::getGeometry()
{
	return m_rGeometry;
}

void LayoutItem::setGeometry(float x, float y, float width, float height)
{
	m_rGeometry.x = x;
	m_rGeometry.y = y;
	m_rGeometry.width = width;
	m_rGeometry.height = height;
}

void LayoutItem::setGeometry(const sys::Rect& rect)
{
	m_rGeometry = rect;

	//this->setLayoutGeometry(rect);
}

void LayoutItem::setOrgin(float x, float y)
{
	m_rGeometry.x = x;
	m_rGeometry.y = y;
}

sys::Vector2 LayoutItem::getOrgin()
{
	return sys::Vector2(m_rGeometry.x, m_rGeometry.y);
}

void LayoutItem::setSize(float width, float height)
{
	m_rGeometry.width = width;
	m_rGeometry.height = height;
}

sys::Size LayoutItem::getSize()
{
	return sys::Size(m_rGeometry.width, m_rGeometry.height);
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

void LayoutItem::resize(const sys::Rect& rect)
{
	sys::Vector2 anchorPoint;
	calAnchorPoint(anchorPoint.x, anchorPoint.y);
	this->setWidgetGeomerty(rect, anchorPoint);
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

void LayoutItem::setWidgetGeomerty(const sys::Rect& geometry, const sys::Vector2& anchorPoint)
{
	if (m_pWidget == nullptr)
	{
		return;
	}

	m_pWidget->setPosition(geometry.x, geometry.y);
	m_pWidget->setVolume(geometry.width, geometry.height);
	m_pWidget->setAnchorPoint(anchorPoint.x, anchorPoint.y);
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

