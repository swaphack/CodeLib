#include "UIEditorApplication.h"
#include "Window/MainWindow.h"
#include "render.h"
#include "ui.h"
#include "Panel/import.h"
#include "UIDesign/import.h"

#define IDE_CONFIG_FILEPATH "Default/ide.xml"

#define PROJECT_CONFIG_FILEPATH "Resource/project.xml"

using namespace render;

ue::UIEditorApplication::UIEditorApplication()
{
	ui::UIProxy::getInstance()->registerElementParser(UI_DESIGN_MENUBAR, new ui::TFileLoader<UIDesignMenuBar>());
	ui::UIProxy::getInstance()->registerElementParser(UI_DESIGN_WIDGET, new ui::TFileLoader<UIDesignWidget>());
	ui::UIProxy::getInstance()->registerElementParser(UI_DESIGN_DIRECTORY, new ui::TFileLoader<UIDesignDirectory>());
	ui::UIProxy::getInstance()->registerElementParser(UI_DESIGN_VIEW, new ui::TFileLoader<UIDesignView>());
	ui::UIProxy::getInstance()->registerElementParser(UI_DESIGN_PROPERTY, new ui::TFileLoader<UIDesignProperty>());
	
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

	MainWindow* pWindow = CREATE_NODE(MainWindow);
	pWindow->setUIFile(_ideConfig.getIDE().Design);
	getCanvas()->pushScene(pWindow);

	std::string filepath = _projectConfig.getRecent().getFile(0);
	G_PANELEVT->setDesignFile(filepath);
}

