#include "TestEnvironmentNode.h"
#include "Utility.h"

using namespace render;
TestEnvironmentNode::TestEnvironmentNode()
{
}

TestEnvironmentNode::~TestEnvironmentNode()
{
}

void TestEnvironmentNode::initNodes()
{
	this->addGrid();

	this->testCamera();

	//this->init3DSkyBox();

	this->testMatrix();

	this->addCoordinate();
}

void TestEnvironmentNode::init3DSkyBox()
{
	render::SkyBox* pSkyBox = CREATE_NODE(render::SkyBox);
	pSkyBox->setLeftTexture("Resource/skybox/left.jpg");
	pSkyBox->setRightTexture("Resource/skybox/right.jpg");
	pSkyBox->setFrontTexture("Resource/skybox/front.jpg");
	pSkyBox->setBackTexture("Resource/skybox/back.jpg");
	pSkyBox->setTopTexture("Resource/skybox/top.jpg");
	pSkyBox->setBottomTexture("Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(0.25f);
	pSkyBox->setVolume(1024, 1024, 1024);
	pSkyBox->setPosition(0, 0, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShaderVF(pSkyBox, "Shader/env/skybox.vs", "Shader/env/skybox.fs");
	
	pSkyBox->setShaderProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("matrix.view");
		if (pUniform)
		{
			math::Matrix4x4 viewMat = Camera::getMainCamera()->getViewMatrix();
			math::Matrix4x4 mat = math::Matrix3x3(viewMat);
			pUniform->setMatrix4(mat);
		}
	});

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 180, 0);
	pRotateByAction->setDuration(20);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	//pSkyBox->getActionProxy()->runAction(pRepeateAction);

}

void TestEnvironmentNode::init2DSkyBox()
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

	pSkyBox->setShaderProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("matrix.view");
		if (pUniform)
		{
			math::Matrix4x4 viewMat = Camera::getMainCamera()->getViewMatrix();
			math::Matrix4x4 Mat = math::Matrix3x3(viewMat);
			pUniform->setMatrix4(Mat);
		}
	});

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pSkyBox->getActionProxy()->runAction(pRepeateAction);
}
void TestEnvironmentNode::testCamera()
{
	Camera* pCamera = Camera::getMainCamera();

	auto size = Tool::getGLViewSize();
	if (pCamera->getDimensions() == DimensionsType::THREE)
	{
		auto size = Tool::getGLViewSize();
		float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
		pCamera->setViewDistance(d - 200, d * 100);
		pCamera->setPosition(size.getWidth() * 0.5f, size.getHeight() * 0.5f, d);
	}
	else
	{
		pCamera->setPositionZ(size.getWidth() * 0.25f);
	}

	//pCamera->setPositionY(pCamera->getPositionY() + 100);
	//pCamera->setRotationX(pCamera->getRotationX() - 30);

	G_KEYBOARDMANAGER->addKeyboardFunc(this, pCamera, [&](Node* object, sys::BoardKey key, sys::ButtonStatus type) {
		auto camera = object->as<Camera>();
		if (camera == nullptr)
		{
			return;
		}

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
		{
			camera->setPosition(camera->getPosition() - _spaceSpeed * camera->getRight());
		}
		else if (key == sys::BoardKey::KD)
		{
			camera->setPosition(camera->getPosition() + _spaceSpeed * camera->getRight());
		}
		else if (key == sys::BoardKey::KW)
		{
			camera->setPosition(camera->getPosition() - _spaceSpeed * camera->getFront());
		}
		else if (key == sys::BoardKey::KS)
		{
			camera->setPosition(camera->getPosition() + _spaceSpeed * camera->getFront());
		}
		else if (key == sys::BoardKey::KQ)
		{
			camera->setPosition(camera->getPosition() - _spaceSpeed * camera->getUp());
		}
		else if (key == sys::BoardKey::KE)
		{
			camera->setPosition(camera->getPosition() + _spaceSpeed * camera->getUp());
		}
		else if (key == sys::BoardKey::KL)
		{
			camera->setRotationY(camera->getRotationY() - _spaceSpeed);
		}
		else if (key == sys::BoardKey::KJ)
		{
			camera->setRotationY(camera->getRotationY() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KK)
		{
			camera->setRotationX(camera->getRotationX() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KI)
		{
			camera->setRotationX(camera->getRotationX() - _spaceSpeed);
		}
	});

	
	G_MOUSEMANAGER->addMouseScrollFunc(this, pCamera, [&](Node* object, sys::ScrollEvent evt, float param) {
		auto camera = object->as<Camera>();
		if (camera == nullptr)
		{
			return;
		}

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

		float zNear = camera->getViewParameter().zNear;
		float zFar = camera->getViewParameter().zFar;
		if (zFar + value <= zNear)
		{
			return;
		}
		if (_viewType == 0)
		{
			if (camera->getDimensions() == DimensionsType::THREE)
			{
				if (zNear + value <= 0)
				{
					return;
				}
			}
			camera->setViewDistance(zNear + value, zFar);
		}
		else
		{
			camera->setViewDistance(zNear, zFar + value);
		}
	});
}

void TestEnvironmentNode::addGrid()
{
	render::Grid* pGrid = CREATE_NODE(render::Grid);
	pGrid->setAnchorPoint(0.5f, 0.5f, 0.5f);
	pGrid->setVolume(10240, 0, 10240);
	pGrid->setGridWidth(100);
	pGrid->setPosition(512, 384);
	//pGrid->setRotationX(90);

	Utility::loadShaderVGF(pGrid, "Shader/geometry/draw_line.vs", "Shader/geometry/draw_line.gs", "Shader/geometry/draw_line.fs");

	this->addChild(pGrid);

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(360, 0, 0);
	pRotateByAction->setDuration(5);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);
}

void TestEnvironmentNode::addCoordinate()
{
	render::Mask* pMask = CREATE_NODE(render::Mask);
	pMask->setColor(sys::Color4B(255, 255, 255, 255));
	pMask->setVolume(100, 100, -100);
	Utility::loadShaderVF(pMask, "Shader/geometry/draw_triangle.vs", "Shader/geometry/draw_triangle.fs");
	this->addChild(pMask);

	render::CoordinateSystem* pCoordSystem = CREATE_NODE(render::CoordinateSystem);
	pCoordSystem->setVolume(100, 100, 100);
	pCoordSystem->setPointSize(5);
	Utility::loadShaderVF(pCoordSystem, "Shader/geometry/draw_coordinate_system.vs","Shader/geometry/draw_coordinate_system.fs");
	this->addChild(pCoordSystem);
}

void TestEnvironmentNode::testMatrix()
{
	math::Vector3 rotate(0, 90, 0);

	math::Vector3 radian = Tool::convertToRadian(rotate);

	math::Matrix4x4 mat;
	mat.setRotate(radian);

	math::Vector3 up(0, 0, 1);

	math::Vector3 result = math::Matrix4x4::transpose(up, mat);

	int a = 1;
}

void TestEnvironmentNode::testMultiPort()
{
	math::Size size = Canvas::getInstance()->getView()->getViewSize();
	Canvas::getInstance()->setViewPort(0, 0, size.getWidth() * 0.5f, size.getHeight() * 0.5f);
}
