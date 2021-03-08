#include "UIPropertyNode.h"

ue::UIPropertyNode::UIPropertyNode()
{
}

ue::UIPropertyNode::~UIPropertyNode()
{
}

void ue::UIPropertyNode::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}

	root->findWidgetByName("TypeText", m_pTextType);
	root->findWidgetByName("NameText", m_pEditName);
	root->findWidgetByName("TagText", m_pEditTag);
	root->findWidgetByName("VisibleState", m_pVisibleState);

	root->findWidgetByName("AnchorPointX", m_pEditAnchorPointX);
	root->findWidgetByName("AnchorPointY", m_pEditAnchorPointY);
	root->findWidgetByName("Width", m_pEditSizeW);
	root->findWidgetByName("Height", m_pEditSizeH);
	root->findWidgetByName("ScaleX", m_pEditScaleX);
	root->findWidgetByName("ScaleY", m_pEditScaleY);

	root->findWidgetByName("PosX", m_pEditPosX);
	root->findWidgetByName("PosY", m_pEditPosY);

	root->findWidgetByName("RotationZ", m_pEditRotateZ);

	ADD_TOGGLE_FUNC(m_pVisibleState, ui::CtrlWidget, setVisible);
}

void ue::UIPropertyNode::readWidgetProperty()
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
	if (m_pEditName)
	{
		m_pEditName->setString(m_pTarget->getName());
	}
	if (m_pEditTag)
	{
		m_pEditTag->setString(getCString("%d", m_pTarget->getTag()));
	}

	if (m_pVisibleState)
	{
		m_pVisibleState->setSelectState(m_pTarget->isVisible());
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
}

void ue::UIPropertyNode::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	if (m_pEditName)
	{
		m_pTarget->setName(m_pEditName->getString());
	}

	if (m_pEditTag)
	{
		int value = atoi(m_pEditTag->getString().c_str());
		m_pTarget->setTag(value);
	}

	if (m_pVisibleState)
	{
		m_pTarget->setVisible(m_pVisibleState->isSelected());
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



}
