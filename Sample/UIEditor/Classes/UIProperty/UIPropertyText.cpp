#include "UIPropertyText.h"

ue::UIPropertyText::UIPropertyText()
{
}

ue::UIPropertyText::~UIPropertyText()
{
}

void ue::UIPropertyText::initPropertyUI(ui::CtrlWidget* root)
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
}

void ue::UIPropertyText::readWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}
	UIPropertyWidget::readWidgetProperty();

	auto pText = m_pTarget->as<ui::CtrlText>();
	if (pText == nullptr)
	{
		return;
	}

	if (m_pFontText)
	{
		m_pFontText->setString(pText->getString());
	}

	if (m_pFontPath)
	{
		m_pFontPath->setString(pText->getFontPath());
	}

	if (m_pFontSize)
	{
		m_pFontSize->setString(getCString("%0.2f", pText->getFontSize()));
	}

	if (m_pFontHorizontalType)
	{
		m_pFontHorizontalType->setString(getCString("%d", (int)pText->getTextHorizontalAlignment()));
	}

	if (m_pFontVerticalType)
	{
		m_pFontVerticalType->setString(getCString("%d", (int)pText->getTextVerticalAlignment()));
	}

}

void ue::UIPropertyText::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}
	auto pText = m_pTarget->as<ui::CtrlText>();
	if (pText == nullptr)
	{
		return;
	}

	if (m_pFontText)
	{
		pText->setString(m_pFontText->getString());
	}

	if (m_pFontPath)
	{
		pText->setFontPath(m_pFontPath->getString());
	}

	if (m_pFontSize)
	{
		int value = atoi(m_pFontSize->getString().c_str());
		pText->setFontSize(value);
	}

	if (m_pFontHorizontalType)
	{
		int value = atoi(m_pFontHorizontalType->getString().c_str());
		pText->setTextHorizontalAlignment((sys::HorizontalAlignment)value);
	}

	if (m_pFontVerticalType)
	{
		int value = atoi(m_pFontVerticalType->getString().c_str());
		pText->setTextVerticalAlignment((sys::VerticalAlignment)value);
	}


	UIPropertyWidget::writeWidgetProperty();


}
