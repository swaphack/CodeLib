#include "UIPropertyButton.h"

ue::UIPropertyButton::UIPropertyButton()
{
}

ue::UIPropertyButton::~UIPropertyButton()
{
}

void ue::UIPropertyButton::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}

	UIPropertyWidget::initPropertyUI(root);


	root->findWidgetByName("FontText", m_pFontText);
	root->findWidgetByName("FontPath", m_pFontPath);
	root->findWidgetByName("FontSize", m_pFontSize);
	root->findWidgetByName("FontHorizontalType", m_pFontHorizontalType);
	root->findWidgetByName("FontVerticalType", m_pFontVerticalType);
	root->findWidgetByName("NormalImagePath", m_pNormalImagePath);
	root->findWidgetByName("SelectedImagePath", m_pSelectedImagePath);
	root->findWidgetByName("DisabledImagePath", m_pDisabledImagePath);


}

void ue::UIPropertyButton::readWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}
	UIPropertyWidget::readWidgetProperty();

	auto pButton = m_pTarget->as<ui::CtrlButton>();
	if (pButton == nullptr)
	{
		return;
	}

	if (m_pFontText)
	{
		m_pFontText->setString(pButton->getString());
	}

	if (m_pFontPath)
	{
		m_pFontPath->setString(pButton->getFontPath());
	}

	if (m_pFontSize)
	{
		m_pFontSize->setString(getCString("%0.2f", pButton->getFontSize()));
	}

	if (m_pFontHorizontalType)
	{
		m_pFontHorizontalType->setString(getCString("%d", (int)pButton->getTextHorizontalAlignment()));
	}

	if (m_pFontVerticalType)
	{
		m_pFontVerticalType->setString(getCString("%d", (int)pButton->getTextVerticalAlignment()));
	}
}

void ue::UIPropertyButton::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	auto pButton = m_pTarget->as<ui::CtrlButton>();
	if (pButton == nullptr)
	{
		return;
	}

	if (m_pFontText)
	{
		pButton->setString(m_pFontText->getString());
	}

	if (m_pFontPath)
	{
		pButton->setFontPath(m_pFontPath->getString());
	}

	if (m_pFontSize)
	{
		int value = atoi(m_pFontSize->getString().c_str());
		pButton->setFontSize(value);
	}

	if (m_pFontHorizontalType)
	{
		int value = atoi(m_pFontHorizontalType->getString().c_str());
		pButton->setTextHorizontalAlignment((sys::HorizontalAlignment)value);
	}

	if (m_pFontVerticalType)
	{
		int value = atoi(m_pFontVerticalType->getString().c_str());
		pButton->setTextVerticalAlignment((sys::VerticalAlignment)value);
	}

	UIPropertyWidget::writeWidgetProperty();
}
