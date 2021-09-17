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

	this->addOperateToDesignCamera();
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

	Camera* camera = G_CAMERAS->getRunningCamera3D();
	if (camera)
	{
		camera->addNotifyListener(NodeNotifyType::SPACE, [pCoordSystem, camera]() {
			math::Vector3 angle = camera->getWorldMatrix().getEularAngle();
			pCoordSystem->setRotation(angle);
		});
	}
}

void SystemEnv::updateCamera()
{
	auto size = Tool::getGLViewSize();
	{
		Camera* pCamera = G_CAMERAS->getDesignCamera();
		if (pCamera)
		{
			//pCamera->setVisible(false);
			auto size = Tool::getGLViewSize();
			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
			pCamera->setViewDistance(d - 200, d * 300);
			pCamera->setPositionZ(d);

			Utility::loadPrimitiveShader(pCamera->getDebugDraw()->getRenderNode());

			render::Sphere* pSphere = CREATE_NODE(render::Sphere);
			pSphere->setRadius(25);
			pSphere->setVolume(50, 50, 50);
			pSphere->setCamera(pCamera);
			pCamera->addChild(pSphere);

			Utility::loadDefaultShader(pSphere);

		}
	}
	{
		Camera* pCamera = G_CAMERAS->getCamera3D();
		if (pCamera)
		{
			auto size = Tool::getGLViewSize();
			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
			pCamera->setViewDistance(d - 200, d * 200);
			pCamera->setPositionZ(d);

			Utility::loadPrimitiveShader(pCamera->getDebugDraw()->getRenderNode());

			render::Sphere* pSphere = CREATE_NODE(render::Sphere);
			pSphere->setRadius(20);
			pSphere->setVolume(40, 40, 40);
			pSphere->setCamera(pCamera);
			pCamera->addChild(pSphere);

			Utility::loadDefaultShader(pSphere);
		}
		
	}
	{
		Camera* pCamera = G_CAMERAS->getCamera2D();
		if (pCamera)
		{
			pCamera->setPositionZ(size.getWidth() * 0.25f);
			Utility::loadPrimitiveShader(pCamera->getDebugDraw()->getRenderNode());

			render::Sphere* pSphere = CREATE_NODE(render::Sphere);
			pSphere->setRadius(15);
			pSphere->setVolume(30, 30, 30);
			pSphere->setCamera(pCamera);
			pCamera->addChild(pSphere);

			Utility::loadDefaultShader(pSphere);
		}
	}
}

void SystemEnv::addOperateToDesignCamera()
{
	Camera* pCamera = G_CAMERAS->getRunningCamera3D();
	if (pCamera == nullptr)
	{
		return;
	}

	G_KEYBOARDMANAGER->addKeyboardFunc(this, pCamera, [this](sys::BoardKey key, sys::ButtonStatus type) {
		Camera* pCamera = G_CAMERAS->getRunningCamera3D();

		if (type == sys::ButtonStatus::BUTTON_DOWN)
		{
			_spaceSpeed += 1.0f;
		}
		else
		{
			_spaceSpeed = 0.0f;
		}

		math::Tool::clamp(_spaceSpeed, 0.0f, 20.0f);

		if (key == sys::BoardKey::K1)
		{
			_viewType = 0;
			_mouseScroll = 1;
		}
		else if (key == sys::BoardKey::K2)
		{
			_viewType = 1;
			_mouseScroll = 1;
		}
		else if (key == sys::BoardKey::KA)
		{// 左边
			pCamera->setPosition(pCamera->getPosition() - _spaceSpeed * pCamera->getRight());
		}
		else if (key == sys::BoardKey::KD)
		{// 右边
			pCamera->setPosition(pCamera->getPosition() + _spaceSpeed * pCamera->getRight());
		}
		else if (key == sys::BoardKey::KW)
		{// 上面
			pCamera->setPosition(pCamera->getPosition() + _spaceSpeed * pCamera->getUp());
		}
		else if (key == sys::BoardKey::KS)
		{// 下面
			pCamera->setPosition(pCamera->getPosition() - _spaceSpeed * pCamera->getUp());
		}
		else if (key == sys::BoardKey::KQ)
		{// 前面
			pCamera->setPosition(pCamera->getPosition() + _spaceSpeed * pCamera->getFront());
		}
		else if (key == sys::BoardKey::KE)
		{// 后面
			pCamera->setPosition(pCamera->getPosition() - _spaceSpeed * pCamera->getFront());
		}
		else if (key == sys::BoardKey::KL)
		{
			pCamera->setRotationY(pCamera->getRotationY() - _spaceSpeed);
		}
		else if (key == sys::BoardKey::KJ)
		{
			pCamera->setRotationY(pCamera->getRotationY() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KK)
		{
			pCamera->setRotationX(pCamera->getRotationX() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KI)
		{
			pCamera->setRotationX(pCamera->getRotationX() - _spaceSpeed);
		}
		else if (key == sys::BoardKey::KU)
		{
			pCamera->setRotationZ(pCamera->getRotationZ() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KO)
		{
			pCamera->setRotationZ(pCamera->getRotationZ() - _spaceSpeed);
		}
		else if (key == sys::BoardKey::KSPACE)
		{
			auto size = Tool::getGLViewSize();
			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));

			pCamera->setRotation(math::Vector3());
			pCamera->setPosition(math::Vector3(0,0,d));
		}
	});


	G_MOUSEMANAGER->addMouseScrollFunc(this, pCamera, [this](sys::ScrollEvent evt, float param) {
		Camera* pCamera = G_CAMERAS->getRunningCamera3D();

		if (_scrollEvt != evt)
		{
			_mouseScroll = 1;
		}
		else
		{
			_mouseScroll *= 2.0f;
		}

		math::Tool::clamp(_mouseScroll, 0.0f, 32.0f);

		_scrollEvt = evt;

		float value = param * _mouseScroll;

		float zNear = pCamera->getViewParameter().zNear;
		float zFar = pCamera->getViewParameter().zFar;
		if (zFar + value <= zNear)
		{
			return;
		}
		if (_viewType == 0)
		{
			if (pCamera->getDimensions() == DimensionsType::THREE)
			{
				if (zNear + value <= 0)
				{
					return;
				}
			}
			pCamera->setViewDistance(zNear + value, zFar);
		}
		else
		{
			pCamera->setViewDistance(zNear, zFar + value);
		}
		});
}
