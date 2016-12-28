#include "LayoutItem.h"

#include "Layout.h"

using namespace ui;

LayoutItem::LayoutItem()
:m_pWidget(nullptr)
, m_pLayout(nullptr)
, m_bBoxVisible(false)
{
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
	m_rectColor = color;
}

const sys::Color4B& LayoutItem::getBoxColor()
{
	return m_rectColor;
}

LayoutItem::~LayoutItem()
{
	SAFE_DELETE(m_pWidget);
	SAFE_DELETE(m_pLayout);
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
}

void LayoutItem::setOrgin(float x, float y)
{
	m_rGeometry.x = x;
	m_rGeometry.y = y;
}

void LayoutItem::setSize(float width, float height)
{
	m_rGeometry.width = width;
	m_rGeometry.height = height;
}

const sys::Size& LayoutItem::getMinSize()
{
	return m_sMinSize;
}

void LayoutItem::setMinSize(float width, float height)
{
	m_sMinSize.width = width;
	m_sMinSize.height = height;
}

void LayoutItem::setMinSize(const sys::Size& size)
{
	m_sMinSize = size;
}

const sys::Size& LayoutItem::getMaxSize()
{
	return m_sMaxSize;
}

void LayoutItem::setMaxSize(float width, float height)
{
	m_sMaxSize.width = width;
	m_sMaxSize.height = height;
}

void LayoutItem::setMaxSize(const sys::Size& size)
{
	m_sMaxSize = size;	
}

void LayoutItem::setWidget(Widget* widget)
{
	if (widget == nullptr)
	{
		return;
	}

	SAFE_DELETE(m_pWidget);

	m_pWidget = widget;
}

Widget* LayoutItem::getWidget()
{
	return m_pWidget;
}

void LayoutItem::setLayout(Layout* layout)
{
	if (layout == nullptr)
	{
		return;
	}

	SAFE_DELETE(m_pLayout);

	m_pLayout = layout;
}

Layout* LayoutItem::getLayout()
{
	return m_pLayout;
}

SizePolicy& LayoutItem::getSizePolicy()
{
	return m_spAdjust;
}

void LayoutItem::setSizePolicy(const SizePolicy& policy)
{
	m_spAdjust = policy;
}

void LayoutItem::setLayoutItemGeometry(const sys::Rect& rect)
{
	if (m_pWidget == nullptr)
	{
		return;
	}

	this->setWidgetGeomerty(rect);

	if (m_pLayout)
	{
		m_pLayout->resize(sys::Size(rect.width, rect.height));
	}
}

sys::Size LayoutItem::getLayoutItemMinSize()
{
	sys::Size size;
	SizeType st = getSizePolicy().getWidthType();
	switch (st)
	{
	case ui::EST_Fixed:
		size.width = getGeometry().width;
		break;
	case ui::EST_Minimum:
		size.width = getMinSize().width;
		break;
	case ui::EST_Maximum:
		size.width = 0;
		break;
	case ui::EST_Expanding:
		size.width = 0;
		break;
	default:
		break;
	}
	st = getSizePolicy().getHeightType();
	switch (st)
	{
	case ui::EST_Fixed:
		size.height = getGeometry().height;
		break;
	case ui::EST_Minimum:
		size.height = getMinSize().height;
		break;
	case ui::EST_Maximum:
		size.height = 0;
		break;
	case ui::EST_Expanding:
		size.height = 0;
		break;
	default:
		break;
	}
	return size;
}

sys::Size LayoutItem::getLayoutItemMaxSize()
{
	sys::Size size;
	SizeType st = getSizePolicy().getWidthType();
	switch (st)
	{
	case ui::EST_Fixed:
		size.width = getGeometry().width;
		break;
	case ui::EST_Minimum:
		size.width = 0;
		break;
	case ui::EST_Maximum:
		size.width = getMaxSize().width;
		break;
	case ui::EST_Expanding:
		size.width = 0;
		break;
	default:
		break;
	}
	st = getSizePolicy().getHeightType();
	switch (st)
	{
	case ui::EST_Fixed:
		size.height = getGeometry().height;
		break;
	case ui::EST_Minimum:
		size.height = 0;
		break;
	case ui::EST_Maximum:
		size.height = getMaxSize().height;
		break;
	case ui::EST_Expanding:
		size.height = 0;
		break;
	default:
		break;
	}
	return size;
}

void LayoutItem::setWidgetGeomerty(const sys::Rect& geometry)
{
	if (m_pWidget == nullptr)
	{
		return;
	}

	const sys::Vector& anchorPoint = m_pWidget->getAnchorPoint();

	float posX = geometry.x + anchorPoint.x * geometry.width;
	float posY = geometry.y + anchorPoint.y * geometry.height;
	float width = geometry.width;
	float height = geometry.height;

	m_pWidget->setPosition(posX, posY);
	m_pWidget->setVolume(width, height);
}
