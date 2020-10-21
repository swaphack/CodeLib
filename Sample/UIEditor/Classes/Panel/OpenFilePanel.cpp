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
	auto item = m_pLayout->findItemByName("body");
	if (item->getWidget() != nullptr)
	{
		_body = item->as<ui::Layout>();
	}
}

void ue::OpenFilePanel::initEvent()
{
}

void ue::OpenFilePanel::initText()
{
}
