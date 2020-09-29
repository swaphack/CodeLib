#include "LayoutItemBase.h"

ui::LayoutItemBase::LayoutItemBase()
{
}

ui::LayoutItemBase::~LayoutItemBase()
{

}

void ui::LayoutItemBase::setWidget(render::CtrlWidget* widget)
{
	if (widget == nullptr)
	{
		return;
	}
	m_pWidget = widget;
}

render::CtrlWidget* ui::LayoutItemBase::getWidget() const
{
	return m_pWidget;
}

void ui::LayoutItemBase::setBoxVisible(bool status)
{
	m_bBoxVisible = status;
}

bool ui::LayoutItemBase::isBoxVisible() const
{
	return m_bBoxVisible;
}

void ui::LayoutItemBase::setBoxColor(const sys::Color4B& color)
{
	m_cBoxColor = color;
}

const sys::Color4B& ui::LayoutItemBase::getBoxColor() const
{
	return m_cBoxColor;
}

bool ui::LayoutItemBase::copy(LayoutItemBase* item)
{
	if (item == nullptr)
	{
		return false;
	}
	setWidget(item->getWidget());
	setBoxColor(item->getBoxColor());
	setBoxVisible(item->isBoxVisible());

	return true;
}

void ui::LayoutItemBase::resize(const math::Size& size)
{
}
