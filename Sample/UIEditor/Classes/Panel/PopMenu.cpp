#include "PopMenu.h"
#include "OpenFilePanel.h"

ue::PopMenu::PopMenu()
{
}

ue::PopMenu::~PopMenu()
{
}

void ue::PopMenu::initUI()
{
	auto item = m_pLayout->findItemByName("body");
	if (item->getWidget() != nullptr)
	{
		_body = item->as<ui::Layout>();
	}

	item = m_pLayout->findItemByName("openFile");
	if (item)
	{
		item->getWidget()->addClickFunc([](render::Node* node) {
			//OpenFilePanel* panel = showWithTarget<OpenFilePanel>();
		});
	}
}

void ue::PopMenu::initEvent()
{
}

void ue::PopMenu::initText()
{
}

const char* ue::PopMenu::getPanelPath()
{
	return "Default/Layout/pop_menu.xml";
}
