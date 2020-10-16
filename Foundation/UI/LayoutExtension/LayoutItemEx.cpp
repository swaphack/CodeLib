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

const math::Size& LayoutItemEx::getMinSize() const
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

const math::Size& LayoutItemEx::getMaxSize() const
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

const SizePolicy& LayoutItemEx::getSizePolicy() const
{
	return m_spAdjust;
}

void LayoutItemEx::setSizePolicy(const SizePolicy& policy)
{
	m_spAdjust = policy;
}

const math::Rect& ui::LayoutItemEx::getLayoutRect() const
{
	return m_sDefaultRect;
}

void ui::LayoutItemEx::setLayoutRect(const math::Rect& rect)
{
	m_sDefaultRect = rect;
}

void ui::LayoutItemEx::setLayoutRect(const math::Vector2& position, const math::Size& size)
{
	m_sDefaultRect.setOrigin(position);
	m_sDefaultRect.setSize(size);
}

const math::Size& ui::LayoutItemEx::getGeometry() const
{
	return m_sDefaultRect.getSize();
}

const math::Vector2& ui::LayoutItemEx::getPosition() const
{
	return m_sDefaultRect.getOrigin();
}

math::Size LayoutItemEx::getLayoutMinSize()
{
	float w = 0, h = 0;
	SizeType st = getSizePolicy().width;
	switch (st)
	{
	case ui::SizeType::FIXED:
		w = getGeometry().getWidth();
		break;
	case ui::SizeType::MINIMUM:
		w = getMinSize().getWidth();
		break;
	case ui::SizeType::MAXIMUM:
		w = 0;
		break;
	case ui::SizeType::EXPANDING:
		w = 0;
		break;
	default:
		break;
	}
	st = getSizePolicy().height;
	switch (st)
	{
	case ui::SizeType::FIXED:
		h = getGeometry().getHeight();
		break;
	case ui::SizeType::MINIMUM:
		h = getMinSize().getHeight();
		break;
	case ui::SizeType::MAXIMUM:
		h = 0;
		break;
	case ui::SizeType::EXPANDING:
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
	case ui::SizeType::FIXED:
		w = getGeometry().getWidth();
		break;
	case ui::SizeType::MINIMUM:
		w = 0;
		break;
	case ui::SizeType::MAXIMUM:
		w = getMaxSize().getWidth();
		break;
	case ui::SizeType::EXPANDING:
		w = 0;
		break;
	default:
		break;
	}
	st = getSizePolicy().height;
	switch (st)
	{
	case ui::SizeType::FIXED:
		h = getGeometry().getHeight();
		break;
	case ui::SizeType::MINIMUM:
		h = 0;
		break;
	case ui::SizeType::MAXIMUM:
		h = getMaxSize().getHeight();
		break;
	case ui::SizeType::EXPANDING:
		h = 0;
		break;
	default:
		break;
	}
	return math::Size(w, h);
}

bool LayoutItemEx::copy(LayoutItemEx* item)
{
	if (!LayoutItemBase::copy(item))
	{
		return false;
	}
	setMinSize(item->getMinSize());
	setMaxSize(item->getMaxSize());
	setSizePolicy(item->getSizePolicy());

	return true;
}