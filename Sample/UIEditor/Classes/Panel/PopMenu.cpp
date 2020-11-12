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
	m_pLayout->findItemByName("body", _body);

	render::CtrlWidget* item = nullptr;
	if (m_pLayout->findWidgetByName("openFile", item))
	{
		item->addClickFunc([](render::Node* node) {
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
