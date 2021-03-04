#include "UIPropertyEditText.h"

ue::UIPropertyEditText::UIPropertyEditText()
{
}

ue::UIPropertyEditText::~UIPropertyEditText()
{
}

void ue::UIPropertyEditText::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}

	UIPropertyWidget::initPropertyUI(root);

	root->findWidgetByName("FontText", m_pFontText);
	root->findWidgetByName("FontPlaceholderText", m_pFontPlaceholderText);
	root->findWidgetByName("FontPath", m_pFontPath);
	root->findWidgetByName("FontSize", m_pFontSize);
	root->findWidgetByName("FontHorizontalType", m_pFontHorizontalType);
	root->findWidgetByName("FontVerticalType", m_pFontVerticalType);
	root->findWidgetByName("MultiLine", m_pMultiLine);

	ADD_CLICK_FUNC(m_pMultiLine, ui::CtrlEditText, setMultiLine);
}

void ue::UIPropertyEditText::readWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	UIPropertyWidget::readWidgetProperty();

	auto pEditText = m_pTarget->as<ui::CtrlEditText>();
	if (pEditText == nullptr)
	{
		return;
	}

	if (m_pFontText)
	{
		m_pFontText->setString(pEditText->getString());
	}

	if (m_pFontPlaceholderText)
	{
		m_pFontPlaceholderText->setString(pEditText->getPlaceholderString());
	}

	if (m_pFontPath)
	{
		m_pFontPath->setString(pEditText->getFontPath());
	}

	if (m_pFontSize)
	{
		m_pFontSize->setString(getCString("%0.2f", pEditText->getFontSize()));
	}

	if (m_pFontHorizontalType)
	{
		m_pFontHorizontalType->setString(getCString("%d", (int)pEditText->getTextHorizontalAlignment()));
	}

	if (m_pFontVerticalType)
	{
		m_pFontVerticalType->setString(getCString("%d", (int)pEditText->getTextVerticalAlignment()));
	}

	if (m_pMultiLine)
	{
		m_pMultiLine->setSelectState(pEditText->isMultiLine());
	}

}

void ue::UIPropertyEditText::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	auto pEditText = m_pTarget->as<ui::CtrlEditText>();
	if (pEditText == nullptr)
	{
		return;
	}

	if (m_pFontText)
	{
		pEditText->setString(m_pFontText->getString());
	}

	if (m_pFontPlaceholderText)
	{
		pEditText->setPlaceholderString(m_pFontPlaceholderText->getString());
	}

	if (m_pFontPath)
	{
		pEditText->setFontPath(m_pFontPath->getString());
	}

	if (m_pFontSize)
	{
		int value = atoi(m_pFontSize->getString().c_str());
		pEditText->setFontSize(value);
	}

	if (m_pFontHorizontalType)
	{
		int value = atoi(m_pFontHorizontalType->getString().c_str());
		pEditText->setTextHorizontalAlignment((sys::HorizontalAlignment)value);
	}

	if (m_pFontVerticalType)
	{
		int value = atoi(m_pFontVerticalType->getString().c_str());
		pEditText->setTextVerticalAlignment((sys::VerticalAlignment)value);
	}

	if (m_pMultiLine)
	{
		pEditText->setMultiLine(m_pMultiLine->isSelected());
	}

	UIPropertyWidget::writeWidgetProperty();

}
