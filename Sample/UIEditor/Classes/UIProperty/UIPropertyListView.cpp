#include "UIPropertyListView.h"

ue::UIPropertyListView::UIPropertyListView()
{
}

ue::UIPropertyListView::~UIPropertyListView()
{
}

void ue::UIPropertyListView::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}
	UIPropertyScrollView::initPropertyUI(root);

	root->findWidgetByName("ScrollDirection", m_pScrollDirection);
	root->findWidgetByName("WidthValue", m_pWidthValue);
	root->findWidgetByName("HeightValue", m_pHeightValue);

	root->findWidgetByName("UseItemSize", m_pUseItemSize);
	root->findWidgetByName("ShowInCenter", m_pShowInCenter);

	ADD_TOGGLE_FUNC(m_pUseItemSize, ui::CtrlListView, setUseItemSize);
	ADD_TOGGLE_FUNC(m_pShowInCenter, ui::CtrlListView, setShowInCenter);
}

void ue::UIPropertyListView::readWidgetProperty()
{
	if (m_pTarget == nullptr) return;

	UIPropertyScrollView::readWidgetProperty();

	auto pListView = m_pTarget->as<ui::CtrlListView>();
	if (pListView == nullptr)
	{
		return;
	}

	if (m_pScrollDirection)
	{
		m_pScrollDirection->setString(getCString("%d", (int)pListView->getDirection()));
	}

	if (m_pWidthValue)
	{
		m_pWidthValue->setString(pListView->getItemSize().getWidth().toString(2));
	}

	if (m_pHeightValue)
	{
		m_pHeightValue->setString(pListView->getItemSize().getHeight().toString(2));
	}
	if (m_pUseItemSize)
	{
		m_pUseItemSize->setSelectState(pListView->isUseItemSize());
	}
	if (m_pShowInCenter)
	{
		m_pShowInCenter->setSelectState(pListView->isShowInCenter());
	}
}

void ue::UIPropertyListView::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	auto pListView = m_pTarget->as<ui::CtrlListView>();
	if (pListView == nullptr)
	{
		return;
	}

	if (m_pScrollDirection)
	{
		int value = atoi(m_pScrollDirection->getString().c_str());
		pListView->setDirection((ui::ScrollDirection)value);
	}

	sys::CSSSize size;
	if (m_pWidthValue)
	{
		std::string strText = m_pWidthValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		size.setWidth(number);
	}

	if (m_pHeightValue)
	{
		std::string strText = m_pHeightValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		size.setHeight(number);
	}

	pListView->setItemSize(size);

	if (m_pUseItemSize)
	{
		m_pUseItemSize->setSelectState(pListView->isUseItemSize());
	}
	if (m_pShowInCenter)
	{
		m_pShowInCenter->setSelectState(pListView->isShowInCenter());
	}



	UIPropertyScrollView::writeWidgetProperty();
}
