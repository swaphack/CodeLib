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

	return true;
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

void LayoutItem::setWidgetGeomerty(const sys::Rect& geometry)
{
	if (m_pWidget == nullptr)
	{
		return;
	}

	sys::Vector3 anchor = m_pWidget->getAnchorPoint();

	float width = geometry.width;
	float height = geometry.height;
	float posX = geometry.x + anchor.x * width;
	float posY = geometry.y + anchor.y * height;

	m_pWidget->setPosition(posX, posY);
	m_pWidget->setVolume(width, height);
}