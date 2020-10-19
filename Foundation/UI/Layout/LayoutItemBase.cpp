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

void ui::LayoutItemBase::setBoxVisible(bool bVisible)
{
	if (m_pWidget)
	{
		m_pWidget->setRectVisible(bVisible);
	}
}

bool ui::LayoutItemBase::containPoint(float x, float y)
{
	if (m_pWidget)
	{
		return m_pWidget->containTouchPoint(x, y);
	}
	return false;
}

bool ui::LayoutItemBase::copy(LayoutItemBase* item)
{
	if (item == nullptr)
	{
		return false;
	}
	setWidget(item->getWidget());

	return true;
}

void ui::LayoutItemBase::resize(const math::Size& size)
{
}
