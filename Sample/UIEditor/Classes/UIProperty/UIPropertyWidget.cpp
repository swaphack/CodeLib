#include "UIPropertyWidget.h"

ue::UIPropertyWidget::UIPropertyWidget()
{
}

ue::UIPropertyWidget::~UIPropertyWidget()
{
}

void ue::UIPropertyWidget::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}

	root->findWidgetByName("TypeText", m_pTextType);
	root->findWidgetByName("NameText", m_pEditTextName);
	root->findWidgetByName("AnchorPointX", m_pEditAnchorPointX);
	root->findWidgetByName("AnchorPointY", m_pEditAnchorPointY);
	root->findWidgetByName("Width", m_pEditSizeW);
	root->findWidgetByName("Height", m_pEditSizeH);
	root->findWidgetByName("ScaleX", m_pEditScaleX);
	root->findWidgetByName("ScaleY", m_pEditScaleY);

	root->findWidgetByName("PosX", m_pEditPosX);
	root->findWidgetByName("PosY", m_pEditPosY);

	root->findWidgetByName("RotationZ", m_pEditRotateZ);

	root->findWidgetByName("MarginTop", m_pBtnMarginTop);
	root->findWidgetByName("MarginRight", m_pBtnMarginRight);
	root->findWidgetByName("MarginBottom", m_pBtnMarginBottom);
	root->findWidgetByName("MarginLeft", m_pBtnMarginLeft);

	root->findWidgetByName("TopValue", m_pEditTopValue);
	root->findWidgetByName("RightValue", m_pEditRightValue);
	root->findWidgetByName("BottomValue", m_pEditBottomValue);
	root->findWidgetByName("LeftValue", m_pEditLeftValue);

	root->findWidgetByName("WidthValue", m_pEditWidthValue);
	root->findWidgetByName("HeightValue", m_pEditHeightValue);

	if (m_pBtnMarginTop)
	{
		m_pBtnMarginTop->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginTop->setSelectState(!m_pBtnMarginTop->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginRight)
	{
		m_pBtnMarginRight->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginRight->setSelectState(!m_pBtnMarginRight->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginBottom)
	{
		m_pBtnMarginBottom->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginBottom->setSelectState(!m_pBtnMarginBottom->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginLeft)
	{
		m_pBtnMarginLeft->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginLeft->setSelectState(!m_pBtnMarginLeft->isSelected());
			this->saveProperty();
		});
	}
}

void ue::UIPropertyWidget::readWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}
	if (m_pTextType)
	{
		sys::String typeName(typeid(*m_pTarget).name());
		int nIndex = typeName.findLastOf(":");
		if (nIndex >= 0)
		{
			typeName = typeName.subString(nIndex + 1, typeName.getSize() - nIndex);
		}
		m_pTextType->setString(typeName.getString());
	}
	if (m_pEditTextName)
	{
		m_pEditTextName->setString(m_pTarget->getName());
	}
	if (m_pEditAnchorPointX)
	{
		m_pEditAnchorPointX->setString(getCString("%0.2f", m_pTarget->getAnchorPointX()));
	}
	if (m_pEditAnchorPointY)
	{
		m_pEditAnchorPointY->setString(getCString("%0.2f", m_pTarget->getAnchorPointY()));
	}
	if (m_pEditSizeW)
	{
		m_pEditSizeW->setString(getCString("%0.2f", m_pTarget->getWidth()));
	}
	if (m_pEditSizeH)
	{
		m_pEditSizeH->setString(getCString("%0.2f", m_pTarget->getHeight()));
	}

	if (m_pEditScaleX)
	{
		m_pEditScaleX->setString(getCString("%0.2f", m_pTarget->getScaleX()));
	}
	if (m_pEditScaleY)
	{
		m_pEditScaleY->setString(getCString("%0.2f", m_pTarget->getScaleY()));
	}

	if (m_pEditPosX)
	{
		m_pEditPosX->setString(getCString("%0.2f", m_pTarget->getPositionX()));
	}
	if (m_pEditPosY)
	{
		m_pEditPosY->setString(getCString("%0.2f", m_pTarget->getPositionY()));
	}

	if (m_pEditRotateZ)
	{
		m_pEditRotateZ->setString(getCString("%0.2f", m_pTarget->getRotationZ()));
	}

	auto layoutItem = ui::UIProxy::getLayoutItem(m_pTarget);
	if (layoutItem == nullptr)
	{
		return;
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

void ue::UIPropertyWidget::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	if (m_pEditTextName)
	{
		m_pTarget->setName(m_pEditTextName->getString());
	}
	if (m_pEditAnchorPointX)
	{
		float value = atof(m_pEditAnchorPointX->getString().c_str());
		m_pTarget->setAnchorPointX(value);
	}
	if (m_pEditAnchorPointY)
	{
		float value = atof(m_pEditAnchorPointY->getString().c_str());
		m_pTarget->setAnchorPointY(value);
	}
	if (m_pEditSizeW)
	{
		float value = atof(m_pEditSizeW->getString().c_str());
		m_pTarget->setWidth(value);
	}
	if (m_pEditSizeH)
	{
		float value = atof(m_pEditSizeH->getString().c_str());
		m_pTarget->setHeight(value);
	}

	if (m_pEditScaleX)
	{
		float value = atof(m_pEditScaleX->getString().c_str());
		m_pTarget->setScaleX(value);
	}
	if (m_pEditScaleY)
	{
		float value = atof(m_pEditScaleY->getString().c_str());
		m_pTarget->setScaleY(value);
	}

	if (m_pEditPosX)
	{
		float value = atof(m_pEditPosX->getString().c_str());
		m_pTarget->setPositionX(value);
	}
	if (m_pEditPosY)
	{
		float value = atof(m_pEditPosY->getString().c_str());
		m_pTarget->setPositionY(value);
	}

	if (m_pEditRotateZ)
	{
		float value = atof(m_pEditRotateZ->getString().c_str());
		m_pTarget->setRotationZ(value);
	}

	auto layoutItem = ui::UIProxy::getLayoutItem(m_pTarget);

	if (m_pBtnMarginTop)
	{
		layoutItem->getMarginState().Top = m_pBtnMarginTop->isSelected();
	}

	if (m_pBtnMarginRight)
	{
		layoutItem->getMarginState().Right = m_pBtnMarginRight->isSelected();
	}

	if (m_pBtnMarginBottom)
	{
		layoutItem->getMarginState().Bottom = m_pBtnMarginBottom->isSelected();
	}

	if (m_pBtnMarginLeft)
	{
		layoutItem->getMarginState().Left = m_pBtnMarginLeft->isSelected();
	}

	if (m_pEditTopValue)
	{
		std::string strText = m_pEditTopValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setTop(number);
	}

	if (m_pEditRightValue)
	{
		std::string strText = m_pEditRightValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setRight(number);
	}

	if (m_pEditBottomValue)
	{
		std::string strText = m_pEditBottomValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setBottom(number);
	}

	if (m_pEditLeftValue)
	{
		std::string strText = m_pEditLeftValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setLeft(number);
	}

	if (m_pEditWidthValue)
	{
		std::string strText = m_pEditWidthValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getSize().setWidth(number);
	}

	if (m_pEditHeightValue)
	{
		std::string strText = m_pEditHeightValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getSize().setHeight(number);
	}

	layoutItem->refresh();

	this->readWidgetProperty();
}
