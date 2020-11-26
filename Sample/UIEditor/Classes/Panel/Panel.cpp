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

void ue::Panel::dispatchLayoutFile(ui::CtrlFile* layout)
{
	G_PANELEVT->dispatchEvent(PANEL_SELECT_LAYOUT, layout);
}

void ue::Panel::dispatchXml(tinyxml2::XMLElement* doc)
{
	G_PANELEVT->dispatchEvent(PANEL_SELECT_XML, doc);
}

void ue::Panel::dispatchDesignFile(const std::string& filepath)
{
	G_PANELEVT->dispatchEvent(PANEL_SELECT_DESIGN_FILE, (void*)filepath.c_str());
}

ui::LayoutItem* ue::Panel::createIteam()
{
	sys::CSSSize size;
	size.setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	size.setHeight(sys::NumberType::Percent, ONE_HUNDRED);
	auto layoutItem = CREATE_OBJECT(ui::LayoutItem);
	layoutItem->setSize(size);
	return layoutItem;
}

ui::LayoutItem* ue::Panel::createUIFile(const std::string& filepath)
{
	auto pItem = createIteam();
	if (pItem == nullptr)
	{
		return nullptr;
	}

	auto pFile = CREATE_NODE(ui::CtrlFile);
	if (pFile)
	{
		pFile->setFilePath(filepath);
		pItem->setWidget(pFile);
	}

	return pItem;
}
