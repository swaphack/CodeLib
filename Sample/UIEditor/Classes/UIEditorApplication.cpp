#include "UIEditorApplication.h"
#include "Window/MainWindow.h"
#include "render.h"
#include "ui.h"
#include "Panel/import.h"

#define IDE_CONFIG_FILEPATH "Default/ide.xml"

#define PROJECT_CONFIG_FILEPATH "Resource/project.xml"

using namespace render;

ue::UIEditorApplication::UIEditorApplication()
{
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_MENUBAR, new ui::TFileLoader<MenuBar>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_CONTROL, new ui::TFileLoader<ControlPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_DIRECTORY, new ui::TFileLoader<DirectoryPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_DESIGN, new ui::TFileLoader<DesignPanel>());
	ui::UIProxy::getInstance()->registerElementParser(PANEL_NAME_PROPERTY, new ui::TFileLoader<PropertyPanel>());
	
	_ideConfig.loadXml(IDE_CONFIG_FILEPATH);

	_projectConfig.loadXml(PROJECT_CONFIG_FILEPATH);
}

ue::UIEditorApplication::~UIEditorApplication()
{
	
}

void ue::UIEditorApplication::show()
{
	DimensionsType eType = DimensionsType::TWO;
	Camera::getMainCamera()->setDimensions(eType);

	ui::UIProxy::setFontPath(_ideConfig.getText().FontPath);

	MainWindow* pWindow = CREATE_NODE(MainWindow);
	pWindow->setUIFile(_ideConfig.getIDE().Design);
	getCanvas()->pushScene(pWindow);

	std::string filepath = _projectConfig.getRecent().getFile(0);
	G_PANELEVT->dispatchEvent(PANEL_SELECT_DESIGN_FILE, (void*)filepath.c_str());
}

