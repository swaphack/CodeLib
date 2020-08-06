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
	this->testCamera();

	//this->init3DSkyBox();
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

	Utility::loadShader(pSkyBox, "Shader/env/skybox.vs", "Shader/env/skybox.fs");
	
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

	Utility::loadShader(pSkyBox, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

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
	if (pCamera->getDimensions() == CameraDimensions::THREE)
	{
		auto size = Tool::getGLViewSize();
		float d = sqrt(powf(size.getWidth(), 2) + powf(size.getHeight(), 2));
		pCamera->setViewDistance(d - 200, d * 100);
		pCamera->setPosition(-size.getWidth() * 0.5f, -size.getHeight() * 0.5f, -d);
	}
	else
	{
		pCamera->setPositionZ(-size.getWidth() * 0.25f);
	}

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
			camera->setPositionX(camera->getPositionX() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KD)
		{
			camera->setPositionX(camera->getPositionX() - _spaceSpeed);
		}
		else if (key == sys::BoardKey::KQ)
		{
			camera->setPositionY(camera->getPositionY() - _spaceSpeed);
		}
		else if (key == sys::BoardKey::KE)
		{
			camera->setPositionY(camera->getPositionY() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KW)
		{
			camera->setPositionZ(camera->getPositionZ() + _spaceSpeed);
		}
		else if (key == sys::BoardKey::KS)
		{
			camera->setPositionZ(camera->getPositionZ() - _spaceSpeed);
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
			if (camera->getDimensions() == CameraDimensions::THREE)
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
