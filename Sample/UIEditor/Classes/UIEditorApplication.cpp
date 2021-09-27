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
	_ideConfig.loadXml(G_FILEPATH->getFilePath(IDE_CONFIG_FILEPATH));
	_projectConfig.loadXml(G_FILEPATH->getFilePath(PROJECT_CONFIG_FILEPATH));
	ui::UIShaderHelper::setTexShader(_ideConfig.getShader().TexVertex, _ideConfig.getShader().TexFragment);
	ui::UIShaderHelper::setColorShader(_ideConfig.getShader().ColorVertex, _ideConfig.getShader().ColorFragment);

	MainWindow* pWindow = CREATE_NODE(MainWindow);
	getCanvas()->pushScene(pWindow);

	pWindow->setUIFile(_ideConfig.getIDE().Design);
	pWindow->setWidgetFile(_ideConfig.getIDE().Control);

	std::string filepath = _projectConfig.getRecent().getFile(0);
	G_PANELEVT->setSelectFile(filepath);
}

