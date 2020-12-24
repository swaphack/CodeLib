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

	G_PANELEVT->addEventListener(PANEL_SELECT_WIDGET, this, [this](const sys::Event* evt) {
		if (evt)
		{
			m_pTargetItem = (ui::CtrlWidget*)evt->getUserData();
			this->loadProperty();
		}
	});


	return true;
}

void ue::PropertyPanel::loadProperty()
{
	if (m_pTargetItem == nullptr || m_pTargetItem->getLayoutItem() == nullptr)
	{
		return;
	}
	auto layoutItem = m_pTargetItem->getLayoutItem();

	if (m_pTextType)
	{
		sys::String typeName(typeid(*m_pTargetItem).name());
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
		m_pEditAnchorPointX->setString(getCString("%0.2f", m_pTargetItem->getAnchorPointX()));
	}
	if (m_pEditAnchorPointY)
	{
		m_pEditAnchorPointY->setString(getCString("%0.2f", m_pTargetItem->getAnchorPointY()));
	}
	if (m_pEditSizeW)
	{
		m_pEditSizeW->setString(getCString("%0.2f", m_pTargetItem->getWidth()));
	}
	if (m_pEditSizeH)
	{
		m_pEditSizeH->setString(getCString("%0.2f", m_pTargetItem->getHeight()));
	}

	if (m_pEditScaleX)
	{
		m_pEditScaleX->setString(getCString("%0.2f", m_pTargetItem->getScaleX()));
	}
	if (m_pEditScaleY)
	{
		m_pEditScaleY->setString(getCString("%0.2f", m_pTargetItem->getScaleY()));
	}

	if (m_pEditPosX)
	{
		m_pEditPosX->setString(getCString("%0.2f", m_pTargetItem->getPositionX()));
	}
	if (m_pEditPosY)
	{
		m_pEditPosY->setString(getCString("%0.2f", m_pTargetItem->getPositionY()));
	}

	if (m_pEditRotateZ)
	{
		m_pEditRotateZ->setString(getCString("%0.2f", m_pTargetItem->getRotationZ()));
	}

	if (m_pBtnMarginTop)
	{
		m_pBtnMarginTop->setSelectState(layoutItem->getMarginState().Top);
	}

	if (m_pBtnMarginRight)
	{
		m_pBtnMarginRight->setSelectState(layoutItem->getMarginState().Right);
	}

	if (m_pBtnMarginBottom)
	{
		m_pBtnMarginBottom->setSelectState(layoutItem->getMarginState().Bottom);
	}

	if (m_pBtnMarginLeft)
	{
		m_pBtnMarginLeft->setSelectState(layoutItem->getMarginState().Left);
	}

	const sys::CSSMargin& margin = layoutItem->getMargin();
	const sys::CSSSize& size = layoutItem->getSize();

	if (m_pEditTopValue)
	{
		m_pEditTopValue->setString(margin.getTop().toString(2));
	}

	if (m_pEditRightValue)
	{
		m_pEditRightValue->setString(margin.getRight().toString(2));
	}

	if (m_pEditBottomValue)
	{
		m_pEditBottomValue->setString(margin.getBottom().toString(2));
	}

	if (m_pEditLeftValue)
	{
		m_pEditLeftValue->setString(margin.getLeft().toString(2));
	}

	if (m_pEditWidthValue)
	{
		m_pEditWidthValue->setString(size.getWidth().toString(2));
	}

	if (m_pEditHeightValue)
	{
		m_pEditHeightValue->setString(size.getHeight().toString(2));
	}
}

void ue::PropertyPanel::saveProperty()
{
	if (m_pTargetItem == nullptr || m_pTargetItem->getLayoutItem() == nullptr)
	{
		return;
	}
	auto playoutItem = m_pTargetItem->getLayoutItem();

	if (m_pEditTextName)
	{
		m_pTargetItem->setName(m_pEditTextName->getString());
	}
	if (m_pEditAnchorPointX)
	{
		float value = atof(m_pEditAnchorPointX->getString().c_str());
		m_pTargetItem->setAnchorPointX(value);
	}
	if (m_pEditAnchorPointY)
	{
		float value = atof(m_pEditAnchorPointY->getString().c_str());
		m_pTargetItem->setAnchorPointY(value);
	}
	if (m_pEditSizeW)
	{
		float value = atof(m_pEditSizeW->getString().c_str());
		m_pTargetItem->setWidth(value);
	}
	if (m_pEditSizeH)
	{
		float value = atof(m_pEditSizeH->getString().c_str());
		m_pTargetItem->setHeight(value);
	}

	if (m_pEditScaleX)
	{
		float value = atof(m_pEditScaleX->getString().c_str());
		m_pTargetItem->setScaleX(value);
	}
	if (m_pEditScaleY)
	{
		float value = atof(m_pEditScaleY->getString().c_str());
		m_pTargetItem->setScaleY(value);
	}

	if (m_pEditPosX)
	{
		float value = atof(m_pEditPosX->getString().c_str());
		m_pTargetItem->setPositionX(value);
	}
	if (m_pEditPosY)
	{
		float value = atof(m_pEditPosY->getString().c_str());
		m_pTargetItem->setPositionY(value);
	}

	if (m_pEditRotateZ)
	{
		float value = atof(m_pEditRotateZ->getString().c_str());
		m_pTargetItem->setRotationZ(value);
	}

	if (m_pBtnMarginTop)
	{
		playoutItem->getMarginState().Top = m_pBtnMarginTop->isSelected();
	}

	if (m_pBtnMarginRight)
	{
		playoutItem->getMarginState().Right = m_pBtnMarginRight->isSelected();
	}

	if (m_pBtnMarginBottom)
	{
		playoutItem->getMarginState().Bottom = m_pBtnMarginBottom->isSelected();
	}

	if (m_pBtnMarginLeft)
	{
		playoutItem->getMarginState().Left = m_pBtnMarginLeft->isSelected();
	}

	if (m_pEditTopValue)
	{
		std::string strText = m_pEditTopValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		playoutItem->getMargin().setTop(number);
	}

	if (m_pEditRightValue)
	{
		std::string strText = m_pEditRightValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		playoutItem->getMargin().setRight(number);
	}

	if (m_pEditBottomValue)
	{
		std::string strText = m_pEditBottomValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		playoutItem->getMargin().setBottom(number);
	}

	if (m_pEditLeftValue)
	{
		std::string strText = m_pEditLeftValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		playoutItem->getMargin().setLeft(number);
	}

	if (m_pEditWidthValue)
	{
		std::string strText = m_pEditWidthValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		playoutItem->getSize().setWidth(number);
	}

	if (m_pEditHeightValue)
	{
		std::string strText = m_pEditHeightValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		playoutItem->getSize().setHeight(number);
	}

	playoutItem->refresh();

	this->loadProperty();
}

void ue::PropertyPanel::initUI()
{
	m_pRootWidget->findWidgetByName("TypeText", m_pTextType);
	m_pRootWidget->findWidgetByName("NameText", m_pEditTextName);
	m_pRootWidget->findWidgetByName("AnchorPointX", m_pEditAnchorPointX);
	m_pRootWidget->findWidgetByName("AnchorPointY", m_pEditAnchorPointY);
	m_pRootWidget->findWidgetByName("Width", m_pEditSizeW);
	m_pRootWidget->findWidgetByName("Height", m_pEditSizeH);
	m_pRootWidget->findWidgetByName("ScaleX", m_pEditScaleX);
	m_pRootWidget->findWidgetByName("ScaleY", m_pEditScaleY);
	
	m_pRootWidget->findWidgetByName("PosX", m_pEditPosX);
	m_pRootWidget->findWidgetByName("PosY", m_pEditPosY);
	
	m_pRootWidget->findWidgetByName("RotationZ", m_pEditRotateZ);
	
	m_pRootWidget->findWidgetByName("MarginTop", m_pBtnMarginTop);
	m_pRootWidget->findWidgetByName("MarginRight", m_pBtnMarginRight);
	m_pRootWidget->findWidgetByName("MarginBottom", m_pBtnMarginBottom);
	m_pRootWidget->findWidgetByName("MarginLeft", m_pBtnMarginLeft);
	
	m_pRootWidget->findWidgetByName("TopValue", m_pEditTopValue);
	m_pRootWidget->findWidgetByName("RightValue", m_pEditRightValue);
	m_pRootWidget->findWidgetByName("BottomValue", m_pEditBottomValue);
	m_pRootWidget->findWidgetByName("LeftValue", m_pEditLeftValue);
	
	m_pRootWidget->findWidgetByName("WidthValue", m_pEditWidthValue);
	m_pRootWidget->findWidgetByName("HeightValue", m_pEditHeightValue);

	if (m_pBtnMarginTop)
	{
		m_pBtnMarginTop->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginTop->setSelectState(!m_pBtnMarginTop->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginRight)
	{
		m_pBtnMarginRight->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginRight->setSelectState(!m_pBtnMarginRight->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginBottom)
	{
		m_pBtnMarginBottom->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginBottom->setSelectState(!m_pBtnMarginBottom->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginLeft)
	{
		m_pBtnMarginLeft->addClickFunc([this](CtrlWidget* target) {
			m_pBtnMarginLeft->setSelectState(!m_pBtnMarginLeft->isSelected());
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
