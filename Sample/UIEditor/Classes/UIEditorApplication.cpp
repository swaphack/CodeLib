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
	getCanvas()->pushScene(pWindow);

	pWindow->setUIFile(_ideConfig.getIDE().Design);
	pWindow->setWidgetFile(_ideConfig.getIDE().Control);

	std::string filepath = _projectConfig.getRecent().getFile(0);
	G_PANELEVT->setSelectFile(filepath);
}

