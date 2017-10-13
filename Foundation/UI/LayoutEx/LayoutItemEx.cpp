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

const sys::Size& LayoutItemEx::getMinSize()
{
	return m_sMinSize;
}

void LayoutItemEx::setMinSize(float width, float height)
{
	m_sMinSize.width = width;
	m_sMinSize.height = height;
}

void LayoutItemEx::setMinSize(const sys::Size& size)
{
	m_sMinSize = size;
}

const sys::Size& LayoutItemEx::getMaxSize()
{
	return m_sMaxSize;
}

void LayoutItemEx::setMaxSize(float width, float height)
{
	m_sMaxSize.width = width;
	m_sMaxSize.height = height;
}

void LayoutItemEx::setMaxSize(const sys::Size& size)
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

sys::Size LayoutItemEx::getLayoutMinSize()
{
	sys::Size size;
	SizeType st = getSizePolicy().width;
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
	st = getSizePolicy().height;
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

sys::Size LayoutItemEx::getLayoutMaxSize()
{
	sys::Size size;
	SizeType st = getSizePolicy().width;
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
	st = getSizePolicy().height;
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