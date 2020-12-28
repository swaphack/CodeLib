#include "FileSystemWindow.h"

ue::FileSystemWindow::FileSystemWindow()
{
}

ue::FileSystemWindow::~FileSystemWindow()
{
}

const char* ue::FileSystemWindow::getPanelPath()
{
	return "Default/Layout/open_file.xml";
}

void ue::FileSystemWindow::initUI()
{
	m_pRootWidget->findWidgetByName("body", _body);
}

void ue::FileSystemWindow::initEvent()
{
}

void ue::FileSystemWindow::initText()
{
}
