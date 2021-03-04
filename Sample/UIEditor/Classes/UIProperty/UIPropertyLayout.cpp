#include "UIPropertyLayout.h"

ue::UIPropertyLayout::UIPropertyLayout()
{
}

ue::UIPropertyLayout::~UIPropertyLayout()
{
}

void ue::UIPropertyLayout::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}

	UIPropertyWidget::initPropertyUI(root);

	root->findWidgetByName("ShowImage", m_pShowImage);
	root->findWidgetByName("ShowMask", m_pShowMask);
	root->findWidgetByName("ImagePath", m_pImagePath);

	ADD_CLICK_FUNC(m_pShowImage, ui::CtrlLayout, setBackgroudImageVisible);
	ADD_CLICK_FUNC(m_pShowMask, ui::CtrlLayout, setBackgroudMaskVisible);
}

void ue::UIPropertyLayout::readWidgetProperty()
{
	if (m_pTarget == nullptr) return;

	UIPropertyWidget::readWidgetProperty();

	auto pLayout = m_pTarget->as<ui::CtrlLayout>();
	if (pLayout == nullptr)
	{
		return;
	}

	if (m_pShowImage)
	{
		m_pShowImage->setSelectState(pLayout->isBackgroudImageVisible());
	}
	if (m_pShowMask)
	{
		m_pShowMask->setSelectState(pLayout->isBackgroudMaskVisible());
	}
	if (m_pImagePath)
	{
		m_pImagePath->setString(pLayout->getBackgroundImagePath());
	}

}

void ue::UIPropertyLayout::writeWidgetProperty()
{
	if (m_pTarget == nullptr) return;
	auto pLayout = m_pTarget->as<ui::CtrlLayout>();
	if (pLayout == nullptr)
	{
		return;
	}

	if (m_pShowImage)
	{
		pLayout->setBackgroudImageVisible(m_pShowImage->isSelected());
	}

	if (m_pShowMask)
	{
		pLayout->setBackgroudMaskVisible(m_pShowMask->isSelected());
	}

	if (m_pImagePath)
	{
		pLayout->setBackgroundImagePath(m_pImagePath->getString());
	}


	UIPropertyWidget::writeWidgetProperty();


}
