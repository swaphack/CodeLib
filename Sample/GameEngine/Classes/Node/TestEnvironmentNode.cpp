#include "TestEnvironmentNode.h"
#include "Utility.h"

using namespace render;
TestEnvironmentNode::TestEnvironmentNode()
{
}

TestEnvironmentNode::~TestEnvironmentNode()
{
}

void TestEnvironmentNode::testFunc()
{
	this->testCamera();

	this->init3DSkyBox();
}

void TestEnvironmentNode::init3DSkyBox()
{
	render::SkyBox* pSkyBox = CREATE_NODE(render::SkyBox);
	pSkyBox->setFaceImage(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceImage(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(0.25f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(0, 0, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShader(pSkyBox->getMaterials(), "Shader/skybox.vs", "Shader/skybox.fs");
	
	pSkyBox->setAllShaderProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("viewMatrix");
		if (pUniform)
		{
			math::Matrix44 viewMat = Camera::getMainCamera()->getViewMatrix();
			PRINT("%s\n", viewMat.toString().c_str());
			math::Matrix44 mat = math::Matrix33(viewMat);
			PRINT("%s\n", mat.toString().c_str());
			pUniform->setMatrix4(mat);
		}
	});

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(20);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	//pSkyBox->getActionProxy()->runAction(pRepeateAction);

}

void TestEnvironmentNode::init2DSkyBox()
{
	render::MultiFaceCube* pSkyBox = CREATE_NODE(render::MultiFaceCube);
	pSkyBox->setFaceImage(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceImage(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	pSkyBox->setScale(0.25f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(512, 384, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShader(pSkyBox->getMaterials(), "Shader/texture3d.vs", "Shader/texture3d.fs");

	pSkyBox->setAllShaderProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("viewMatrix");
		if (pUniform)
		{
			math::Matrix44 viewMat = Camera::getMainCamera()->getViewMatrix();
			math::Matrix44 Mat = math::Matrix33(viewMat);
			pUniform->setMatrix4(Mat);
		}
	});

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pSkyBox->getActionProxy()->runAction(pRepeateAction);
}
void TestEnvironmentNode::testCamera()
{
	Camera* pCamera = Camera::getMainCamera();
	if (pCamera->getDimensions() == CameraDimensions::TWO)
	{
		return;
	}

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pCamera->getActionProxy()->runAction(pRepeateAction);

	auto size = Tool::getGLViewSize();
	pCamera->setPosition(-size.getWidth() * 0.5f, -size.getHeight() * 0.5f);
	G_KEYBOARDMANAGER->addKeyboardFunc(this, pCamera, [this](Node* object, sys::BoardKey key, sys::ButtonStatus type) {
		auto camera = object->as<Camera>();
		if (camera == nullptr)
		{
			return;
		}

		if (key == sys::BoardKey::K1)
		{
			_viewType = 0;
		}
		else if (key == sys::BoardKey::K2)
		{
			_viewType = 1;
		}
		else if (key == sys::BoardKey::KA)
		{
			camera->setPositionX(camera->getPositionX() + 10);
		}
		else if (key == sys::BoardKey::KD)
		{
			camera->setPositionX(camera->getPositionX() - 10);
		}
		else if (key == sys::BoardKey::KQ)
		{
			camera->setPositionY(camera->getPositionY() - 10);
		}
		else if (key == sys::BoardKey::KE)
		{
			camera->setPositionY(camera->getPositionY() + 10);
		}
		else if (key == sys::BoardKey::KW)
		{
			camera->setPositionZ(camera->getPositionZ() + 10);
		}
		else if (key == sys::BoardKey::KS)
		{
			camera->setPositionZ(camera->getPositionZ() - 10);
		}
	});

	G_MOUSEMANAGER->addMouseScrollFunc(this, pCamera, [this](Node* object, sys::ScrollEvent evt, float param) {
		auto camera = object->as<Camera>();
		if (camera == nullptr)
		{
			return;
		}

		float value = param * 10;

		float zNear = camera->getViewParameter().zNear;
		float zFar = camera->getViewParameter().zFar;
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
