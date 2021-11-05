#include "UIPropertyTableView.h"

ue::UIPropertyTableView::UIPropertyTableView()
{
}

ue::UIPropertyTableView::~UIPropertyTableView()
{
}

void ue::UIPropertyTableView::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}
	UIPropertyScrollView::initPropertyUI(root);
}

void ue::UIPropertyTableView::readWidgetProperty()
{
	if (m_pTarget == nullptr) return;

	UIPropertyScrollView::readWidgetProperty();
}

void ue::UIPropertyTableView::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	UIPropertyScrollView::writeWidgetProperty();
}
