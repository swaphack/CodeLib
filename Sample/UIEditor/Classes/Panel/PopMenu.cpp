#include "PopMenu.h"

ue::PopMenu* ue::PopMenu::sPopMenu = nullptr;

ue::PopMenu::PopMenu()
{
}

ue::PopMenu::~PopMenu()
{
}

void ue::PopMenu::initUI()
{
}

void ue::PopMenu::initEvent()
{
}

void ue::PopMenu::initText()
{
}

void ue::PopMenu::show()
{
	hide();
	sPopMenu = createPanel<PopMenu>("Default/Layout/main_view_pop_menu.xml");
	render::RenderApplication::getInstance()->getCanvas()->getCurScene()->addChild(sPopMenu);
}

void ue::PopMenu::hide()
{
	if (sPopMenu)
	{
		sPopMenu->removeFromParent();
		sPopMenu = nullptr;
	}
}

bool ue::PopMenu::isShow()
{
	return sPopMenu != nullptr;
}

ue::PopMenu* ue::PopMenu::getInstance()
{
	return sPopMenu;
}
