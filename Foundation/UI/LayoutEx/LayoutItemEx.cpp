#include "LayoutItemEx.h"

using namespace ui;

LayoutItemEx::LayoutItemEx()
{
	setMinSize(LAYOUT_SIZE_MIN_WIDTH, LAYOUT_SIZE_MIN_HEIGHT);
	setMaxSize(LAYOUT_SIZE_MAX_WIDTH, LAYOUT_SIZE_MAX_HEIGHT);
}

LayoutItemEx::~LayoutItemEx()
{
}

const math::Size& LayoutItemEx::getMinSize()
{
	return m_sMinSize;
}

void LayoutItemEx::setMinSize(float width, float height)
{
	m_sMinSize.set(width, height);
}

void LayoutItemEx::setMinSize(const math::Size& size)
{
	m_sMinSize = size;
}

const math::Size& LayoutItemEx::getMaxSize()
{
	return m_sMaxSize;
}

void LayoutItemEx::setMaxSize(float width, float height)
{
	m_sMaxSize.set(width, height);
}

void LayoutItemEx::setMaxSize(const math::Size& size)
{
	m_sMaxSize = size;	
}

SizePolicy& LayoutItemEx::getSizePolicy()
{
	return m_spAdjust;
}

void LayoutItemEx::setSizePolicy(const SizePolicy& policy)
{
	m_spAdjust = policy;
}

math::Size LayoutItemEx::getLayoutMinSize()
{
	float w = 0, h = 0;
	SizeType st = getSizePolicy().width;
	switch (st)
	{
	case ui::EST_Fixed:
		w = getGeometry().getWidth();
		break;
	case ui::EST_Minimum:
		w = getMinSize().getWidth();
		break;
	case ui::EST_Maximum:
		w = 0;
		break;
	case ui::EST_Expanding:
		w = 0;
		break;
	default:
		break;
	}
	st = getSizePolicy().height;
	switch (st)
	{
	case ui::EST_Fixed:
		h = getGeometry().getHeight();
		break;
	case ui::EST_Minimum:
		h = getMinSize().getHeight();
		break;
	case ui::EST_Maximum:
		h = 0;
		break;
	case ui::EST_Expanding:
		h = 0;
		break;
	default:
		break;
	}
	return math::Size(w, h);
}

math::Size LayoutItemEx::getLayoutMaxSize()
{
	float w = 0, h = 0;
	SizeType st = getSizePolicy().width;
	switch (st)
	{
	case ui::EST_Fixed:
		w = getGeometry().getWidth();
		break;
	case ui::EST_Minimum:
		w = 0;
		break;
	case ui::EST_Maximum:
		w = getMaxSize().getWidth();
		break;
	case ui::EST_Expanding:
		w = 0;
		break;
	default:
		break;
	}
	st = getSizePolicy().height;
	switch (st)
	{
	case ui::EST_Fixed:
		h = getGeometry().getHeight();
		break;
	case ui::EST_Minimum:
		h = 0;
		break;
	case ui::EST_Maximum:
		h = getMaxSize().getHeight();
		break;
	case ui::EST_Expanding:
		h = 0;
		break;
	default:
		break;
	}
	return math::Size(w, h);
}

bool LayoutItemEx::copy(LayoutItemEx* item)
{
	if (item == nullptr)
	{
		return false;
	}
	setMinSize(item->getMinSize());
	setMaxSize(item->getMaxSize());
	setSizePolicy(item->getSizePolicy());

	return LayoutItem::copy(item);
}