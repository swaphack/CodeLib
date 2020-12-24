#include "OpenFilePanel.h"

ue::OpenFilePanel::OpenFilePanel()
{
}

ue::OpenFilePanel::~OpenFilePanel()
{
}

const char* ue::OpenFilePanel::getPanelPath()
{
	return "Default/Layout/open_file.xml";
}

void ue::OpenFilePanel::initUI()
{
	m_pRootWidget->findWidgetByName("body", _body);
}

void ue::OpenFilePanel::initEvent()
{
}

void ue::OpenFilePanel::initText()
{
}
