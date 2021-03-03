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
	proxy->registerElementParser(UI_DESIGN_NODE_TREE, new ui::TFileLoader<UIDesignNodeTree>());
	proxy->registerElementParser(UI_DESIGN_MASK, new ui::TFileLoader<UIDesignMask>());

	proxy->registerWidgetCreator(UI_DESIGN_WIDGET_CREATOR, [this](const std::string& name) { return this->createWidget(name); });
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

void ue::MainWindow::setWidgetFile(const std::string& config)
{
	_widgetConfig.loadXml(config);
}

ui::CtrlWidget* ue::MainWindow::createWidget(const std::string& widgetName)
{
	auto pSetting = _widgetConfig.getWidget(widgetName);
	if (pSetting == nullptr)
	{
		return nullptr;
	}

	auto pRoot = ui::UIProxy::getInstance()->loadFile(pSetting->ControlFilepath, this->getSize());
	if (pRoot == nullptr)
	{
		return nullptr;
	}

	return pRoot;
}
