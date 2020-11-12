#include "PropertyPanel.h"
#include "PanelEvent.h"

ue::PropertyPanel::PropertyPanel()
{
}

ue::PropertyPanel::~PropertyPanel()
{
	G_KEYBOARDMANAGER->removeTargetAllEvents(this);
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
			m_pTargetItem = (ui::LayoutItem*)evt->getUserData();
			this->loadProperty();
		}
	});


	return true;
}

void ue::PropertyPanel::loadProperty()
{
	if (m_pTargetItem == nullptr || m_pTargetItem->getWidget() == nullptr)
	{
		return;
	}
	auto pWidget = m_pTargetItem->getWidget();

	if (m_pTextType)
	{
		sys::String typeName(typeid(*pWidget).name());
		int nIndex = typeName.findLastOf(":");
		if (nIndex >= 0)
		{
			typeName = typeName.subString(nIndex + 1, typeName.getSize() - nIndex);
		}
		m_pTextType->setString(typeName.getString());
	}
	if (m_pEditTextName)
	{
		m_pEditTextName->setString(m_pTargetItem->getName());
	}
	if (m_pEditAnchorPointX)
	{
		m_pEditAnchorPointX->setString(getCString("%f", pWidget->getAnchorPointX()));
	}
	if (m_pEditAnchorPointY)
	{
		m_pEditAnchorPointY->setString(getCString("%f", pWidget->getAnchorPointY()));
	}
	if (m_pEditSizeW)
	{
		m_pEditSizeW->setString(getCString("%f", pWidget->getWidth()));
	}
	if (m_pEditSizeH)
	{
		m_pEditSizeH->setString(getCString("%f", pWidget->getHeight()));
	}

	if (m_pEditScaleX)
	{
		m_pEditScaleX->setString(getCString("%f", pWidget->getScaleX()));
	}
	if (m_pEditScaleY)
	{
		m_pEditScaleY->setString(getCString("%f", pWidget->getScaleY()));
	}

	if (m_pEditPosX)
	{
		m_pEditPosX->setString(getCString("%f", pWidget->getPositionX()));
	}
	if (m_pEditPosY)
	{
		m_pEditPosY->setString(getCString("%f", pWidget->getPositionY()));
	}
}

void ue::PropertyPanel::saveProperty()
{
	if (m_pTargetItem == nullptr || m_pTargetItem->getWidget() == nullptr)
	{
		return;
	}
	auto pWidget = m_pTargetItem->getWidget();

	if (m_pEditTextName)
	{
		m_pTargetItem->setName(m_pEditTextName->getString());
	}
	if (m_pEditAnchorPointX)
	{
		float value = atof(m_pEditAnchorPointX->getString().c_str());
		pWidget->setAnchorPointX(value);
	}
	if (m_pEditAnchorPointY)
	{
		float value = atof(m_pEditAnchorPointY->getString().c_str());
		pWidget->setAnchorPointY(value);
	}
	if (m_pEditSizeW)
	{
		float value = atof(m_pEditSizeW->getString().c_str());
		pWidget->setWidth(value);
	}
	if (m_pEditSizeH)
	{
		float value = atof(m_pEditSizeH->getString().c_str());
		pWidget->setHeight(value);
	}

	if (m_pEditScaleX)
	{
		float value = atof(m_pEditScaleX->getString().c_str());
		pWidget->setScaleX(value);
	}
	if (m_pEditScaleY)
	{
		float value = atof(m_pEditScaleY->getString().c_str());
		pWidget->setScaleY(value);
	}

	if (m_pEditPosX)
	{
		float value = atof(m_pEditPosX->getString().c_str());
		pWidget->setPositionX(value);
	}
	if (m_pEditPosY)
	{
		float value = atof(m_pEditPosY->getString().c_str());
		pWidget->setPositionY(value);
	}
}

void ue::PropertyPanel::initUI()
{
	m_pLayout->findWidgetByName("TypeText", m_pTextType);
	m_pLayout->findWidgetByName("NameText", m_pEditTextName);
	m_pLayout->findWidgetByName("AnchorPointX", m_pEditAnchorPointX);
	m_pLayout->findWidgetByName("AnchorPointY", m_pEditAnchorPointY);
	m_pLayout->findWidgetByName("Width", m_pEditSizeW);
	m_pLayout->findWidgetByName("Height", m_pEditSizeH);
	m_pLayout->findWidgetByName("ScaleX", m_pEditScaleX);
	m_pLayout->findWidgetByName("ScaleY", m_pEditScaleY);

	m_pLayout->findWidgetByName("PosX", m_pEditPosX);
	m_pLayout->findWidgetByName("PosY", m_pEditPosY);
}

void ue::PropertyPanel::initEvent()
{
	G_KEYBOARDMANAGER->addKeyboardFunc(this, this, [this](Node* object, sys::BoardKey key, sys::ButtonStatus status){
		if (this != object)
		{
			return;
		}

		if (key == sys::BoardKey::KRETURN)
		{
			this->saveProperty();
		}
	});
}

void ue::PropertyPanel::initText()
{
}
