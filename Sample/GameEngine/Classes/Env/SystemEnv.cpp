#include "SystemEnv.h"
#include "ui.h"
#include "Utility.h"

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
	
	this->addGrid();
	
	this->init3DSkyBox();

	this->addOperateToDesignCamera();
}

void SystemEnv::addFPS()
{
	ui::CtrlText* pCtrlText = CREATE_NODE(ui::CtrlText);
	pCtrlText->setUseDesignCamera(false);
	pCtrlText->setVolume(100, 50);
	pCtrlText->setTextDimensions(100, 50);
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

	render::SequenceAction* pAction2 = CREATE_ACTION(render::SequenceAction);
	pAction2->addAction(pCallFunc);
	pAction2->addAction(pDelayAction);

	render::RepeateForeverAction* pRepeateForeverAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateForeverAction->setAction(pAction2);

	pCtrlText->getActionProxy()->runAction(pRepeateForeverAction);
}

void SystemEnv::addCoordinate()
{
	render::CoordinateSystem* pCoordSystem = CREATE_NODE(render::CoordinateSystem);
	pCoordSystem->setUseDesignCamera(false);
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
	auto size = Tool::getViewSize();
	{
		Camera* pCamera = G_CAMERAS->getDesignCamera();
		if (pCamera)
		{
			//pCamera->setVisible(false);

			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
			pCamera->setViewDistance(d - 300, d * 300);
			pCamera->setRotationX(15);
			pCamera->setPositionY(300);
			pCamera->setPositionZ(d);

			Utility::loadPrimitiveShader(pCamera->getDebugDraw()->getRenderNode());
			Utility::loadPrimitiveShader(pCamera->getShapeDraw()->getRenderNode());

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
			//pCamera->setVisible(false);

			float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
			pCamera->setViewDistance(d - 200, d * 200);
			pCamera->setPositionZ(d);

			Utility::loadPrimitiveShader(pCamera->getDebugDraw()->getRenderNode());
			Utility::loadPrimitiveShader(pCamera->getShapeDraw()->getRenderNode());

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
			//pCamera->setVisible(false);

			pCamera->setPositionZ(0);
			Utility::loadPrimitiveShader(pCamera->getDebugDraw()->getRenderNode());
			Utility::loadPrimitiveShader(pCamera->getShapeDraw()->getRenderNode());

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
			pCamera->setRotationY(pCamera->getRotationY() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KJ)
		{
			pCamera->setRotationY(pCamera->getRotationY() - _spaceSpeed);
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
			auto size = Tool::getViewSize();
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

void SystemEnv::init3DSkyBox()
{
	render::SkyBox* pSkyBox = CREATE_NODE(render::SkyBox);
	pSkyBox->setLeftTexture("Resource/skybox/left.jpg");
	pSkyBox->setRightTexture("Resource/skybox/right.jpg");
	pSkyBox->setFrontTexture("Resource/skybox/front.jpg");
	pSkyBox->setBackTexture("Resource/skybox/back.jpg");
	pSkyBox->setTopTexture("Resource/skybox/top.jpg");
	pSkyBox->setBottomTexture("Resource/skybox/bottom.jpg");

	pSkyBox->setScale(100.0f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(512, 384, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShaderVF(pSkyBox, "Shader/env/skybox.vs", "Shader/env/skybox.fs");
}

void SystemEnv::init2DSkyBox()
{
	render::MultiFaceCube* pSkyBox = CREATE_NODE(render::MultiFaceCube);
	pSkyBox->setFaceTexture(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceTexture(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceTexture(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceTexture(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceTexture(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceTexture(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	pSkyBox->setScale(0.25f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(512, 384, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShaderVF(pSkyBox, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	pSkyBox->setShaderProgramFunc([pSkyBox](ShaderProgram* program) {
		auto pUniform = program->getUniform("matrix.view");
		if (pUniform)
		{
			math::Matrix4x4 viewMat = pSkyBox->getCamera()->getViewMatrix();
			math::Matrix4x4 Mat = math::Matrix3x3(viewMat);
			pUniform->setMatrix4x4(Mat);
		}
		});

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pSkyBox->getActionProxy()->runAction(pRepeateAction);
}

void SystemEnv::addGrid()
{
	render::Grid* pGrid = CREATE_NODE(render::Grid);
	pGrid->setAnchorPoint(0.5f, 0.5f, 0.5f);
	pGrid->setVolume(10240, 0, 10240);
	pGrid->setGridWidth(100);
	pGrid->setPosition(512, 384);
	if (pGrid->getCamera()->getDimensions() == DimensionsType::TWO)
	{
		pGrid->setRotationX(90);
	}

	Utility::loadShaderVGF(pGrid, "Shader/geometry/draw_line.vs", "Shader/geometry/draw_line.gs", "Shader/geometry/draw_line.fs");

	this->addChild(pGrid);
}
