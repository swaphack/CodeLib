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
