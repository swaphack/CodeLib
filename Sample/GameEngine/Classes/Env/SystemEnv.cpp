#include "SystemEnv.h"
#include "ui.h"
#include "../Node/Utility.h"

using namespace render;

SystemEnv::SystemEnv()
{
}

SystemEnv::~SystemEnv()
{
}

void SystemEnv::initNodes()
{
	this->updateCamera();
	this->addFPS();
	this->addCoordinate();
}

void SystemEnv::addFPS()
{
	ui::CtrlText* pCtrlText = CREATE_NODE(ui::CtrlText);
	pCtrlText->setVolume(100, 50);
	pCtrlText->setDimensions(100, 50);
	pCtrlText->setFontPath("Resource/Font/font_3.ttf");
	pCtrlText->setFontSize(22);
	pCtrlText->setScale(1);
	pCtrlText->setPosition(0, 0, 0);
	pCtrlText->setAnchorPoint(0, 0, 0);
	pCtrlText->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
	pCtrlText->setTextVerticalAlignment(sys::VerticalAlignment::TOP);
	pCtrlText->setTextColor(phy::Color3B(255, 255, 255));
	Utility::loadDefaultShader(pCtrlText);
	this->addChild(pCtrlText);

	render::CallFuncN* pCallFunc = CREATE_ACTION(CallFuncN);
	pCallFunc->setFunc([](sys::Object* sender) {
		char strVal[255] = {};
		uint64_t diffTime = sys::TimeClock::getDifferenceOfRecordTime();
		int fps = 1000 / diffTime;
		sprintf(strVal, "FPS %d", fps);
		((ui::CtrlText*)sender)->setString(strVal);
	});

	render::DelayAction* pDelayAction = CREATE_ACTION(DelayAction);
	pDelayAction->setDuration(1);

	render::SequenceAction* pAction2 = render::CREATE_ACTION(render::SequenceAction);
	pAction2->addAction(pCallFunc);
	pAction2->addAction(pDelayAction);

	render::RepeateForeverAction* pRepeateForeverAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateForeverAction->setAction(pAction2);

	pCtrlText->getActionProxy()->runAction(pRepeateForeverAction);
}

void SystemEnv::addCoordinate()
{
	render::CoordinateSystem* pCoordSystem = CREATE_NODE(render::CoordinateSystem);
	pCoordSystem->setAnchorPoint(0.5f, 0.5f, 0.5f);
	pCoordSystem->setVolume(50, 50, 50);
	pCoordSystem->setPointSize(5);
	pCoordSystem->setPosition(100, 668, 0);
	pCoordSystem->setCamera(G_CAMERAS->getCamera2D());
	Utility::loadShaderVF(pCoordSystem, "Shader/geometry/draw_coordinate_system.vs", "Shader/geometry/draw_coordinate_system.fs");

	this->addChild(pCoordSystem);

	Camera* camera = G_CAMERAS->getCamera3D();
	camera->addNotifyListener(NodeNotifyType::SPACE, [pCoordSystem, camera]() {
		math::Vector3 angle = camera->getWorldMatrix().getEularAngle();
		pCoordSystem->setRotation(angle);
	});
}

void SystemEnv::updateCamera()
{
	auto size = Tool::getGLViewSize();
	{
		Camera* pCamera = G_CAMERAS->getCamera3D();
		auto size = Tool::getGLViewSize();
		float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
		pCamera->setViewDistance(d - 200, d * 200);
		pCamera->setPosition(0, 0, d);
	}
	{
		Camera* pCamera = G_CAMERAS->getCamera2D();
		pCamera->setPositionZ(size.getWidth() * 0.25f);
	}
}
