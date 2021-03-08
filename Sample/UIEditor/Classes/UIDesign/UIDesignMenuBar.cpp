#include "UIDesignMenuBar.h"
#include "UIHelper/Menu.h"

ue::UIDesignMenuBar::UIDesignMenuBar()
{
}

ue::UIDesignMenuBar::~UIDesignMenuBar()
{
}

void ue::UIDesignMenuBar::initUI()
{
	if (m_pRootWidget == nullptr) return;
	ui::CtrlWidget* item = nullptr;
	if (m_pRootWidget->findWidgetByName("file", item))
	{
		item->addClickFunc([item](render::Node* node) {
			Panel::showWithTarget<Menu>(item, sys::CSSDirection::Bottom);
		});
	}

	if (m_pRootWidget->findWidgetByName("edit", item))
	{
		item->addClickFunc([item](render::Node* node) {
			Panel::showWithTarget<Menu>(item, sys::CSSDirection::Bottom);
		});
	}
}

void ue::UIDesignMenuBar::initEvent()
{
}

void ue::UIDesignMenuBar::initText()
{
}
