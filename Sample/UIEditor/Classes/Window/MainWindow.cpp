#include "MainWindow.h"
#include "UIDesign/import.h"

ue::MainWindow::MainWindow()
{
	_viewLayout = CREATE_NODE(UIDesignWindow);
	this->addChild(_viewLayout);
}

ue::MainWindow::~MainWindow()
{

}

bool ue::MainWindow::init()
{
	if (!Scene::init())
	{
		return false;
	}

	return true;
}

void ue::MainWindow::setUIFile(const std::string& config)
{
	_viewLayout->autoResize();
	_viewLayout->setFilePath(config);
}
