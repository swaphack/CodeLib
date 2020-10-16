#include "UIEditorApplication.h"
#include "Window/MainWindow.h"
#include "render.h"
#include "ui.h"
#include "Panel/import.h"

#define EDITOR_VIEW_LAYOUT "Resource/Layout/main_view.xml"

using namespace render;

ue::UIEditorApplication::UIEditorApplication()
{
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_WIDGETPANEL, new ui::TFileLoader<WidgetPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_DESIGNPANEL, new ui::TFileLoader<DesignPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_PROPERTYPANEL, new ui::TFileLoader<PropertyPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_MENUBAR, new ui::TFileLoader<MenuBar>());
}

ue::UIEditorApplication::~UIEditorApplication()
{
	
}

void ue::UIEditorApplication::show()
{
	DimensionsType eType = DimensionsType::TWO;
	Camera::getMainCamera()->setDimensions(eType);

	MainWindow* pWindow = CREATE_NODE(MainWindow);
	pWindow->setUIFile(EDITOR_VIEW_LAYOUT);
	getCanvas()->pushScene(pWindow);
}

