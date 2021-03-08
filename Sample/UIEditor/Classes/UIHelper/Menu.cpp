#include "Menu.h"
#include "File.h"
#include "Panel/PanelEvent.h"

ue::Menu::Menu()
{
}

ue::Menu::~Menu()
{
}

void ue::Menu::initUI()
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

void ue::Menu::initEvent()
{
}

void ue::Menu::initText()
{
}

const char* ue::Menu::getPanelPath()
{
	return "Default/Layout/ui_menu.xml";
}
