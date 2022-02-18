#include "MainWindow.h"
#include "UIDesign/import.h"
#include "ui.h"
#include "render.h"
ue::MainWindow::MainWindow()
{
	auto proxy = ui::UIProxy::getInstance();

	proxy->registerElementParser(UI_DESIGN_MENUBAR, new ui::TFileLoader<UIDesignMenuBar>());
	proxy->registerElementParser(UI_DESIGN_WIDGET, new ui::TFileLoader<UIDesignWidget>());
	proxy->registerElementParser(UI_DESIGN_DIRECTORY, new ui::TFileLoader<UIDesignDirectory>());
	proxy->registerElementParser(UI_DESIGN_DIR, new ui::TFileLoader<UIDesignDir>());
	proxy->registerElementParser(UI_DESIGN_VIEW, new ui::TFileLoader<UIDesignView>());
	proxy->registerElementParser(UI_DESIGN_PROPERTY, new ui::TFileLoader<UIDesignProperty>());
	proxy->registerElementParser(UI_DESIGN_NODE_TREE, new ui::TFileLoader<UIDesignNodeTree>());
	proxy->registerElementParser(UI_DESIGN_MASK, new ui::TFileLoader<UIDesignMask>());

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
	auto boxDraw = G_BOXSPACE->getBoxDraw();
	if (boxDraw)
	{
		ui::UIShaderHelper::loadColorShader(boxDraw->getRenderNode2d());
		ui::UIShaderHelper::loadColorShader(boxDraw->getRenderNode3d());

		boxDraw->setAllBoxesVisibled(true);
	}
	
	auto size = render::Tool::getViewSize();
	_viewLayout = CREATE_NODE(UIDesignWindow);
	_viewLayout->setRootView(true);
	_viewLayout->setAnchorPoint(0.5f, 0.5f);
	_viewLayout->setPosition(0,0);
	_viewLayout->setVolume(size);
	_viewLayout->getLayoutItem()->setMargin(0, 0, 0, 0);
	this->addChild(_viewLayout, 0);

	updateCamera();
	addFPS();

	return true;
}

void ue::MainWindow::setUIFile(const std::string& config)
{
	if (_viewLayout)
	{
		_viewLayout->autoResize();
		_viewLayout->setFilePath(config);
	}
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

			ui::UIShaderHelper::loadColorShader(pCamera->getDebugDraw()->getRenderNode());
			ui::UIShaderHelper::loadColorShader(pCamera->getShapeDraw()->getRenderNode());

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

			ui::UIShaderHelper::loadColorShader(pCamera->getDebugDraw()->getRenderNode());
			ui::UIShaderHelper::loadColorShader(pCamera->getShapeDraw()->getRenderNode());
		}

	}
	{
		render::Camera* pCamera = G_CAMERAS->getCamera2D();
		if (pCamera)
		{
			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));

			pCamera->getDebugDraw()->setVisible(false);
			pCamera->getShapeDraw()->setVisible(false);

			pCamera->setVisible(true);
			pCamera->setPositionZ(d);

			ui::UIShaderHelper::loadColorShader(pCamera->getDebugDraw()->getRenderNode());
			ui::UIShaderHelper::loadColorShader(pCamera->getShapeDraw()->getRenderNode());
		}
	}
}

void ue::MainWindow::addFPS()
{
	auto size = render::Tool::getViewSize();
	auto panel = CREATE_NODE(ui::CtrlFile);
	ui::UIShaderHelper::loadShader(panel);
	panel->setRootView(true);
	panel->setAnchorPoint(0.5f, 0.5f);
	panel->setPosition(0, 0);
	panel->setVolume(size);
	panel->getLayoutItem()->setMargin(0, 0, 0, 0);
	this->addChild(panel, 0);

	ui::CtrlText* pCtrlText = CREATE_NODE(ui::CtrlText);
	pCtrlText->setBoxVisible(true);
	pCtrlText->setVolume(200, 120);
	pCtrlText->setTextDimensions(200, 120);
	pCtrlText->setFontPath("Resource/Font/font_3.ttf");
	pCtrlText->setFontSize(22);
	pCtrlText->setScale(1);
	//pCtrlText->setPosition(-size.getWidth() * 0.5f, -size.getHeight() * 0.5f, 0);
	pCtrlText->setAnchorPoint(0, 0, 0);
	pCtrlText->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
	pCtrlText->setTextVerticalAlignment(sys::VerticalAlignment::BOTTOM);
	pCtrlText->setTextColor(phy::Color3B(255, 255, 255));
	pCtrlText->getLayoutItem()->unsetMarginState();
	pCtrlText->getLayoutItem()->setLeftMargin(5);
	pCtrlText->getLayoutItem()->setBottomMargin(5);

	ui::UIShaderHelper::loadShader(pCtrlText);
	panel->addWidget(pCtrlText, 1);

	render::CallFuncN* pCallFunc = CREATE_ACTION(render::CallFuncN);
	pCallFunc->setFunc([](sys::Object* sender) {
		uint64_t diffTime = sys::TimeClock::getDifferenceOfRecordTime();
		if (diffTime == 0) return;
		int fps = 1000 / diffTime;
		int drawCount = G_DRAWCORE->getDrawCallCount();
		int vertexCount = G_DRAWCORE->getVertexCount();
		std::string text = getCString("FPS %d\nDraw Call %d\nVertices %d", fps, drawCount, vertexCount);
		((ui::CtrlText*)sender)->setString(text);
	});

	render::DelayAction* pDelayAction = CREATE_ACTION(render::DelayAction);
	pDelayAction->setDuration(1);

	render::SequenceAction* pAction2 = CREATE_ACTION(render::SequenceAction);
	pAction2->addAction(pCallFunc);
	pAction2->addAction(pDelayAction);

	render::RepeateForeverAction* pRepeateForeverAction = CREATE_ACTION(render::RepeateForeverAction);
	pRepeateForeverAction->setAction(pAction2);

	pCtrlText->getActionProxy()->runAction(pRepeateForeverAction);
}
