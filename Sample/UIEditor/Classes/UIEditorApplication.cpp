#include "UIEditorApplication.h"
#include "Window/MainWindow.h"
#include "render.h"
#include "ui.h"
#include "Panel/import.h"
#include "UIDesign/import.h"

const std::string IDE_CONFIG_FILEPATH = "Default/ide.xml";

const std::string PROJECT_CONFIG_FILEPATH = "Resource/project.xml";

using namespace render;

ue::UIEditorApplication::UIEditorApplication()
{	
}

ue::UIEditorApplication::~UIEditorApplication()
{
	
}

void ue::UIEditorApplication::show()
{
	MainWindow* pWindow = CREATE_NODE(MainWindow);
	getCanvas()->pushScene(pWindow);

	_ideConfig.loadXml(G_FILEPATH->getFilePath(IDE_CONFIG_FILEPATH));
	_projectConfig.loadXml(G_FILEPATH->getFilePath(PROJECT_CONFIG_FILEPATH));
	G_UIPROXY->setTexShader(_ideConfig.getShader().TexVertex, _ideConfig.getShader().TexFragment);
	G_UIPROXY->setColorShader(_ideConfig.getShader().ColorVertex, _ideConfig.getShader().ColorFragment);

	pWindow->setUIFile(_ideConfig.getIDE().Design);
	pWindow->setWidgetFile(_ideConfig.getIDE().Control);

	std::string filepath = _projectConfig.getRecent().getFile(0);
	G_PANELEVT->setSelectFile(filepath);
}

