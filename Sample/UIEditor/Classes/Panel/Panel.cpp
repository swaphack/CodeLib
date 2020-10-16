#include "Panel.h"

ue::Panel::Panel()
{
}

ue::Panel::~Panel()
{
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
