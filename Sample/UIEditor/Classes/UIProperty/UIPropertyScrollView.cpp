#include "UIPropertyScrollView.h"

ue::UIPropertyScrollView::UIPropertyScrollView()
{
}

ue::UIPropertyScrollView::~UIPropertyScrollView()
{
}

void ue::UIPropertyScrollView::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}
	UIPropertyLayout::initPropertyUI(root);

	root->findWidgetByName("ScrollDirection", m_pScrollDirection);
	root->findWidgetByName("HorizontalScroll", m_pHorizontalScroll);
	root->findWidgetByName("VerticalScroll", m_pVerticalScroll);
	root->findWidgetByName("MoveMultiple", m_pMoveMultiple);

	ADD_TOGGLE_FUNC(m_pHorizontalScroll, ui::CtrlScrollView, setHorizontalScroll);
	ADD_TOGGLE_FUNC(m_pVerticalScroll, ui::CtrlScrollView, setVerticalScroll);
}

void ue::UIPropertyScrollView::readWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	UIPropertyLayout::readWidgetProperty();

	auto pScrollView = m_pTarget->as<ui::CtrlScrollView>();
	if (pScrollView == nullptr)
	{
		return;
	}

	if (m_pHorizontalScroll)
	{
		m_pHorizontalScroll->setSelectState(pScrollView->isHorizontalScroll());
	}

	if (m_pVerticalScroll)
	{
		m_pVerticalScroll->setSelectState(pScrollView->isVerticalScroll());
	}

	if (m_pScrollDirection)
	{
		m_pScrollDirection->setString(getCString("%d", (int)pScrollView->getDirection()));
	}

	if (m_pMoveMultiple)
	{
		m_pMoveMultiple->setString(getCString("%0.2f", pScrollView->getMovingMultiple()));
	}


}

void ue::UIPropertyScrollView::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	auto pScrollView = m_pTarget->as<ui::CtrlScrollView>();
	if (pScrollView == nullptr)
	{
		return;
	}

	if (m_pHorizontalScroll)
	{
		pScrollView->setHorizontalScroll(m_pHorizontalScroll->isSelected());
	}

	if (m_pVerticalScroll)
	{
		pScrollView->setVerticalScroll(m_pVerticalScroll->isSelected());
	}

	if (m_pScrollDirection)
	{
		int value = atoi(m_pScrollDirection->getString().c_str());
		pScrollView->setDirection((ui::ScrollDirection)value);
	}

	if (m_pMoveMultiple)
	{
		float value = atof(m_pMoveMultiple->getString().c_str());

		pScrollView->setMovingMultiple(value);
	}


	UIPropertyLayout::writeWidgetProperty();
}
