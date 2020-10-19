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
		item->getWidget()->addClickFunc([this](render::Node* node) {
			PopMenu::show();
		});
	}
}

void ue::MenuBar::initEvent()
{
}

void ue::MenuBar::initText()
{
}
