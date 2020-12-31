#include "MainWindow.h"
#include "UIDesign/import.h"

ue::MainWindow::MainWindow()
{
	_viewLayout = CREATE_NODE(UIDesignWindow);
	this->addChild(_viewLayout);

	auto proxy = ui::UIProxy::getInstance();

	proxy->registerElementParser(UI_DESIGN_MENUBAR, new ui::TFileLoader<UIDesignMenuBar>());
	proxy->registerElementParser(UI_DESIGN_WIDGET, new ui::TFileLoader<UIDesignWidget>());
	proxy->registerElementParser(UI_DESIGN_DIRECTORY, new ui::TFileLoader<UIDesignDirectory>());
	proxy->registerElementParser(UI_DESIGN_VIEW, new ui::TFileLoader<UIDesignView>());
	proxy->registerElementParser(UI_DESIGN_PROPERTY, new ui::TFileLoader<UIDesignProperty>());
	proxy->registerElementParser(UI_DESIGN_TREE, new ui::TFileLoader<UIDesignTree>());
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
