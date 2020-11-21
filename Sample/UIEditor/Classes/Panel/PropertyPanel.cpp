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

	if (m_pEditRotateZ)
	{
		m_pEditRotateZ->setString(getCString("%f", pWidget->getRotationZ()));
	}

	if (m_pBtnMarginTop)
	{
		m_pBtnMarginTop->setSelect(m_pTargetItem->getMarginState().Top);
	}

	if (m_pBtnMarginRight)
	{
		m_pBtnMarginRight->setSelect(m_pTargetItem->getMarginState().Right);
	}

	if (m_pBtnMarginBottom)
	{
		m_pBtnMarginBottom->setSelect(m_pTargetItem->getMarginState().Bottom);
	}

	if (m_pBtnMarginLeft)
	{
		m_pBtnMarginLeft->setSelect(m_pTargetItem->getMarginState().Left);
	}

	sys::CSSMargin& margin = m_pTargetItem->getMargin();
	if (m_pEditTopValue)
	{
		std::string strPercent;
		if (m_pTargetItem->getMargin().getTop().getType() == sys::NumberType::Percent)
		{
			strPercent = "%";
		}

		m_pEditTopValue->setString(getCString("%f%s", margin.getTop().getValue(), strPercent));
	}

	if (m_pEditRightValue)
	{
		std::string strPercent;
		if (m_pTargetItem->getMargin().getRight().getType() == sys::NumberType::Percent)
		{
			strPercent = "%";
		}

		m_pEditRightValue->setString(getCString("%f%s", margin.getRight().getValue(), strPercent));
	}

	if (m_pEditBottomValue)
	{
		std::string strPercent;
		if (m_pTargetItem->getMargin().getBottom().getType() == sys::NumberType::Percent)
		{
			strPercent = "%";
		}

		m_pEditBottomValue->setString(getCString("%f%s", margin.getBottom().getValue(), strPercent));
	}

	if (m_pEditLeftValue)
	{
		std::string strPercent;
		if (m_pTargetItem->getMargin().getLeft().getType() == sys::NumberType::Percent)
		{
			strPercent = "%";
		}

		m_pEditLeftValue->setString(getCString("%f%s", margin.getLeft().getValue(), strPercent));
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

	if (m_pEditRotateZ)
	{
		float value = atof(m_pEditRotateZ->getString().c_str());
		pWidget->setRotationZ(value);
	}

	if (m_pBtnMarginTop)
	{
		m_pTargetItem->getMarginState().Top = m_pBtnMarginTop->isSelected();
	}

	if (m_pBtnMarginRight)
	{
		m_pTargetItem->getMarginState().Right = m_pBtnMarginRight->isSelected();
	}

	if (m_pBtnMarginBottom)
	{
		m_pTargetItem->getMarginState().Bottom = m_pBtnMarginBottom->isSelected();
	}

	if (m_pBtnMarginLeft)
	{
		m_pTargetItem->getMarginState().Left = m_pBtnMarginLeft->isSelected();
	}

	if (m_pEditTopValue)
	{
		sys::NumberType eType = sys::NumberType::Fixed;
		sys::String strText = m_pEditTopValue->getString();
		sys::String strValue = strText;
		if (strText.endWith("%"))
		{
			eType = sys::NumberType::Percent;
			strValue = strText.subString(0, strText.findLastOf("%"));
		}

		float value = atof(strValue.getString());
		m_pTargetItem->getMargin().setTop(eType, value);
	}

	if (m_pEditRightValue)
	{
		sys::NumberType eType = sys::NumberType::Fixed;
		sys::String strText = m_pEditRightValue->getString();
		sys::String strValue = strText;
		if (strText.endWith("%"))
		{
			eType = sys::NumberType::Percent;
			strValue = strText.subString(0, strText.findLastOf("%"));
		}

		float value = atof(strValue.getString());
		m_pTargetItem->getMargin().setRight(eType, value);
	}

	if (m_pEditBottomValue)
	{
		sys::NumberType eType = sys::NumberType::Fixed;
		sys::String strText = m_pEditBottomValue->getString();
		sys::String strValue = strText;
		if (strText.endWith("%"))
		{
			eType = sys::NumberType::Percent;
			strValue = strText.subString(0, strText.findLastOf("%"));
		}

		float value = atof(strValue.getString());
		m_pTargetItem->getMargin().setBottom(eType, value);
	}

	if (m_pEditLeftValue)
	{
		sys::NumberType eType = sys::NumberType::Fixed;
		sys::String strText = m_pEditLeftValue->getString();
		sys::String strValue = strText;
		if (strText.endWith("%")) 
		{
			eType = sys::NumberType::Percent;
			strValue = strText.subString(0, strText.findLastOf("%"));
		}
		
		float value = atof(strValue.getString());
		m_pTargetItem->getMargin().setLeft(eType, value);
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

	m_pLayout->findWidgetByName("RotationZ", m_pEditRotateZ);

	m_pLayout->findWidgetByName("MarginTop", m_pBtnMarginTop);
	m_pLayout->findWidgetByName("MarginRight", m_pBtnMarginRight);
	m_pLayout->findWidgetByName("MarginBottom", m_pBtnMarginBottom);
	m_pLayout->findWidgetByName("MarginLeft", m_pBtnMarginLeft);

	m_pLayout->findWidgetByName("TopValue", m_pEditTopValue);
	m_pLayout->findWidgetByName("RightValue", m_pEditRightValue);
	m_pLayout->findWidgetByName("BottomValue", m_pEditTopValue);
	m_pLayout->findWidgetByName("LeftValue", m_pEditLeftValue);

	if (m_pBtnMarginTop)
	{
		m_pBtnMarginTop->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginTop->setSelect(!m_pBtnMarginTop->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginRight)
	{
		m_pBtnMarginRight->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginRight->setSelect(!m_pBtnMarginRight->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginBottom)
	{
		m_pBtnMarginBottom->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginBottom->setSelect(!m_pBtnMarginBottom->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginLeft)
	{
		m_pBtnMarginLeft->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginLeft->setSelect(!m_pBtnMarginLeft->isSelected());
			this->saveProperty();
		});
	}
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
