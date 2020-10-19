#include "Panel.h"
#include "PanelEvent.h"

ue::Panel::Panel()
{
}

ue::Panel::~Panel()
{
	G_PANELEVT->removeEventListener(this);
}

bool ue::Panel::init()
{
	if (!ui::CtrlFile::init())
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

bool ue::Panel::onTouchBegan(float x, float y, bool include)
{
	return true;
}

bool ue::Panel::onTouchMoved(float x, float y, bool include)
{
	return false;
}

bool ue::Panel::onTouchEnded(float x, float y, bool include)
{
	return false;
}

void ue::Panel::dispatchItem(ui::LayoutItem* item)
{
	G_PANELEVT->dispatchEvent(PANEL_SELECT_TARGET, item);
}

void ue::Panel::dispatchFile(ui::CtrlFile* layout)
{
	G_PANELEVT->dispatchEvent(PANEL_SELECT_FILE, layout);
}

void ue::Panel::dispatchXml(tinyxml2::XMLElement* doc)
{
	G_PANELEVT->dispatchEvent(PANEL_SELECT_XML, doc);
}

ui::LayoutItem* ue::Panel::createUIFile(const std::string& filepath)
{
	auto pFile = CREATE_NODE(ui::CtrlFile);
	pFile->setFilePath(filepath);

	sys::CSSSize size;
	size.setWidth(sys::NumberType::Percent, 1);
	size.setHeight(sys::NumberType::Percent, 1);

	auto layoutItem = CREATE_OBJECT(ui::LayoutItem);
	layoutItem->setSize(size);
	layoutItem->setWidget(pFile);

	return layoutItem;
}
