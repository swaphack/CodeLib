#include "PropertyPanel.h"
#include "PanelEvent.h"

ue::PropertyPanel::PropertyPanel()
{
}

ue::PropertyPanel::~PropertyPanel()
{
}

bool ue::PropertyPanel::init()
{
	if (!Panel::init())
	{
		return false;
	}

	G_PANELEVT->addEventListener(PANEL_SELECT_TARGET, this, [this](const sys::Event* evt) {
		if (evt)
		{
			this->updateProperty((ui::LayoutItem*)evt->getUserData());
		}
	});


	return true;
}

void ue::PropertyPanel::updateProperty(ui::LayoutItem* item)
{
	if (item == nullptr || item->getWidget() == nullptr)
	{
		return;
	}
	if (m_pTextType)
	{
		sys::String typeName(typeid(*item->getWidget()).name());
		int nIndex = typeName.findLastOf(":");
		if (nIndex >= 0)
		{
			typeName = typeName.subString(nIndex + 1, typeName.getSize() - nIndex);
		}
		m_pTextType->setString(typeName.getString());
	}
	if (m_pEditTextName)
	{
		m_pEditTextName->setString(item->getWidget()->getName());
	}
}

void ue::PropertyPanel::initUI()
{
	auto layoutItem = m_pLayout->findItemByName("TypeText");
	if (layoutItem)
	{
		m_pTextType = layoutItem->getWidget<render::CtrlText>();
	}

	layoutItem = m_pLayout->findItemByName("NameText");
	if (layoutItem)
	{
		m_pEditTextName = layoutItem->getWidget<render::CtrlEditText>();
	}
}

void ue::PropertyPanel::initEvent()
{
}

void ue::PropertyPanel::initText()
{
}
