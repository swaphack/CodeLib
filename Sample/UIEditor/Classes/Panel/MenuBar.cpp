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
	auto item = m_pLayout->findItemByName("file");
	if (item)
	{
		item->getWidget()->addClickFunc([item](render::Node* node) {
			PopMenu::show(item, sys::CSSDirection::Bottom);
		});
	}

	item = m_pLayout->findItemByName("edit");
	if (item)
	{
		item->getWidget()->addClickFunc([item](render::Node* node) {
			PopMenu::show(item, sys::CSSDirection::Bottom);
		});
	}
}

void ue::MenuBar::initEvent()
{
}

void ue::MenuBar::initText()
{
}
