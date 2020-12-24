#include "PopMenu.h"
#include "OpenFilePanel.h"
#include "PanelEvent.h"

ue::PopMenu::PopMenu()
{
}

ue::PopMenu::~PopMenu()
{
}

void ue::PopMenu::initUI()
{
	if (m_pRootWidget->findWidgetByName("body", _body))
	{
		_body->addClickFunc([this](render::Node* node) {
			//OpenFilePanel* panel = showWithTarget<OpenFilePanel>();
			this->close();
		});
	}

	ui::CtrlWidget* item = nullptr;
	if (m_pRootWidget->findWidgetByName("openFile", item))
	{
		item->addClickFunc([this](render::Node* node) {
			//OpenFilePanel* panel = showWithTarget<OpenFilePanel>();
			this->close();
		});
	}

	if (m_pRootWidget->findWidgetByName("saveFile", item))
	{
		item->addClickFunc([this](render::Node* node) {
			G_PANELEVT->saveFile();
			this->close();
		});
	}

	if (m_pRootWidget->findWidgetByName("closeFile", item))
	{
		item->addClickFunc([this](render::Node* node) {
			this->close();
		});
	}

	if (m_pRootWidget->findWidgetByName("quitApp", item))
	{
		item->addClickFunc([this](render::Node* node) {
			this->close();
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
