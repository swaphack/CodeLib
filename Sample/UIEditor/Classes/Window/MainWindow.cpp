#include "MainWindow.h"
#include "UIDesign/import.h"

ue::MainWindow::MainWindow()
{
	_viewLayout = CREATE_NODE(UIDesignWindow);
	this->addChild(_viewLayout, 0);

	auto proxy = ui::UIProxy::getInstance();

	proxy->registerElementParser(UI_DESIGN_MENUBAR, []() { return new ui::TFileLoader<UIDesignMenuBar>(); });
	proxy->registerElementParser(UI_DESIGN_WIDGET, []() { return new ui::TFileLoader<UIDesignWidget>(); });
	proxy->registerElementParser(UI_DESIGN_DIRECTORY, []() { return new ui::TFileLoader<UIDesignDirectory>(); });
	proxy->registerElementParser(UI_DESIGN_VIEW, []() { return new ui::TFileLoader<UIDesignView>(); });
	proxy->registerElementParser(UI_DESIGN_PROPERTY, []() { return new ui::TFileLoader<UIDesignProperty>(); });
	proxy->registerElementParser(UI_DESIGN_NODE_TREE, []() { return new ui::TFileLoader<UIDesignNodeTree>(); });
	proxy->registerElementParser(UI_DESIGN_MASK, []() { return new ui::TFileLoader<UIDesignMask>(); });

	proxy->registerWidgetCreator(UI_DESIGN_WIDGET_CREATOR, [this](const std::string& name) { return this->createWidget(name); });
	proxy->registerWidgetPropertyCreator(UI_DESIGN_WIDGET_CREATOR, [this](const std::string& name) { return this->createWidgetProperty(name); });
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

	auto size = render::Tool::getViewSize();
	this->setAnchorPoint(math::Vector2(0, 0));
	//this->setPosition(math::Vector2(-0.5f * size.getWidth(), -0.5f * size.getHeight()));
	this->setVolume(size);

	updateCamera();

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

ui::CtrlWidget* ue::MainWindow::createWidgetProperty(const std::string& widgetName)
{
	auto pSetting = _widgetConfig.getWidget(widgetName);
	if (pSetting == nullptr)
	{
		return nullptr;
	}

	auto pRoot = ui::UIProxy::getInstance()->loadFile(pSetting->PropertyFilepath, this->getSize());
	if (pRoot == nullptr)
	{
		return nullptr;
	}

	return pRoot;
}

void ue::MainWindow::updateCamera()
{
	auto size = render::Tool::getViewSize();
	{
		render::Camera* pCamera = G_CAMERAS->getDesignCamera();
		if (pCamera)
		{
			pCamera->setVisible(false);
			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
			pCamera->setViewDistance(d - 300, d * 300);
			pCamera->setRotationX(15);
			pCamera->setPositionY(300);
			pCamera->setPositionZ(d);

		}
	}
	{
		render::Camera* pCamera = G_CAMERAS->getCamera3D();
		if (pCamera)
		{
			pCamera->setVisible(false);

			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
			pCamera->setViewDistance(d - 200, d * 200);
			pCamera->setPositionZ(d);
		}

	}
	{
		render::Camera* pCamera = G_CAMERAS->getCamera2D();
		if (pCamera)
		{
			pCamera->setVisible(true);
			pCamera->setPositionZ(0.0f);
		}
	}
}
