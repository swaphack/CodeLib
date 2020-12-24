#include "LayoutItemBase.h"
#include "UI/CtrlWidget.h"

ui::LayoutItemBase::LayoutItemBase()
{
}

ui::LayoutItemBase::~LayoutItemBase()
{

}

void ui::LayoutItemBase::setWidgetName(const std::string& name)
{
	m_strWidgetName = name;
}

const std::string& ui::LayoutItemBase::getWidgetName() const
{
	return m_strWidgetName;
}

void ui::LayoutItemBase::setWidget(CtrlWidget* widget)
{
	if (widget == nullptr)
	{
		return;
	}
	m_pWidget = widget;
}

ui::CtrlWidget* ui::LayoutItemBase::getWidget() const
{
	return m_pWidget;
}

void ui::LayoutItemBase::autoResize()
{
	this->resize(m_sParentSize);
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
	m_sParentSize = size;
}

void ui::LayoutItemBase::refresh()
{
	if (m_pWidget != nullptr)
	{
		m_pWidget->refreshLayout();
	}
}

