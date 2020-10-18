#include "UIEditorApplication.h"
#include "Window/MainWindow.h"
#include "render.h"
#include "ui.h"
#include "Panel/import.h"

#define EDITOR_VIEW_LAYOUT "Default/Layout/main_view.xml"

using namespace render;

ue::UIEditorApplication::UIEditorApplication()
{
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_MENUBAR, new ui::TFileLoader<MenuBar>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_CONTROL, new ui::TFileLoader<ControlPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_DIRECTORY, new ui::TFileLoader<DirectoryPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_DESIGN, new ui::TFileLoader<DesignPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_PROPERTY, new ui::TFileLoader<PropertyPanel>());
	
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

