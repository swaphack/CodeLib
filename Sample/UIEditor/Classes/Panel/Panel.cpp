#include "Panel.h"
#include "PanelEvent.h"

ue::Panel::Panel()
{
}

ue::Panel::~Panel()
{
	G_KEYBOARDMANAGER->removeTargetAllEvents(this);
	G_PANELEVT->removeEventListener(this);
}

bool ue::Panel::init()
{
	if (!CtrlFile::init())
	{
		return false;
	}

	return true;
}

void ue::Panel::initUI()
{
}

void ue::Panel::initEvent()
{
}

void ue::Panel::initText()
{
}

ui::CtrlWidget* ue::Panel::createUIFile(const std::string& filepath)
{
	auto pFile = CREATE_NODE(ui::CtrlFile);
	if (pFile)
	{
		pFile->setFilePath(filepath);
	}

	return pFile;
}
