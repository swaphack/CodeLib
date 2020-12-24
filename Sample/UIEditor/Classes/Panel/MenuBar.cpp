#include "MenuBar.h"
#include "PopMenu.h"

ue::MenuBar::MenuBar()
{
}

ue::MenuBar::~MenuBar()
{
}

void ue::MenuBar::initUI()
{
	if (m_pRootWidget == nullptr) return;
	ui::CtrlWidget* item = nullptr;
	if (m_pRootWidget->findWidgetByName("file", item))
	{
		item->addClickFunc([item](render::Node* node) {
			showWithTarget<PopMenu>(item, sys::CSSDirection::Bottom);
		});
	}

	if (m_pRootWidget->findWidgetByName("edit", item))
	{
		item->addClickFunc([item](render::Node* node) {
			showWithTarget<PopMenu>(item, sys::CSSDirection::Bottom);
		});
	}
}

void ue::MenuBar::initEvent()
{
}

void ue::MenuBar::initText()
{
}
